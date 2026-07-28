# COREX: Co-modeling RISC-V Example Core
# 
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
# 
# Author: Ran Ji

from pathlib import Path
import sys
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer

# 导入通用辅助工具
sys.path.append(str(Path(__file__).parent.parent))
from cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner

NOP = 0x00000013  # addi x0, x0, 0

def load_hex_file(filepath):
    """解析 objcopy -O verilog 生成的 hex 文件"""
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

def read_dmem(dut, byte_addr: int) -> int:
    """按字节地址读取 DMem 内部对应字（Word）索引的数据。"""
    word_index = byte_addr // 4
    return int(dut.u_dmem.dmem.mem[word_index].value)

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

def calculate_expected_soft_mul(x=1234, y=5678):
    """计算 C 语言软乘法与位翻转测试的理论 Golden 结果"""
    product = (x * y) & 0xFFFFFFFF  # 7006652 (0x006AEBBC)

    bit_reversed = 0
    temp = product
    for _ in range(32):
        bit_reversed = ((bit_reversed << 1) | (temp & 1)) & 0xFFFFFFFF
        temp >>= 1

    checksum = (product ^ bit_reversed) & 0xFFFFFFFF
    return product, checksum

@cocotb.test()
async def t_core_c_soft_mul_bit_test(dut):
    """运行 RV32I 软乘法与位运算测试 soft_mul_bit/test.hex 并验证结果"""
    TEST_DIR = Path(__file__).parent.parent
    hex_path = TEST_DIR / "build" / "soft_mul_bit" / "test.hex"
    
    words = load_hex_file(hex_path)

    fill_mem(dut, words)
    await setup_dut(dut, start_pc=0)

    # 算好的 Golden 期待值: product = 7006652, checksum = 1024961980 (0x3D17CDBC)
    expected_product, expected_checksum = calculate_expected_soft_mul(1234, 5678)
    
    max_cycles = 5000  # 软件乘法循环次数较多，适当增加最大周期数
    done = False

    for cycle in range(max_cycles):
        await RisingEdge(dut.clk)
        
        # 轮询检查 0x2000 处的 Done 标志位
        if read_dmem(dut, byte_addr=0x2000) == 1:
            dut._log.info(f"检测到程序完成标志 (0x2000 = 1)，用时 {cycle} 周期！")
            done = True
            break

    assert done, "测试超时！未能在规定时间内监测到 0x2000 处的写 1 结束标志。"

    # 读取 MMIO 数据地址并校验
    actual_product = read_dmem(dut, byte_addr=0x1000)
    actual_checksum = read_dmem(dut, byte_addr=0x1004)

    dut._log.info(f"计算得出的 Product: {actual_product} (预期: {expected_product})")
    dut._log.info(f"计算得出的 Checksum: {actual_checksum} (预期: {expected_checksum})")

    assert actual_product == expected_product, f"Product 计算错误！预期 {expected_product}, 实际获取 {actual_product}"
    assert actual_checksum == expected_checksum, f"Checksum 计算错误！预期 {expected_checksum}, 实际获取 {actual_checksum}"
    
    dut._log.info("软乘法与位运算测试完全通过！")

class TestCore_SV:
    """Test the minimal three-stage core with soft_mul_bit program."""

    runner: Runner
    hdl_top: str

    @classmethod
    def setup_class(cls):
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
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    def test_c_soft_mul_bit(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=f"testcases.{Path(__file__).stem}",
            testcase="t_core_c_soft_mul_bit_test",
        )