// COREX: Pure-Verilator C++ testbench for C-program tests
//
// Drives the Verilator model directly (no cocotb / no VPI), loads the
// objcopy-generated .hex into the instruction memory, runs the core until
// the completion flag is written, and reports results plus raw simulation
// throughput.  Use this to measure pure-Verilator efficiency vs. cocotb.
//
// Build & run:
//   cd my_c_test/tb_verilator
//   make run TEST=binary_search
//
// Arguments (all optional):
//   --hex <file>         hex image to load (default: ../build/<TEST>/test.hex,
//                        relative to the tb_verilator/ directory)
//   --max-cycles <n>     timeout in cycles (default: 2000)
//   --iters <n>          repeat reset+run n times, report average throughput
//   --expect-idx1 <n>    expected result at dmem[0x1000]  (default 5)
//   --expect-idx2 <n>    expected result at dmem[0x1004]  (default -1)
//   --verbose            print per-iteration cycle counts
//
// Author: Ran Ji

#include "verilated.h"
#include "VCoreTop.h"
// Internal model headers (generated into the build dir) needed to reach the
// IMem / DMem arrays exposed by --public-flat-rw and /*verilator public*/.
#include "VCoreTop___024root.h"
#include "VCoreTop_CoreTop.h"
#include "VCoreTop_Ifu.h"
#include "VCoreTop_IMemTop.h"
#include "VCoreTop_IMem.h"
#ifdef HIER_DMEM
// Hierarchical-DMem mode: dmem.sv mem marked /*verilator public*/ so the
// design can be built without --public-flat-rw (better optimization).
#include "VCoreTop_DMemTop.h"
#include "VCoreTop_DMem.h"
#endif

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using Clock = std::chrono::steady_clock;

// ---------------------------------------------------------------------------
// Global model handles
// ---------------------------------------------------------------------------
static VerilatedContext* g_ctx  = nullptr;
static VCoreTop*         g_top  = nullptr;

static constexpr int IMEM_DEPTH = 4096;    // IMem SIZE_BYTES=16384 / 4
static constexpr int DMEM_DEPTH = 4096;    // DMem SIZE_BYTES=16384 / 4
static constexpr uint32_t NOP = 0x00000013;

// ---------------------------------------------------------------------------
// Memory access helpers (paths confirmed from generated headers)
//  - flat mode  (--public-flat-rw):  rootp->CoreTop->u_dmem__DOT__...
//  - hier mode  (dmem mem /*verilator public*/): rootp->CoreTop->u_dmem->dmem->mem
// ---------------------------------------------------------------------------
#ifdef HIER_DMEM
static inline uint32_t dmem_read(uint32_t byte_addr) {
    return g_top->rootp->CoreTop->u_dmem->dmem->mem[byte_addr >> 2];
}

static inline void dmem_write(uint32_t byte_addr, uint32_t val) {
    g_top->rootp->CoreTop->u_dmem->dmem->mem[byte_addr >> 2] = val;
}
#else
static inline uint32_t dmem_read(uint32_t byte_addr) {
    return g_top->rootp->CoreTop->u_dmem__DOT__dmem__DOT__mem[byte_addr >> 2];
}

static inline void dmem_write(uint32_t byte_addr, uint32_t val) {
    g_top->rootp->CoreTop->u_dmem__DOT__dmem__DOT__mem[byte_addr >> 2] = val;
}
#endif

static inline void imem_write(uint32_t word_addr, uint32_t val) {
    g_top->rootp->CoreTop->u_ifu->IMem->imem->mem[word_addr] = val;
}

// ---------------------------------------------------------------------------
// Hex loading (objcopy -O verilog: "@ADDR" sections + little-endian bytes)
// ---------------------------------------------------------------------------
struct HexImage {
    std::vector<uint8_t> bytes;   // byte[i] is the byte at byte address (base+i)
    uint32_t base = 0;
    size_t   count = 0;
};

static std::string trim(const std::string& s) {
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == std::string::npos) return "";
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}

