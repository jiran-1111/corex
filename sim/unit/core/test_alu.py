# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ran Ji
# 
 

import cocotb
from cocotb.triggers import Timer
import random
from ..cocotb_utils import HDL_SV_DIR, Runner, setup_runner

async def setup_dut(dut):
    """Initialize DUT inputs to default states."""
    dut.ALU_Control.value = 0
    dut.operand_A.value = 0
    dut.operand_B.value = 0
    await Timer(1, unit="ns")

def to_unsigned(val, width):
    """Truncate integer to unsigned with specified bit-width."""
    return val & ((1 << width) - 1)

def to_signed(val, width):
    """Convert unsigned value to Python signed integer."""
    val = val & ((1 << width) - 1)
    if val >= (1 << (width - 1)):
        return val - (1 << width)
    return val
  
@cocotb.test()
async def t_alu_add_sub(dut):
    """Test Case: Arithmetic Operations (ADD, ADDI, SUB)"""
    await setup_dut(dut)
    width = int(dut.DATA_WIDTH.value)

    # 1. ADD / ADDI: 5 + 10 = 15
    dut.ALU_Control.value = 0b000_000
    dut.operand_A.value = 5
    dut.operand_B.value = 10
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 15

    # 2. SUB: 10 - 5 = 5
    dut.ALU_Control.value = 0b001_000
    dut.operand_A.value = 10
    dut.operand_B.value = 5
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 5

    # 3. Corner case: -1 + 1 = 0 (Overflow handling)
    dut.ALU_Control.value = 0b000_000
    dut.operand_A.value = to_unsigned(-1, width) # 32'hFFFF_FFFF
    dut.operand_B.value = 1
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0


@cocotb.test()
async def t_alu_logical(dut):
    """Test Case: Logical Operations (XOR, OR, AND)"""
    await setup_dut(dut)

    # XOR
    dut.ALU_Control.value = 0b000_100
    dut.operand_A.value = 0x12F0
    dut.operand_B.value = 0xF012
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == (0x12F0 ^ 0xF012)

    # OR
    dut.ALU_Control.value = 0b000_110
    dut.operand_A.value = 0xAAAA_5555
    dut.operand_B.value = 0x5555_AAAA
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0xFFFF_FFFF

    # AND
    dut.ALU_Control.value = 0b000_111
    dut.operand_A.value = 0xFFFF_0000
    dut.operand_B.value = 0x5555_5555
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x5555_0000


@cocotb.test()
async def t_alu_compare(dut):
    """Test Case: Comparison Operations (SLT, SLTU)"""
    await setup_dut(dut)
    width = int(dut.DATA_WIDTH.value)

    # 1. SLT (Signed): -5 < 2 -> 1
    dut.ALU_Control.value = 0b000_010
    dut.operand_A.value = to_unsigned(-5, width)
    dut.operand_B.value = 2
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 1

    # 2. SLTU (Unsigned): MAX_INT < 2 -> 0
    dut.ALU_Control.value = 0b000_011
    dut.operand_A.value = to_unsigned(-5, width)
    dut.operand_B.value = 2
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0


@cocotb.test()
async def t_alu_shifts(dut):
    """Test Case: Shift Operations (SLL, SRL, SRA)"""
    await setup_dut(dut)
    width = int(dut.DATA_WIDTH.value)

    # 1. SLL (Logical left shift)
    dut.ALU_Control.value = 0b000_001
    dut.operand_A.value = 1
    dut.operand_B.value = 4
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x10

    # 2. SRL (Logical right shift, zero-filled)
    dut.ALU_Control.value = 0b000_101
    dut.operand_A.value = 0xF000_0000
    dut.operand_B.value = 4
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x0F00_0000

    # 3. SRA (Arithmetic right shift, sign-filled)
    dut.ALU_Control.value = 0b001_101
    dut.operand_A.value = 0xF000_0000
    dut.operand_B.value = 4
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0xFF00_0000


@cocotb.test()
async def t_alu_random(dut):
    """Test Case: Random Stimulus and Golden Model Verification"""
    await setup_dut(dut)
    width = int(dut.DATA_WIDTH.value)

    opcodes = [
        0b000_000, 0b001_000, 0b000_100, 0b000_110,
        0b000_111, 0b000_010, 0b000_011, 0b000_001,
        0b000_101, 0b001_101
    ]

    for _ in range(200):
        ctrl = random.choice(opcodes)
        op_a = random.randint(0, (1 << width) - 1)
        op_b = random.randint(0, (1 << width) - 1)
        shamt = op_b & ((1 << (width.bit_length() - 1)) - 1)

        # Golden Model behavior reference
        if ctrl == 0b000_000:   res = op_a + op_b
        elif ctrl == 0b001_000: res = op_a - op_b
        elif ctrl == 0b000_100: res = op_a ^ op_b
        elif ctrl == 0b000_110: res = op_a | op_b
        elif ctrl == 0b000_111: res = op_a & op_b
        elif ctrl == 0b000_010: res = 1 if to_signed(op_a, width) < to_signed(op_b, width) else 0
        elif ctrl == 0b000_011: res = 1 if op_a < op_b else 0
        elif ctrl == 0b000_001: res = op_a << shamt
        elif ctrl == 0b000_101: res = op_a >> shamt
        elif ctrl == 0b001_101: res = to_signed(op_a, width) >> shamt
        else:                   res = 0

        # Drive DUT inputs
        dut.ALU_Control.value = ctrl
        dut.operand_A.value = op_a
        dut.operand_B.value = op_b
        await Timer(1, unit="ns")

        # Verify results against Golden Model
        expected = to_unsigned(res, width)
        assert dut.ALU_result.value == expected

class TestALU_SV:
    """Testrunner configuration class for ALU SystemVerilog simulation."""
    sources = [
        HDL_SV_DIR / "core" / "ALU.sv" 
    ]
    hdl_top = "ALU"

    def test_alu_normal(self):
        """Execute all targeted and random testcases."""
        cases = [
            "t_alu_add_sub",
            "t_alu_logical",
            "t_alu_compare",
            "t_alu_shifts",
            "t_alu_random"
        ]
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top
        )
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )