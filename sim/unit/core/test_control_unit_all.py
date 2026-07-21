# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ran Ji

import cocotb
from cocotb.triggers import Timer

from ..cocotb_utils import HDL_SV_DIR, setup_runner

async def setup_dut(dut):
    """Initialize DUT inputs to safe default states."""
    dut.clk.value = 0
    dut.rst.value = 0
    dut.opcode.value = 0
    await Timer(1, unit="ns")


@cocotb.test()
async def t_ctrl_R_type(dut):
    """Verify control signals for R-type instructions (e.g., ADD, SUB, SLT)."""
    await setup_dut(dut)

    dut.opcode.value = 0b0110011  # R_TYPE
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.ALUOp.value == 0b000
    assert dut.operand_A.value == 0b00
    assert dut.operand_B.value == 0
    assert dut.memWrite.value == 0
    assert dut.memRead.value == 0
    assert dut.branch_op.value == 0


@cocotb.test()
async def t_ctrl_I_type(dut):
    """Verify control signals for I-type arithmetic instructions (e.g., ADDI, XORI)."""
    await setup_dut(dut)

    dut.opcode.value = 0b0010011  # I_TYPE
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.ALUOp.value == 0b001
    assert dut.operand_A.value == 0b00
    assert dut.operand_B.value == 1
    assert dut.extend_sel.value == 0b000  # I-type extension
    assert dut.memWrite.value == 0


@cocotb.test()
async def t_ctrl_load_store(dut):
    """Verify control signals for LOAD and STORE instructions."""
    await setup_dut(dut)

    # Test LOAD
    dut.opcode.value = 0b0000011  # LOAD
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.memRead.value == 1
    assert dut.memtoReg.value == 1
    assert dut.memWrite.value == 0
    assert dut.operand_B.value == 1
    assert dut.extend_sel.value == 0b000  # I-type extension

    # Test STORE
    dut.opcode.value = 0b0100011  # STORE
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 0
    assert dut.memRead.value == 0
    assert dut.memWrite.value == 1
    assert dut.operand_B.value == 1
    assert dut.extend_sel.value == 0b001  # S-type extension


@cocotb.test()
async def t_ctrl_branch_jumps(dut):
    """Verify control signals for BRANCH, JAL, and JALR instructions."""
    await setup_dut(dut)

    # Test BRANCH (BEQ, BNE, etc.)
    dut.opcode.value = 0b1100011  # BRANCH
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 0
    assert dut.branch_op.value == 1
    assert dut.next_PC_sel.value == 0b01
    assert dut.extend_sel.value == 0b010  # B-type extension

    # Test JAL
    dut.opcode.value = 0b1101111  # JAL
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.operand_A.value == 0b10    # Select PC+4 for rd
    assert dut.next_PC_sel.value == 0b10
    assert dut.extend_sel.value == 0b100  # J-type extension

    # Test JALR
    dut.opcode.value = 0b1100111  # JALR
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.operand_A.value == 0b10    # Select PC+4 for rd
    assert dut.next_PC_sel.value == 0b11
    assert dut.extend_sel.value == 0b000  # I-type extension


@cocotb.test()
async def t_ctrl_LUI_AUIPC(dut):
    """Verify control signals for U-type LUI and AUIPC instructions."""
    await setup_dut(dut)

    # Test LUI
    dut.opcode.value = 0b0110111  # LUI
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.ALUOp.value == 0b110
    assert dut.operand_A.value == 0b11    # Select 0
    assert dut.operand_B.value == 1
    assert dut.extend_sel.value == 0b011  # U-type extension

    # Test AUIPC
    dut.opcode.value = 0b0010111  # AUIPC
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.ALUOp.value == 0b110
    assert dut.operand_A.value == 0b01    # Select PC
    assert dut.operand_B.value == 1
    assert dut.extend_sel.value == 0b011  # U-type extension


@cocotb.test()
async def t_ctrl_unsupported_opcode(dut):
    """Verify safety lock (regWrite & memWrite deasserted) on illegal opcodes."""
    await setup_dut(dut)

    dut.opcode.value = 0b0000000  # Illegal zero opcode
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 0
    assert dut.memWrite.value == 0
    assert dut.memRead.value == 0
    assert dut.branch_op.value == 0


class TestControlUnit_SV:
    """Testrunner configuration class for ControlUnit simulation."""
    sources = [
        HDL_SV_DIR / "core" / "control_unit.sv"
    ] 
    hdl_top = "ControlUnit"
    
    def test_decode_control_unit(self):
        cases = [
            "t_ctrl_R_type",
            "t_ctrl_I_type",
            "t_ctrl_load_store",
            "t_ctrl_branch_jumps",
            "t_ctrl_LUI_AUIPC",
            "t_ctrl_unsupported_opcode"
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