static HexImage load_hex(const std::string& path) {
    HexImage img;
    std::ifstream fin(path);
    if (!fin.is_open()) {
        fprintf(stderr, "[tb] ERROR: cannot open hex file: %s\n", path.c_str());
        exit(1);
    }
    std::string line;
    while (std::getline(fin, line)) {
        line = trim(line);
        if (line.empty()) continue;
        if (line[0] == '/' || line[0] == '#') continue;
        if (line[0] == '@') {
            img.base = static_cast<uint32_t>(strtoul(line.c_str() + 1, nullptr, 16));
            continue;                       // assume single contiguous section
        }
        std::istringstream iss(line);
        std::string tok;
        while (iss >> tok) {
            img.bytes.push_back(static_cast<uint8_t>(strtoul(tok.c_str(), nullptr, 16)));
        }
    }
    img.count = img.bytes.size();
    return img;
}

static std::vector<uint32_t> pack_words(const HexImage& img) {
    std::vector<uint32_t> words((img.count + 3) / 4, 0);
    for (size_t i = 0; i < img.count; i++) {
        words[i >> 2] |= static_cast<uint32_t>(img.bytes[i]) << ((i & 3) * 8);
    }
    return words;
}

// ---------------------------------------------------------------------------
// Clock / reset driving
// ---------------------------------------------------------------------------
static inline void tick(bool clk_val) {
    g_top->clk = clk_val;
    g_ctx->timeInc(5);        // half clock period (ns); keeps $time sane in debug prints
    g_top->eval();
}

