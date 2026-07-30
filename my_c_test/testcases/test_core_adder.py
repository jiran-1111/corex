# COREX: Co-modeling RISC-V Example Core
# 
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
# 
# Author: Ran Ji

from pathlib import Path
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer

# 导入上一级目录中的通用辅助工具
import sys
sys.path.append(str(Path(__file__).parent.parent))
from cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner,collect_coverage

NOP = 0x00000013 # addi x0, x0, 0

def load_hex_file(filepath):
    """
    解析 objcopy -O verilog 生成的 hex 文件
    处理 @00000000 地址行以及小端序字节组合
    """
    raw_bytes = []
    
    with open(filepath, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("//") or line.startswith("@"):
                continue
            
            parts = line.split()
            for part in parts:
                raw_bytes.append(int(part, 16))
    
    words = []
    for i in range(0, len(raw_bytes), 4):
        if i + 3 < len(raw_bytes):
            b0 = raw_bytes[i]      # LSB
            b1 = raw_bytes[i+1]
            b2 = raw_bytes[i+2]
            b3 = raw_bytes[i+3]    # MSB
            word = (b3 << 24) | (b2 << 16) | (b1 << 8) | b0
            words.append(word)
            
    return words

def fill_mem(dut, words: list[int]):
    """通过层次化路径填充 IFU 内部 IMEM。"""
    imem_size = len(dut.u_ifu.IMem.imem.mem)
    for i in range(imem_size):
        dut.u_ifu.IMem.imem.mem[i].value = NOP

    for i, word in enumerate(words):
        dut.u_ifu.IMem.imem.mem[i].value = word
        
    dut._log.info(f"Successfully loaded {len(words)} instructions into IMem.")

def read_dmem(dut, index: int) -> int:
    """读取 DMem 内部指定字（Word）索引的数据。"""
    return int(dut.u_dmem.dmem.mem[index].value)

async def clock_tick(dut):
    await RisingEdge(dut.clk)
    await Timer(1, unit="step")

async def setup_dut(dut, start_pc: int = 0):
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

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
    await clock_tick(dut)

@cocotb.test()
async def t_core_c_add_test(dut):
    """运行 C 语言编译出的加法测试 test.hex 并验证结果"""
    # 动态获取对应的 build/adder/test.hex 路径
    TEST_DIR = Path(__file__).parent.parent
    hex_path = TEST_DIR / "build" / "adder" / "test.hex"
    
    words = load_hex_file(hex_path)

    fill_mem(dut, words)
    await setup_dut(dut, start_pc=0)

    for i in range(100):
        await RisingEdge(dut.clk)
        result = read_dmem(dut, index=0x100 // 4)
        if result == 8:
            dut._log.info("检测到正确结果 8，测试通过！")
            break
    else:
        assert False, f"Test timeout! Expected 8 at address 0x100, got {read_dmem(dut, index=0x100 // 4)}"

class TestCore_SV:
    """Test the minimal three-stage core."""

    runner: Runner
    hdl_top: str

    @classmethod
    def setup_class(cls):
        # 注意：脚本现在在 testcases/ 目录下，向上两级到达项目根目录
        COREX_ROOT = Path(__file__).parent.parent.parent
        hdl_dir = COREX_ROOT / "hdl_sv" / "core"
        sources = [
            hdl_dir / "control_unit.sv",
            hdl_dir / "ibus_if.sv",
            hdl_dir / "dbus_if.sv",
            hdl_dir / "imem.sv",
            hdl_dir / "dmem.sv",
            hdl_dir / "reg_file.sv",
            hdl_dir / "pipeline_reg.sv",
            hdl_dir / "decoder.sv",
            hdl_dir / "ALU.sv",
            hdl_dir / "execute.sv",
            hdl_dir / "ifu.sv",
            hdl_dir / "core.sv"
        ]
        cls.hdl_top = "CoreTop"
        cls.runner = setup_runner(
            sources=sources, 
            hdl_toplevel=cls.hdl_top,
            extra_args=["--coverage"]
        )

    def test_c_add(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=f"testcases.{Path(__file__).stem}",
            testcase="t_core_c_add_test"
        )
        collect_coverage("c_add")