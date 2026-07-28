from pathlib import Path
import sys
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer

sys.path.append(str(Path(__file__).parent.parent))
from cocotb_utils import CLK_PERIOD_NS, Runner, setup_runner

NOP = 0x00000013

def load_hex_file(filepath):
    raw_bytes = []
    with open(filepath, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("//") or line.startswith("@"):
                continue
            for part in line.split():
                raw_bytes.append(int(part, 16))
    
    words = []
    for i in range(0, len(raw_bytes), 4):
        if i + 3 < len(raw_bytes):
            word = (raw_bytes[i+3] << 24) | (raw_bytes[i+2] << 16) | (raw_bytes[i+1] << 8) | raw_bytes[i]
            words.append(word)
    return words

def fill_mem(dut, words: list[int]):
    imem_size = len(dut.u_ifu.IMem.imem.mem)
    for i in range(imem_size):
        dut.u_ifu.IMem.imem.mem[i].value = NOP
    for i, word in enumerate(words):
        dut.u_ifu.IMem.imem.mem[i].value = word

def read_dmem(dut, byte_addr: int) -> int:
    word_index = byte_addr // 4
    return int(dut.u_dmem.dmem.mem[word_index].value)

async def setup_dut(dut, start_pc: int = 0):
    cocotb.start_soon(Clock(dut.clk, CLK_PERIOD_NS, unit="ns").start())
    dut.rst.value = 1
    dut.start.value = 0
    dut.program_address.value = start_pc
    await ClockCycles(dut.clk, 2)
    await Timer(1, unit="step")
    dut.rst.value = 0
    dut.start.value = 1
    await RisingEdge(dut.clk)
    await Timer(1, unit="step")
    dut.start.value = 0

@cocotb.test()
async def t_core_c_str_toggle_test(dut):
    """运行大小写转换测试"""
    TEST_DIR = Path(__file__).parent.parent
    hex_path = TEST_DIR / "build" / "str_toggle" / "test.hex"
    
    words = load_hex_file(hex_path)
    fill_mem(dut, words)
    await setup_dut(dut, start_pc=0)

    # "Hello RISC-V 2026!" 转换为大小写反转后为 "hELLO risc-v 2026!"
    expected_str = "hELLO risc-v 2026!"
    expected_checksum = sum(ord(c) for c in expected_str) # 预期值为 1331

    max_cycles = 5000
    done = False
    for cycle in range(max_cycles):
        await RisingEdge(dut.clk)
        if read_dmem(dut, byte_addr=0x2000) == 1:
            dut._log.info(f"检测到程序完成标志 (0x2000 = 1)，用时 {cycle} 周期！")
            done = True
            break

    assert done, "测试超时！"

    actual_checksum = read_dmem(dut, byte_addr=0x1004)
    dut._log.info(f"计算的 Checksum: {actual_checksum} (预期: {expected_checksum})")
    assert actual_checksum == expected_checksum, f"Checksum 验证失败！预期 {expected_checksum}, 实际 {actual_checksum}"

class TestCore_SV:
    runner: Runner
    hdl_top: str

    @classmethod
    def setup_class(cls):
        COREX_ROOT = Path(__file__).parent.parent.parent
        hdl_dir = COREX_ROOT / "hdl_sv" / "core"
        sources = [
            hdl_dir / "control_unit.sv", hdl_dir / "ibus_if.sv", hdl_dir / "dbus_if.sv",
            hdl_dir / "imem.sv", hdl_dir / "dmem.sv", hdl_dir / "reg_file.sv",
            hdl_dir / "pipeline_reg.sv", hdl_dir / "decoder.sv", hdl_dir / "ALU.sv",
            hdl_dir / "execute.sv", hdl_dir / "ifu.sv", hdl_dir / "core.sv"
        ]
        cls.hdl_top = "CoreTop"
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    def test_c_str_toggle(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=f"testcases.{Path(__file__).stem}",
            testcase="t_core_c_str_toggle_test",
        )