// Run one reset + execute sequence. Returns cycle count and results.
static void run_once(uint64_t max_cycles, uint64_t& out_cycles, bool& out_done) {
    // Clear previous run's results; DMem is not cleared by reset, so this must
    // be done explicitly before every iteration.
    dmem_write(0x2000, 0);
    dmem_write(0x1000, 0);
    dmem_write(0x1004, 0);

    // Deassert start, hold reset, clear completion/results area.
    g_top->rst = 1;
    g_top->start = 0;
    g_top->program_address = 0;
    tick(false);

    // Two reset cycles (matches cocotb ClockCycles(dut.clk, 2)).
    for (int i = 0; i < 2; i++) {
        tick(true);
        tick(false);
    }

    // Release reset and pulse start for one cycle.
    g_top->rst = 0;
    g_top->start = 1;
    tick(true);
    tick(false);
    g_top->start = 0;

    // Execute until the C program writes 1 to the completion flag at 0x2000.
    uint64_t cycle;
    bool done = false;
    for (cycle = 0; cycle < max_cycles; cycle++) {
        tick(true);
        if (dmem_read(0x2000) == 1) {
            done = true;
            break;
        }
        tick(false);
    }
    out_cycles = cycle;
    out_done = done;
}

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main(int argc, char** argv) {
    // Default is relative to the tb_verilator/ directory (the documented usage).
    std::string hex_path = "../build/binary_search/test.hex";
    uint64_t    max_cycles = 2000;
    uint64_t    iters      = 1;
    int32_t     expect1    = 5;
    int32_t     expect2    = -1;
    bool        verbose    = false;
    auto t_process_start = Clock::now();
    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];
        auto need_val = [&](const char* name) -> const char* {
            if (i + 1 >= argc) {
                fprintf(stderr, "[tb] ERROR: missing value for %s\n", name);
                exit(1);
            }
            return argv[++i];
        };
        if (a == "--hex")        hex_path   = need_val(a.c_str());
        else if (a == "--max-cycles") max_cycles = strtoull(need_val(a.c_str()), nullptr, 10);
        else if (a == "--iters") iters     = strtoull(need_val(a.c_str()), nullptr, 10);
        else if (a == "--expect-idx1") expect1 = static_cast<int32_t>(strtol(need_val(a.c_str()), nullptr, 10));
        else if (a == "--expect-idx2") expect2 = static_cast<int32_t>(strtol(need_val(a.c_str()), nullptr, 10));
        else if (a == "--verbose")  verbose = true;
        else {
            fprintf(stderr, "[tb] ERROR: unknown argument: %s\n", a.c_str());
            return 1;
        }
    }

    // ------------------------------------------------------------------
    // Model construction + instruction memory load
    // ------------------------------------------------------------------
    g_ctx = new VerilatedContext;
    g_top = new VCoreTop{g_ctx, "CoreTop"};

    printf("==============================================================\n");
    printf(" [tb] Pure-Verilator C++ testbench\n");
    printf(" [tb] hex        : %s\n", hex_path.c_str());
    printf("==============================================================\n");

    HexImage img = load_hex(hex_path);
    std::vector<uint32_t> words = pack_words(img);
    printf(" [tb] loaded %zu bytes (%zu words) from %s\n",
           img.count, words.size(), hex_path.c_str());

    for (int i = 0; i < IMEM_DEPTH; i++) {
        imem_write(i, i < static_cast<int>(words.size()) ? words[i] : NOP);
    }
    dmem_write(0x2000, 0);   // completion flag cleared

    auto t_init_done = Clock::now();
    double init_sec = std::chrono::duration<double>(t_init_done - t_process_start).count();

    // ------------------------------------------------------------------
    // Benchmark loop
    // ------------------------------------------------------------------
    uint64_t total_cycles = 0;
    double   total_sim_time   = 0.0;
    bool     all_pass     = true;

    for (uint64_t it = 0; it < iters; it++) {
        auto t0 = Clock::now();
        uint64_t cycles;
        bool done;
        run_once(max_cycles, cycles, done);
        auto t1 = Clock::now();

        double seconds = std::chrono::duration<double>(t1 - t0).count();
        total_cycles += cycles;
        total_sim_time += seconds;
        //total_time   += seconds;

        int32_t idx1 = static_cast<int32_t>(dmem_read(0x1000));
        int32_t idx2 = static_cast<int32_t>(dmem_read(0x1004));
        bool ok = done && (idx1 == expect1) && (idx2 == expect2);
        all_pass &= ok;

        if (verbose || iters == 1) {
            printf(" [tb] iter %2llu: cycles=%llu  idx1=%d (exp %d)  idx2=%d (exp %d)  %s\n",
                   (unsigned long long)it,
                   (unsigned long long)cycles,
                   idx1, expect1, idx2, expect2,
                   ok ? "PASS" : "FAIL");
        }
        if (!done) {
            printf(" [tb] WARNING: completion flag not set within %llu cycles (timeout)\n",
                   (unsigned long long)max_cycles);
        }
    }
    auto t_process_end = Clock::now();
    double total_wall_sec = std::chrono::duration<double>(t_process_end - t_process_start).count();

    // ------------------------------------------------------------------
    // Summary + efficiency report
    // ------------------------------------------------------------------
    // ------------------------------------------------------------------
    // 详细吞吐量报告 (修复 total_cycles 统计)
    // ------------------------------------------------------------------
    double avg_sim_sec     = total_sim_time / static_cast<double>(iters);
    double avg_cycles      = static_cast<double>(total_cycles) / static_cast<double>(iters);
    
    // Pure Sim：用平均周期除以平均纯仿真时间
    double pure_throughput = (avg_sim_sec > 0.0) ? avg_cycles / avg_sim_sec : 0.0;
    
    // Wall-Clock：必须用总周期数 (total_cycles) 除以总墙上时间 (total_wall_sec)
    double real_throughput = (total_wall_sec > 0.0) ? static_cast<double>(total_cycles) / total_wall_sec : 0.0;

    printf("--------------------------------------------------------------\n");
    printf(" [tb] RESULT             : %s\n", all_pass ? "PASS" : "FAIL");
    printf(" [tb] Setup/Init Overhead: %.6f s\n", init_sec);
    printf(" [tb] Total Process Wall Time: %.6f s\n", total_wall_sec);
    printf(" [tb] Pure Sim Throughput: %.1f cycles/s (%.3f ns/cycle)\n",
           pure_throughput, (pure_throughput > 0.0) ? 1e9 / pure_throughput : 0.0);
    printf(" [tb] Wall-Clock Throughput: %.1f cycles/s (%.3f ns/cycle)\n",
           real_throughput, (real_throughput > 0.0) ? 1e9 / real_throughput : 0.0);
    printf("--------------------------------------------------------------\n");

    g_top->final();

    // === 新增：如果编译时开启了 --coverage，把数据写盘 ===
#if VM_COVERAGE
    Verilated::threadContextp()->coveragep()->write("coverage.dat");
    printf(" [tb] Coverage data written to: coverage.dat\n");
#endif

    
    delete g_top;
    delete g_ctx;
    return all_pass ? 0 : 1;
}
