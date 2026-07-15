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
from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner

async def setup_dut(dut):
    """Initialize DUT inputs to default states."""
    dut.clk.value = 0
    dut.rst.value = 0
    dut.stall.value = 0
    dut.ALU_Operation.value = 0
    dut.funct7.value = 0
    dut.funct3.value = 0
    dut.ALU_ASrc.value = 0
    dut.ALU_BSrc.value = 0
    dut.PC.value = 0
    dut.regRead_1.value = 0
    dut.regRead_2.value = 0
    dut.extend.value = 0
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
async def t_execute_mux_A(dut):
    """Test Case: Verifying Operand A Multiplexer (regRead_1 vs PC vs PC+4)"""
    await setup_dut(dut)
    
    dut.ALU_Operation.value = 0b001  # I-Type (pass-through / ADDI behavior)
    dut.funct3.value = 0b000         # ADD
    dut.ALU_BSrc.value = 1           # Select 'extend'
    dut.extend.value = 0             # Add zero to pass operand_A directly to output
    
    dut.regRead_1.value = 0xAAAA_BBBB
    dut.PC.value = 0x1000_0000

    # 1. ALU_ASrc = 00 -> Select regRead_1
    dut.ALU_ASrc.value = 0b00
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0xAAAA_BBBB

    # 2. ALU_ASrc = 01 -> Select PC
    dut.ALU_ASrc.value = 0b01
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x1000_0000

    # 3. ALU_ASrc = 10 -> Select PC + 4
    dut.ALU_ASrc.value = 0b10
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x1000_0004


@cocotb.test()
async def t_execute_mux_B(dut):
    """Test Case: Verifying Operand B Multiplexer (regRead_2 vs Immediate Extend)"""
    await setup_dut(dut)
    
    dut.ALU_Operation.value = 0b001  # I-Type
    dut.funct3.value = 0b000         # ADD
    dut.ALU_ASrc.value = 0b00        # Select regRead_1
    dut.regRead_1.value = 0          # Add zero to pass operand_B directly to output
    
    dut.regRead_2.value = 0x5555_6666
    dut.extend.value = 0x1234_5678

    # 1. ALU_BSrc = 0 -> Select regRead_2
    dut.ALU_BSrc.value = 0
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x5555_6666

    # 2. ALU_BSrc = 1 -> Select extend (Immediate)
    dut.ALU_BSrc.value = 1
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x1234_5678


@cocotb.test()
async def t_execute_random_ops(dut):
    """Test Case: Integrated Random Operations and Mux Logic Routing"""
    await setup_dut(dut)
    data_width = int(dut.DATA_WIDTH.value)
    addr_width = int(dut.ADDR_WIDTH.value)

    # Valid computational combinations of (ALU_Operation, funct3, funct7)
    op_combinations = [
        # (ALU_Op, f3, f7, is_shift)
        (0b000, 0b000, 0b0000000, False),  # ADD (R-Type)
        (0b000, 0b000, 0b0100000, False),  # SUB (R-Type)
        (0b000, 0b100, 0b0000000, False),  # XOR (R-Type)
        (0b000, 0b110, 0b0000000, False),  # OR  (R-Type)
        (0b000, 0b111, 0b0000000, False),  # AND (R-Type)
        (0b001, 0b000, 0b0000000, False),  # ADDI (I-Type)
        (0b001, 0b100, 0b0000000, False),  # XORI (I-Type)
        (0b000, 0b001, 0b0000000, True),   # SLL (R-Type Shift)
        (0b001, 0b101, 0b0000000, True),   # SRLI (I-Type Shift)
        (0b001, 0b101, 0b0100000, True)    # SRAI (I-Type Shift)
    ]

    for _ in range(150):
        alu_op, f3, f7, is_shift = random.choice(op_combinations)
        
        # Randomize data inputs
        val_reg1 = random.randint(0, (1 << data_width) - 1)
        val_reg2 = random.randint(0, (1 << data_width) - 1)
        val_ext  = random.randint(0, (1 << data_width) - 1)
        val_pc   = random.randint(0, (1 << addr_width) - 4) & ~0x3 # Align PC to 4 bytes

        # Randomize control paths
        asrc = random.choice([0b00, 0b01, 0b10])
        bsrc = random.choice([0, 1])

        # Apply stimulus to inputs
        dut.ALU_Operation.value = alu_op
        dut.funct3.value = f3
        dut.funct7.value = f7
        dut.ALU_ASrc.value = asrc
        dut.ALU_BSrc.value = bsrc
        
        dut.regRead_1.value = val_reg1
        dut.regRead_2.value = val_reg2
        dut.extend.value = val_ext
        dut.PC.value = val_pc
        
        await Timer(1, unit="ns")

        # Determine expected operand values based on active Mux path
        expected_A = val_pc if asrc == 0b01 else (val_pc + 4 if asrc == 0b10 else val_reg1)
        expected_B = val_ext if bsrc == 1 else val_reg2

        # Extract shift amount if instruction is a shift op
        shamt_width = (data_width).bit_length() - 1
        shamt = expected_B & ((1 << shamt_width) - 1)

        # Execution Logic Golden Model
        if (alu_op, f7) == (0b000, 0b0000000) and f3 == 0b000:    # ADD
            expected_res = expected_A + expected_B
        elif (alu_op, f7) == (0b000, 0b0100000) and f3 == 0b000:  # SUB
            expected_res = expected_A - expected_B
        elif f3 == 0b100:                                         # XOR / XORI
            expected_res = expected_A ^ expected_B
        elif f3 == 0b110:                                         # OR / ORI
            expected_res = expected_A | expected_B
        elif f3 == 0b111:                                         # AND / ANDI
            expected_res = expected_A & expected_B
        elif f3 == 0b001:                                         # SLL / SLLI
            expected_res = expected_A << shamt
        elif (alu_op, f3, f7) == (0b001, 0b101, 0b0000000) or (alu_op, f3, f7) == (0b000, 0b101, 0b0000000): # SRL / SRLI
            expected_res = expected_A >> shamt
        elif (alu_op, f3, f7) == (0b001, 0b101, 0b0100000) or (alu_op, f3, f7) == (0b000, 0b101, 0b0100000): # SRA / SRAI
            expected_res = to_signed(expected_A, data_width) >> shamt
        else:
            expected_res = expected_A + expected_B # Default ADD behavior

        expected_res = to_unsigned(expected_res, data_width)
        
        # Verify result
        assert dut.ALU_result.value == expected_res, \
            f"Failed: OP={alu_op:b} F3={f3:b} A={expected_A:x} B={expected_B:x} Got={int(dut.ALU_result.value):x} Exp={expected_res:x}"


class TestExecute_SV:
    """Testrunner configuration class for Execution Unit SystemVerilog simulation."""
    sources = [
        HDL_SV_DIR / "core" / "ALU.sv",
        HDL_SV_DIR / "core" / "execute.sv"
    ]
    hdl_top = "execute"

    def test_execute_normal(self):
        """Execute all target unit tests and randomized test suites."""
        cases = [
            "t_execute_mux_A",
            "t_execute_mux_B",
            "t_execute_random_ops"
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