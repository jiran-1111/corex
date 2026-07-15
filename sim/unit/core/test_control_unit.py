# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ran Ji

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, FallingEdge, Timer

from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner

async def setup_dut(dut):
    """Initialize the ControlUnit DUT and start the clock generator."""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    dut.opcode.value = 0
    
    dut.rst.value = 1
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

@cocotb.test()
async def t_ctrl_R_type(dut):
    """Verify control signals for R-type instructions (e.g., ADD, SUB)."""
    await setup_dut(dut)

    # R_TYPE opcode (0x33)
    dut.opcode.value = 0b0110011
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.ALUOp.value == 0b000
    assert dut.operand_A.value == 0b00  # Select rs1
    assert dut.operand_B.value == 0     # Select rs2
    assert dut.extend_sel.value == 0        # Don't care for R-type, defaults to 0

@cocotb.test()
async def t_ctrl_I_type(dut):
    """Verify control signals for I-type arithmetic/logic instructions (e.g., ADDI, XORI)."""
    await setup_dut(dut)

    # I_TYPE opcode (0x13)
    dut.opcode.value = 0b0010011
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.ALUOp.value == 0b001
    assert dut.operand_A.value == 0b00  
    assert dut.operand_B.value == 1     
    assert dut.extend_sel.value == 0        

@cocotb.test()
async def t_ctrl_LUI(dut):
    """Verify control signals for U-type LUI instruction."""
    await setup_dut(dut)

    # LUI opcode (0x37)
    dut.opcode.value = 0b0110111
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.ALUOp.value == 0b110
    assert dut.operand_A.value == 0b11  
    assert dut.operand_B.value == 1     
    assert dut.extend_sel.value == 1       

@cocotb.test()
async def t_ctrl_AUIPC(dut):
    """Verify control signals for U-type AUIPC instruction."""
    await setup_dut(dut)

    # AUIPC opcode (0x17)
    dut.opcode.value = 0b0010111
    await Timer(1, unit="ns")

    assert dut.regWrite.value == 1
    assert dut.ALUOp.value == 0b110
    assert dut.operand_A.value == 0b01  
    assert dut.operand_B.value == 1     
    assert dut.extend_sel.value == 1        

@cocotb.test()
async def t_ctrl_unsupported_opcode(dut):
    """Verify that regWrite is safely deasserted on unsupported/illegal opcodes."""
    await setup_dut(dut)

    # Drive an unsupported opcode (e.g., JAL opcode 0x6F)
    dut.opcode.value = 0b1101111
    await Timer(1, unit="ns")

    # Critical safety check: write enable must be disabled
    assert dut.regWrite.value == 0


class TestControlUnit_SV:
    sources = [
        HDL_SV_DIR / "core" / "control_unit.sv"
    ] 
    hdl_top = "ControlUnit"
    
    def test_decode_control_unit(self):
        cases = [
            "t_ctrl_R_type",
            "t_ctrl_I_type",
            "t_ctrl_LUI",
            "t_ctrl_AUIPC",
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