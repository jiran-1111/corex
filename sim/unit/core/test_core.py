# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ran Ji

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer

from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner

NOP = 0x0000_0013


# ==============================================================================
# 1. 异步辅助函数 (Clocking & Setup)
# ==============================================================================

async def clock_tick(dut):
    await RisingEdge(dut.clk)
    await Timer(1, unit="step")


async def setup_dut(dut):
    """Setup DUT with clock and reset."""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    dut.rst.value = 1
    dut.start.value = 0
    dut.stall.value = 0
    dut.program_address.value = 0
    await ClockCycles(dut.clk, 2)
    await Timer(1, unit="step")
    dut.rst.value = 0

    # 触发启动脉冲
    dut.start.value = 1
    await clock_tick(dut)
    dut.start.value = 0


# ==============================================================================
# 2. RISC-V 指令打包辅助函数 (Instruction Encoders)
# ==============================================================================

def i_type(imm: int, rs1: int, funct3: int, rd: int, opcode: int = 0x13) -> int:
    return ((imm & 0xFFF) << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode


def r_type(
    funct7: int,
    rs2: int,
    rs1: int,
    funct3: int,
    rd: int,
    opcode: int = 0x33,
) -> int:
    return (
        (funct7 << 25)
        | (rs2 << 20)
        | (rs1 << 15)
        | (funct3 << 12)
        | (rd << 7)
        | opcode
    )

def u_type(imm: int, rd: int, opcode: int) -> int:
    """U-type: imm[31:12] | rd | opcode"""
    # 提取 20 位立即数
    return ((imm & 0xFFFFF) << 12) | (rd << 7) | opcode
# ==============================================================================
# 3. 仿真环境交互辅助函数 (DUT Peek & Poke)
# ==============================================================================

def fill_mem(dut, words: list[int]):
    """填充指令存储器，剩余区域用 NOP 填充"""
    # 假设最大支持 64 条指令
    for i in range(64):
        dut.u_ifu.IMem.imem.mem[i].value = NOP

    for i, word in enumerate(words):
        dut.u_ifu.IMem.imem.mem[i].value = word


def read_reg(dut, index: int) -> int:
    """读取通用寄存器堆的值"""
    return int(dut.u_decoder.u_regfile.regs[index].value)


async def run_cycles(dut, cycles: int):
    for _ in range(cycles):
        await clock_tick(dut)


# ==============================================================================
# 4. Cocotb 测试用例 (Testcases)
# ==============================================================================

@cocotb.test()
async def test_corex_pipeline(dut):
    """验证 Corex 3级流水线顺序执行无冲突 ADDI 指令"""
    program = [
        i_type(5, 0, 0, 1),   # 0x00: addi x1, x0, 5
        i_type(10, 0, 0, 2),  # 0x04: addi x2, x0, 10
        i_type(15, 0, 0, 3),  # 0x08: addi x3, x0, 15
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 20)

    # 验证最终写回寄存器的结果
    assert read_reg(dut, 1) == 5
    assert read_reg(dut, 2) == 10
    assert read_reg(dut, 3) == 15


@cocotb.test()
async def test_regfile_bypass_hazard(dut):
    """验证寄存器堆内部的 Read-During-Write Bypass (RAW 冲突)"""
    program = [
        i_type(8, 0, 0, 1),  # 0x00: addi x1, x0, 8
        i_type(4, 1, 0, 2),  # 0x04: addi x2, x1, 4  (依赖 x1)
        i_type(2, 2, 0, 3),  # 0x08: addi x3, x2, 2  (依赖 x2)
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 25)

    assert read_reg(dut, 1) == 8
    assert read_reg(dut, 2) == 12
    assert read_reg(dut, 3) == 14


@cocotb.test()
async def test_arithmetic_stress(dut):
    """流水线混合算术指令压力测试 (包含 SUB 与负数立即数)"""
    program = [
        i_type(50, 0, 0, 1),               # 0x00: addi x1, x0, 50
        i_type(20, 0, 0, 2),               # 0x04: addi x2, x0, 20
        r_type(0x20, 2, 1, 0, 3),          # 0x08: sub  x3, x1, x2
        i_type(-10 & 0xFFF, 3, 0, 4),      # 0x0C: addi x4, x3, -10
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 30)

    assert read_reg(dut, 1) == 50
    assert read_reg(dut, 2) == 20
    assert read_reg(dut, 3) == 30
    assert read_reg(dut, 4) == 20

@cocotb.test()
async def test_raw_hazard_extreme(dut):
    """极限 RAW 冲突测试（包含 x0 写入忽略、相邻及隔代依赖）"""
    program = [
        i_type(10, 0, 0, 0),   # 0x00: addi x0, x0, 10  (写入 x0，应该被忽略)
        i_type(5, 0, 0, 1),    # 0x04: addi x1, x0, 5   (x1 = 5)
        r_type(0, 1, 0, 0, 2), # 0x08: add  x2, x0, x1  (x2 = x0 + x1 = 5, 距离1依赖 x1)
        i_type(15, 0, 0, 3),   # 0x0C: addi x3, x0, 15  (x3 = 15)
        r_type(0, 3, 2, 0, 4), # 0x10: add  x4, x2, x3  (x4 = x2 + x3 = 20, 距离1依赖 x3, 距离2依赖 x2)
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 35)

    assert read_reg(dut, 0) == 0   # x0 必须保持为 0
    assert read_reg(dut, 1) == 5
    assert read_reg(dut, 2) == 5
    assert read_reg(dut, 4) == 20

@cocotb.test()
async def test_dual_source_raw_hazard(dut):
    """验证双源寄存器同时发生 RAW 冲突（rs1 和 rs2 均未写回）"""
    program = [
        i_type(15, 0, 0, 5),   # 0x00: addi x5, x0, 15  (x5 = 15)
        i_type(30, 0, 0, 6),   # 0x04: addi x6, x0, 30  (x6 = 30)
        # 下面这条指令：
        # rs1 (x5) 依赖 2 周期前的指令 (距离 2)
        # rs2 (x6) 依赖 1 周期前的指令 (距离 1)
        r_type(0, 6, 5, 0, 7), # 0x08: add  x7, x5, x6  (x7 = 15 + 30 = 45)
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 25)

    assert read_reg(dut, 5) == 15
    assert read_reg(dut, 6) == 30
    assert read_reg(dut, 7) == 45

@cocotb.test()
async def test_u_type_instructions(dut):
    """验证 U 型指令 (LUI, AUIPC) 的功能以及相关的 RAW 冲突"""
    LUI_OP    = 0x37
    AUIPC_OP  = 0x17

    program = [
        # 1. 测试 LUI 基础功能
        u_type(0x12345, 1, LUI_OP),       # 0x00: lui x1, 0x12345 -> x1 = 0x12345000
        
        # 2. 测试 LUI -> I-type 的 RAW 冲突 (立即数拼接常态)
        i_type(0x678, 1, 0, 2),           # 0x04: addi x2, x1, 0x678 -> x2 = 0x12345678
        
        # 3. 测试 AUIPC 功能 (此时 PC = 0x08)
        u_type(0x10, 3, AUIPC_OP),        # 0x08: auipc x3, 0x10 -> x3 = 0x08 + (0x10 << 12) = 0x10008
        
        # 4. 测试 AUIPC -> I-type 的 RAW 冲突
        i_type(-8 & 0xFFF, 3, 0, 4),      # 0x0C: addi x4, x3, -8 -> x4 = 0x10008 - 8 = 0x10000
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 30)

    # 验证最终结果
    assert read_reg(dut, 1) == 0x12345000
    assert read_reg(dut, 2) == 0x12345678
    assert read_reg(dut, 3) == 0x10008
    assert read_reg(dut, 4) == 0x10000

@cocotb.test()
async def test_continuous_raw_chain(dut):
    """验证同一个寄存器连续累加的 RAW 极端依赖链"""
    program = [
        i_type(1, 0, 0, 1),    # 0x00: addi x1, x0, 1  (x1 = 1)
        r_type(0, 1, 1, 0, 1), # 0x04: add  x1, x1, x1  (x1 = 1 + 1 = 2,   距离 1 依赖)
        r_type(0, 1, 1, 0, 1), # 0x08: add  x1, x1, x1  (x1 = 2 + 2 = 4,   距离 1 依赖)
        r_type(0, 1, 1, 0, 1), # 0x0c: add  x1, x1, x1  (x1 = 4 + 4 = 8,   距离 1 依赖)
        r_type(0, 1, 1, 0, 1), # 0x10: add  x1, x1, x1  (x1 = 8 + 8 = 16,  距离 1 依赖)
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 35)

    assert read_reg(dut, 1) == 16

@cocotb.test()
async def test_lzq_raw_stall_only(dut):
    """融合林子青同学的 RAW 冲突用例 (无控制流指令)"""
    program = [
        i_type(5, 0, 0, 1),      # 0x00: addi x1, x0, 5
        i_type(7, 1, 0, 2),      # 0x04: addi x2, x1, 7
        r_type(0, 2, 1, 0, 3),   # 0x08: add x3, x1, x2
        i_type(1, 3, 0, 4),      # 0x0c: addi x4, x3, 1
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 30)

    assert read_reg(dut, 1) == 5
    assert read_reg(dut, 2) == 12
    assert read_reg(dut, 3) == 17
    assert read_reg(dut, 4) == 18

@cocotb.test()
async def test_u_type_extreme_hazards(dut):
    """
    极限界 U 型指令测试：
    1. 连续发射 LUI 和 AUIPC（无气泡连续发射）
    2. 双源同时发生 U 型指令 RAW 依赖（R-type 的 rs1 依赖 AUIPC，rs2 依赖 LUI）
    3. 写入 x0 的 U 型指令应该被安全忽略，不影响后续依赖
    """
    LUI_OP    = 0x37
    AUIPC_OP  = 0x17

    program = [
        # 0x00: lui x5, 0xABCDE -> x5 = 0xABCDE000
        u_type(0xABCDE, 5, LUI_OP),
        
        # 0x04: auipc x6, 0x20000 -> x6 = 0x04 + 0x20000000 = 0x20000004
        u_type(0x20000, 6, AUIPC_OP),
        
        # 0x08: lui x0, 0x55555 -> 写入 x0 必须被硬件忽略
        u_type(0x55555, 0, LUI_OP),
        
        # 0x0C: add x7, x6, x5 -> 双重前推/旁路！
        # rs1 = x6 (由 0x04 的 AUIPC 产生，距离 2 周期)
        # rs2 = x5 (由 0x00 的 LUI 产生，此时已写回或正处于写回边缘)
        # 预期：x7 = 0x20000004 + 0xABCDE000 = 0xCBDDE004
        r_type(0, 5, 6, 0, 7),
        
        # 0x10: addi x8, x0, 100 -> 验证 x0 依然为 0，不受 0x08 处 lui x0 的影响
        # 预期：x8 = 100
        i_type(100, 0, 0, 8),
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 35)

    # ================= 验证逻辑 =================
    assert read_reg(dut, 0) == 0, "Error: x0 寄存器被 U 型指令非法写入了！"
    assert read_reg(dut, 5) == 0xABCDE000, "Error: LUI x5 值错误"
    assert read_reg(dut, 6) == 0x20000004, f"Error: AUIPC x6 值错误 (PC 对应 0x04)"
    assert read_reg(dut, 7)
# ==============================================================================
# 5. 仿真运行控制类 (Pytest Runner Wrapper)
# ==============================================================================

class TestCorex_SV:
    sources: list = [
        HDL_SV_DIR / "core" / "ALU.sv",
        HDL_SV_DIR / "core" / "control_unit.sv",
        HDL_SV_DIR / "core" / "core.sv",
        HDL_SV_DIR / "core" / "decoder.sv",
        HDL_SV_DIR / "core" / "execute.sv",
        HDL_SV_DIR / "core" / "ibus_if.sv",
        HDL_SV_DIR / "core" / "ifu.sv",
        HDL_SV_DIR / "core" / "imem.sv",
        HDL_SV_DIR / "core" / "pipeline_reg.sv",
        HDL_SV_DIR / "core" / "reg_file.sv",
    ]
    hdl_top = "corex"
    

    def test_pipeline_flow(self):
        cases = [
            "test_corex_pipeline",
            "test_regfile_bypass_hazard",
            "test_arithmetic_stress",
            "test_raw_hazard_extreme",
            "test_dual_source_raw_hazard",
            "test_continuou",
            "test_lzq_raw_stall_only",
            "test_u_type_instructions",
            "test_u_type_extreme_hazards"

        ]
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
        )
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )