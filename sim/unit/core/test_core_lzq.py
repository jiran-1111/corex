# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ziqing Lin


import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer

from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner


NOP = 0x0000_0013



async def clock_tick(dut):
    await RisingEdge(dut.clk)
    await Timer(1, unit="step")



async def setup_dut(dut, start_pc: int = 0):
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    # 1. 挂起复位
    dut.rst.value = 1

    dut.start.value = 0
    dut.program_address.value = start_pc

    await ClockCycles(dut.clk, 2)
    await Timer(1, unit="step")
    
    # 2. 解除复位并给一个单周期的 start 脉冲
    dut.rst.value = 0
  
    dut.start.value = 1  # 给出 start 脉冲
    
    await RisingEdge(dut.clk)
    await Timer(1, unit="step")
    

    dut.start.value = 0  # <---【关键修改】及时拉低 start，允许 PC 开始自增！
    
    await clock_tick(dut)


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


def b_type(imm: int, rs2: int, rs1: int, funct3: int, opcode: int = 0x63) -> int:
    imm &= 0x1FFF
    return (
        ((imm >> 12) & 0x1) << 31
        | ((imm >> 5) & 0x3F) << 25
        | (rs2 << 20)
        | (rs1 << 15)
        | (funct3 << 12)
        | ((imm >> 1) & 0xF) << 8
        | ((imm >> 11) & 0x1) << 7
        | opcode
    )


def s_type(imm: int, rs2: int, rs1: int, funct3: int, opcode: int = 0x23) -> int:
    imm &= 0xFFF
    return (
        ((imm >> 5) & 0x7F) << 25
        | (rs2 << 20)
        | (rs1 << 15)
        | (funct3 << 12)
        | (imm & 0x1F) << 7
        | opcode
    )


def j_type(imm: int, rd: int, opcode: int = 0x6F) -> int:
    imm &= 0x1F_FFFF
    return (
        ((imm >> 20) & 0x1) << 31
        | ((imm >> 1) & 0x3FF) << 21
        | ((imm >> 11) & 0x1) << 20
        | ((imm >> 12) & 0xFF) << 12
        | (rd << 7)
        | opcode
    )


def fill_mem(dut, words: list[int]):
    """通过层次化路径填充 IFU 内部 IMEM。"""
    # 填充 NOP 刷空前 64 个字
    for i in range(64):
        dut.u_ifu.IMem.imem.mem[i].value = NOP

    # 写入程序指令
    for i, word in enumerate(words):
        dut.u_ifu.IMem.imem.mem[i].value = word


def read_reg(dut, index: int) -> int:
    """从 Decoder 内部的寄存器堆读取寄存器值。"""
    return int(dut.u_decoder.u_regfile.regs[index].value)


def read_dmem(dut, index: int) -> int:
    """读取 DMem 内部指定字（Word）索引的数据。"""
    # 假设 DMemTop 内部的 Ram 存储器实例名为 u_dmem 或 mem
    return int(dut.u_dmem.dmem.mem[index].value)


async def run_cycles(dut, cycles: int):
    for _ in range(cycles):
        await clock_tick(dut)


@cocotb.test()
async def t_core_raw_stall_only(dut):
    """Test RAW stalls without any control-flow instructions."""
    program = [
        i_type(5, 0, 0, 1),  # 0x00: addi x1, x0, 5
        i_type(7, 1, 0, 2),  # 0x04: addi x2, x1, 7
        r_type(0, 2, 1, 0, 3),  # 0x08: add x3, x1, x2
        i_type(1, 3, 0, 4),  # 0x0c: addi x4, x3, 1
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 30)

    assert read_reg(dut, 1) == 5
    assert read_reg(dut, 2) == 12
    assert read_reg(dut, 3) == 17
    assert read_reg(dut, 4) == 18


@cocotb.test()
async def t_core_control_stall_only(dut):
    """Test control stalls without RAW hazards."""
    program = [
        b_type(8, 0, 0, 0),  # 0x00: beq x0, x0, 0x08
        i_type(99, 0, 0, 1),  # 0x04: skipped
        i_type(5, 0, 0, 2),  # 0x08: addi x2, x0, 5
        b_type(8, 0, 0, 1),  # 0x0c: bne x0, x0, 0x14 (not taken)
        i_type(6, 0, 0, 3),  # 0x10: addi x3, x0, 6
        j_type(8, 4),  # 0x14: jal x4, 0x1c
        i_type(88, 0, 0, 5),  # 0x18: skipped
        i_type(0x28, 0, 0, 7, opcode=0x67),  # 0x1c: jalr x7, 0x28(x0)
        i_type(77, 0, 0, 8),  # 0x20: skipped
        i_type(66, 0, 0, 9),  # 0x24: skipped
        i_type(10, 0, 0, 10),  # 0x28: addi x10, x0, 10
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 50)

    assert read_reg(dut, 1) == 0
    assert read_reg(dut, 2) == 5
    assert read_reg(dut, 3) == 6
    assert read_reg(dut, 4) == 0x18
    assert read_reg(dut, 5) == 0
    assert read_reg(dut, 7) == 0x20
    assert read_reg(dut, 8) == 0
    assert read_reg(dut, 9) == 0
    assert read_reg(dut, 10) == 10


@cocotb.test()
async def t_core_alu_stall_and_redirect(dut):
    """Run a small ALU-only program through the three-stage core."""
    program = [
        i_type(5, 0, 0, 1),  # 0x00: addi x1, x0, 5
        i_type(7, 1, 0, 2),  # 0x04: addi x2, x1, 7
        r_type(0, 2, 1, 0, 3),  # 0x08: add x3, x1, x2
        j_type(8, 4),  # 0x0c: jal x4, 0x14
        i_type(99, 0, 0, 5),  # 0x10: skipped
        b_type(8, 3, 3, 0),  # 0x14: beq x3, x3, 0x1c
        i_type(88, 0, 0, 6),  # 0x18: skipped
        i_type(2, 4, 0, 7),  # 0x1c: addi x7, x4, 2
        i_type(0x2C, 0, 0, 9),  # 0x20: addi x9, x0, 0x2c
        i_type(0, 9, 0, 10, opcode=0x67),  # 0x24: jalr x10, 0(x9)
        i_type(123, 0, 0, 11),  # 0x28: skipped
        i_type(1, 10, 0, 12),  # 0x2c: addi x12, x10, 1
        b_type(8, 1, 0, 0),  # 0x30: beq x0, x1, 0x38 (not taken)
        i_type(13, 0, 0, 13),  # 0x34: addi x13, x0, 13
        i_type(1, 13, 0, 14),  # 0x38: addi x14, x13, 1
    ]
    fill_mem(dut, program)

    await setup_dut(dut)

    await run_cycles(dut, 60)

    assert read_reg(dut, 1) == 5
    assert read_reg(dut, 2) == 12
    assert read_reg(dut, 3) == 17
    assert read_reg(dut, 4) == 0x10
    assert read_reg(dut, 5) == 0
    assert read_reg(dut, 6) == 0
    assert read_reg(dut, 7) == 0x12
    assert read_reg(dut, 9) == 0x2C
    assert read_reg(dut, 10) == 0x28
    assert read_reg(dut, 11) == 0
    assert read_reg(dut, 12) == 0x29
    assert read_reg(dut, 13) == 13
    assert read_reg(dut, 14) == 14


@cocotb.test()
async def t_core_load_store(dut):
    """Test load/store execution and load-use RAW stalls."""
    program = [
        i_type(16, 0, 0, 1),  # 0x00: addi x1, x0, 16
        i_type(0x12, 0, 0, 2),  # 0x04: addi x2, x0, 0x12
        s_type(0, 2, 1, 2),  # 0x08: sw x2, 0(x1)
        i_type(0, 1, 2, 3, opcode=0x03),  # 0x0c: lw x3, 0(x1)
        i_type(1, 3, 0, 4),  # 0x10: addi x4, x3, 1
        s_type(4, 4, 1, 2),  # 0x14: sw x4, 4(x1)
        i_type(4, 1, 2, 5, opcode=0x03),  # 0x18: lw x5, 4(x1)
        r_type(0, 5, 3, 0, 6),  # 0x1c: add x6, x3, x5
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    await run_cycles(dut, 60)

    assert read_reg(dut, 1) == 16
    assert read_reg(dut, 2) == 0x12
    assert read_reg(dut, 3) == 0x12
    assert read_reg(dut, 4) == 0x13
    assert read_reg(dut, 5) == 0x13
    assert read_reg(dut, 6) == 0x25
    assert read_dmem(dut, 4) == 0x12
    assert read_dmem(dut, 5) == 0x13



class TestCore_SV:
    """Test the minimal three-stage core."""

    runner: Runner
    hdl_top: str

    @classmethod
    def setup_class(cls):
        sources = [
            HDL_SV_DIR / "core" / "control_unit.sv",
            HDL_SV_DIR / "core" / "ibus_if.sv",
            HDL_SV_DIR / "core" / "dbus_if.sv",
            HDL_SV_DIR / "core" / "imem.sv",
            HDL_SV_DIR / "core" / "dmem.sv",
            HDL_SV_DIR / "core" / "reg_file.sv",
            HDL_SV_DIR / "core" / "pipeline_reg.sv",
            HDL_SV_DIR / "core" / "decoder.sv",
            HDL_SV_DIR / "core" / "ALU.sv",
            HDL_SV_DIR / "core" / "execute.sv",
            HDL_SV_DIR / "core" / "ifu.sv",
            HDL_SV_DIR / "core" / "core_new.sv",
        ]
        cls.hdl_top = "CoreTop"
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    def test_raw_stall(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_raw_stall_only",
        )
    
    def test_core_program(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_alu_stall_and_redirect",
        )

    

    def test_control_stall(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_control_stall_only",
        )

    def test_load_store(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_load_store",
        )

    def test_control_stall_jal_only(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_control_stall_jal_only",
        )
    