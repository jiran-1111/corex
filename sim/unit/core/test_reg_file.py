# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ziqing Lin

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge

from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner


async def setup_dut(dut):
    """Setup DUT with clock, reset, and stable input defaults."""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    dut.rst.value = 1
    dut.wen.value = 0
    dut.waddr.value = 0
    dut.wdata.value = 0
    dut.raddr1.value = 0
    dut.raddr2.value = 0
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)


def drive_write(dut, addr: int, data: int, *, wen: int = 1):
    dut.wen.value = wen
    dut.waddr.value = addr
    dut.wdata.value = data


def drive_read(dut, addr1: int, addr2: int):
    dut.raddr1.value = addr1
    dut.raddr2.value = addr2


def is_read_correct(dut, expected1: int, expected2: int) -> bool:
    return dut.rdata1.value == expected1 and dut.rdata2.value == expected2


@cocotb.test()
async def t_reset_sync(dut):
    """Test synchronous reset clears registers."""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    dut.rst.value = 1
    dut.wen.value = 0
    dut.waddr.value = 0
    dut.wdata.value = 0
    drive_read(dut, 0, 0)
    await ClockCycles(dut.clk, 2)
    assert is_read_correct(dut, 0, 0)

    dut.rst.value = 0
    await RisingEdge(dut.clk)

    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)


@cocotb.test()
async def t_reset_after_write(dut):
    """Test reset clears written registers."""
    await setup_dut(dut)

    drive_read(dut, 1, 2)
    drive_write(dut, 1, 0x1001)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    drive_write(dut, 2, 0x2002)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x1001, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x1001, 0x2002)

    dut.rst.value = 1
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x1001, 0x2002)

    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)


@cocotb.test()
async def t_reset_and_write(dut):
    """Test writes are ignored while reset is asserted."""
    await setup_dut(dut)

    drive_read(dut, 1, 0)
    dut.rst.value = 1
    drive_write(dut, 1, 0x1001)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    dut.rst.value = 0
    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)


@cocotb.test()
async def t_write_and_read(dut):
    """Test normal writes and the two combinational read ports."""
    await setup_dut(dut)

    drive_read(dut, 1, 2)
    drive_write(dut, 1, 0x1101)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    drive_write(dut, 2, 0x2202)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x1101, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x1101, 0x2202)


@cocotb.test()
async def t_write_disabled(dut):
    """Test wen=0 prevents register updates."""
    await setup_dut(dut)

    drive_read(dut, 3, 3)
    drive_write(dut, 3, 0x3303)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x3303, 0x3303)

    drive_write(dut, 3, 0x4404, wen=0)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x3303, 0x3303)

    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x3303, 0x3303)


@cocotb.test()
async def t_write_burst(dut):
    """Test back-to-back writes."""
    await setup_dut(dut)

    drive_read(dut, 4, 5)
    drive_write(dut, 4, 0x4404)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    drive_write(dut, 5, 0x5505)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x4404, 0)

    drive_write(dut, 6, 0x6606)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x4404, 0x5505)

    dut.wen.value = 0
    drive_read(dut, 6, 0)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x6606, 0)


@cocotb.test()
async def t_write_x0(dut):
    """Test x0 ignores writes and always reads as zero."""
    await setup_dut(dut)

    drive_read(dut, 0, 0)
    drive_write(dut, 0, 0x0001)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)


@cocotb.test()
async def t_no_zero_x0(dut):
    """Test x0 is writable when ZERO_X0 is disabled."""
    await setup_dut(dut)

    drive_read(dut, 0, 0)
    drive_write(dut, 0, 0x00A5_5A00)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x00A5_5A00, 0x00A5_5A00)


@cocotb.test()
async def t_read_during_write(dut):
    """Test reads return stored data until the write clock edge."""
    await setup_dut(dut)

    drive_read(dut, 7, 0)
    drive_write(dut, 7, 0x7001)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x7001, 0)

    drive_write(dut, 7, 0x7002)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x7001, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x7002, 0)

    drive_read(dut, 7, 8)
    drive_write(dut, 8, 0x8001)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x7002, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x7002, 0x8001)


class TestRegFile_SV:
    """Test the register file with default configuration."""

    runner: Runner
    hdl_top: str

    @classmethod
    def setup_class(cls):
        sources = [
            HDL_SV_DIR / "core" / "reg_file.sv",
        ]
        cls.hdl_top = "RegFile"
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    def test_reset(self):
        cases = [
            "t_reset_sync",
            "t_reset_after_write",
            "t_reset_and_write",
        ]
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

    def test_write_read(self):
        cases = [
            "t_write_and_read",
            "t_write_disabled",
            "t_write_burst",
            "t_write_x0",
        ]
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

    def test_read_during_write(self):
        cases = [
            "t_read_during_write",
        ]
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )


@cocotb.test()
async def t_data_width_64b(dut):
    """Test 64-bit REG_DATA_WIDTH parameter."""
    await setup_dut(dut)

    drive_read(dut, 1, 0)
    drive_write(dut, 1, 0x1234_5678_9ABC_DEF0)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x1234_5678_9ABC_DEF0, 0)


@cocotb.test()
async def t_sel_width_4b(dut):
    """Test 4-bit REG_SEL_WIDTH parameter."""
    await setup_dut(dut)

    drive_read(dut, 15, 0)
    drive_write(dut, 15, 0x150F)
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0, 0)

    dut.wen.value = 0
    await RisingEdge(dut.clk)
    assert is_read_correct(dut, 0x150F, 0)


class TestRegFileParam_SV:
    """Test the register file parameters."""

    sources = [
        HDL_SV_DIR / "core" / "reg_file.sv",
    ]
    hdl_top = "RegFile"

    def test_data_width(self):
        parameters = {
            "DATA_WIDTH": 64,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            parameters=parameters,
        )
        cases = ["t_reset_sync", "t_data_width_64b"]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

    def test_sel_width(self):
        parameters = {
            "SEL_WIDTH": 4,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            parameters=parameters,
        )
        cases = ["t_reset_sync", "t_sel_width_4b"]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

    def test_no_zero_x0(self):
        parameters = {
            "ZERO_X0": 0,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            parameters=parameters,
        )
        cases = ["t_reset_sync", "t_no_zero_x0"]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )
