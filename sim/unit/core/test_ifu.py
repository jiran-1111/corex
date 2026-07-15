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

# Default configuration (32-bit DATA_WIDTH)
DEFAULT_WORD_BYTES = 4


async def setup_ifu_dut(dut, start_pc: int = 0x0000_0000):
    """Setup IFU DUT with clock, default signals, and reset."""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    # Initialize input signals to default state
    dut.rst.value = 1
    dut.start.value = 0
    dut.stall.value = 0
    dut.program_address.value = start_pc

    await ClockCycles(dut.clk, 1)
    dut.rst.value = 0
    await RisingEdge(dut.clk)


def fill_ifu_imem(dut, words: list[int], start: int = 0):
    """Fill the instantiated internal instruction memory directly via hierarchical path."""
    for i, word in enumerate(words):
        dut.IMem.imem.mem[start + i].value = word


def is_pc_correct(dut, expected_pc: int) -> bool:
    """Check if the current instruction PC matches the expected value safely."""
    return dut.inst_PC.value.to_unsigned() == expected_pc


@cocotb.test()
async def t_ifu_reset(dut):
    """Test IFU reset state and steady state at the moment of reset deassertion."""
    await setup_ifu_dut(dut, start_pc=0x1000)
    
    assert is_pc_correct(dut, 0x1000)
    assert dut.fetch.value == 0


async def t_ifu_normal_sequential(dut):
    """Test standard sequential instruction fetch (PC + 4) with PC & Instruction synchronization."""
    instructions = [
        0x00100093, 
        0x00200113,
        0x00300193, 
        0x00400213  
    ]
    fill_ifu_imem(dut, instructions, start=0)

    await setup_ifu_dut(dut, start_pc=0x0)
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    

    for i in range(4):
        await RisingEdge(dut.clk)

        await Timer(1, unit="ps")
        
        expected_pc = i * 4
        expected_inst = instructions[i]
        
        current_pc = dut.inst_PC.value.to_unsigned()
        current_inst = dut.instruction.value.to_unsigned()
        

        assert current_pc == expected_pc
        assert current_inst == expected_inst
        assert dut.fetch.value == 1

@cocotb.test()
async def t_ifu_stall_long_duration(dut):
    """Test long duration stall holding capability and successful resumption."""
    instructions = [0x11111111, 0x22222222, 0x33333333, 0x44444444]
    fill_ifu_imem(dut, instructions, start=0)

    await setup_ifu_dut(dut, start_pc=0x0)

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    await RisingEdge(dut.clk)
    
    # Assert stall on the falling edge
    await FallingEdge(dut.clk)
    dut.stall.value = 1
    await RisingEdge(dut.clk)
    
    locked_pc = dut.inst_PC.value.to_unsigned()
    
    # Hold stall for multiple cycles
    await ClockCycles(dut.clk, 10)
    assert is_pc_correct(dut, locked_pc)

    # Deassert stall signal
    await RisingEdge(dut.clk)
    dut.stall.value = 0
    await RisingEdge(dut.clk)
    
    # Delta delay to allow signals to propagate after the clock edge
    await Timer(1, unit="ps")
    
    expected_next_pc = locked_pc + 4
    assert is_pc_correct(dut, expected_next_pc)


@cocotb.test()
async def t_ifu_reset_during_run(dut):
    """Test unexpected synchronous/asynchronous reset assertion during running state."""
    instructions = [0xAAAA_AAAA, 0xBBBB_BBBB]
    fill_ifu_imem(dut, instructions, start=0)
    await setup_ifu_dut(dut, start_pc=0x0)

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    await ClockCycles(dut.clk, 2) 

    # Trigger reset during execution
    await FallingEdge(dut.clk)
    dut.rst.value = 1
    dut.program_address.value = 0x2000
    
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    
    assert is_pc_correct(dut, 0x2000)
      
    assert dut.fetch.value == 0


@cocotb.test()
async def t_ifu_multiple_starts(dut):
    """Test repeated start pulses given during runtime for PC redirection."""
    instructions = [0x10, 0x20, 0x30, 0x40]
    fill_ifu_imem(dut, instructions, start=0)
    await setup_ifu_dut(dut, start_pc=0x0)

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    await ClockCycles(dut.clk, 2) 

    # Re-direct address with another start pulse
    await FallingEdge(dut.clk)
    dut.program_address.value = 0x4
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
   
    await Timer(1, unit="ps")
    assert is_pc_correct(dut, 0x4)


class TestIfu_SV:

    sources = [
            HDL_SV_DIR / "core" / "ibus_if.sv",
            HDL_SV_DIR / "core" / "imem.sv",
            HDL_SV_DIR / "core" / "ifu.sv",
    ]
    hdl_top = "Ifu"
        
    def test_ifu_core(self):
        cases = [
            "t_ifu_reset",
            "t_ifu_normal_sequential",
            "t_ifu_stall_long_duration",
            "t_ifu_reset_during_run",
            "t_ifu_multiple_starts",
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
    
    def test_data_64b(self):
        """Verify hardware compatibility when expanded to a 64-bit data bus width."""
        parameters = {
            "DATA_WIDTH": 64,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            parameters=parameters,
        )
        cases = ["t_ifu_reset", "t_ifu_normal_sequential"]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )