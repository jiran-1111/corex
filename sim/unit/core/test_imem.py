# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Chun Yang

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge

from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner


# Default configuration (32-bit DATA_WIDTH)
DEFAULT_WORD_BYTES = 4


async def setup_dut(dut):
    """Setup DUT with clock and reset.

    Protocol: rdata output is only valid when ack==1.
    When ack==0, rdata value is undefined and must not be used.
    """
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    dut.rst.value = 1
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)


def fill_mem(dut, words: list[int], start: int = 0):
    for i, word in enumerate(words):
        dut.imem.mem[start + i].value = word


def clear_request(dut):
    dut.req.value = 0


def drive_request(dut, addr: int):
    dut.addr.value = addr
    dut.req.value = 1


def is_gnt_no_err(dut) -> bool:
    return dut.gnt.value == 1 and dut.err.value == 0


def is_response_correct(dut, expected_data: int) -> bool:
    return dut.ack.value == 1 and dut.rdata.value == expected_data


@cocotb.test()
async def t_reset_sync(dut):
    """Test synchronous reset."""
    # Start the clock.
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())
    await ClockCycles(dut.clk, 2)

    # Assert rst on a clock edge.
    dut.rst.value = 1
    await RisingEdge(dut.clk)

    # Check the control signals on the next clock edge.
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Keep rst asserted for a few cycles.
    await ClockCycles(dut.clk, 2)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Deassert rst on a clock edge.
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # Check the control signals on the next clock edge.
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0


@cocotb.test()
async def t_reset_after_request(dut):
    """Test reset after a request is made."""
    fill_mem(dut, [0x10, 0x11, 0x12, 0x13])

    # Reset the DUT.
    await setup_dut(dut)

    # Issue a request.
    drive_request(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response on the next clock edge.
    drive_request(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x10)

    # Assert rst.
    dut.rst.value = 1
    drive_request(dut, 2 * DEFAULT_WORD_BYTES)  # Ignored due to reset
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x11)

    # Check the control signals on the next clock edge.
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Keep rst asserted for a few cycles.
    await ClockCycles(dut.clk, 2)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Deassert rst and start a new request.
    dut.rst.value = 0
    drive_request(dut, 3 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Reset finishes. The request after reset completes.
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x13)


@cocotb.test()
async def t_reset_and_request(dut):
    """Test a request issued during reset."""
    fill_mem(dut, [0x20, 0x21, 0x22, 0x23])

    # Reset the DUT.
    await setup_dut(dut)
    clear_request(dut)
    await RisingEdge(dut.clk)

    # Assert rst and issue a request at the same time.
    dut.rst.value = 1
    drive_request(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response on the next clock edge.
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Send a request during reset.
    drive_request(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response on the next clock edge.
    drive_request(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Deassert rst and start a new request.
    dut.rst.value = 0
    drive_request(dut, 2 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Reset finishes. The request after reset completes.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x22)


@cocotb.test()
async def t_request_single(dut):
    """Test a single request."""
    fill_mem(dut, [0x30, 0x31, 0x32, 0x33])

    # Reset the DUT.
    await setup_dut(dut)

    # Issue a request.
    drive_request(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response on the next clock edge.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x30)

    # No request is made.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # No response is made. Issue a new request.
    drive_request(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response on the next clock edge.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x31)


@cocotb.test()
async def t_request_burst(dut):
    """Test burst (back-to-back) requests."""
    fill_mem(dut, [0x40, 0x41, 0x42, 0x43])

    # Reset the DUT.
    await setup_dut(dut)

    # Issue back-to-back requests, advancing the address each cycle.
    drive_request(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response for the first request.
    drive_request(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x40)

    # Check the response for the second request.
    drive_request(dut, 2 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x41)

    # Check the response for the third request.
    drive_request(dut, 3 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x42)

    # Check the response for the fourth request. Stop requesting.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x43)

    # Check that no more responses are made.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0


@cocotb.test()
async def t_request_unaligned(dut):
    """Test unaligned requests."""
    fill_mem(dut, [0x50, 0x51, 0x52, 0x53])

    # Reset the DUT.
    await setup_dut(dut)

    # All four byte offsets map to the same word.
    for offset in range(4):
        # Issue a request.
        drive_request(dut, DEFAULT_WORD_BYTES + offset)
        await RisingEdge(dut.clk)
        assert is_gnt_no_err(dut)
        assert dut.ack.value == 0

        # Check the response on the next clock edge.
        clear_request(dut)
        await RisingEdge(dut.clk)
        assert is_gnt_no_err(dut)
        assert is_response_correct(dut, 0x51)


@cocotb.test()
async def t_request_high_address(dut):
    """Test requests to high addresses (address truncation to valid range)."""
    fill_mem(dut, [0x60, 0x61, 0x62, 0x63])

    # Reset the DUT.
    await setup_dut(dut)

    # High addresses are truncated to the valid memory address range.
    drive_request(dut, 0x4000_0004)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response on the next clock edge.
    drive_request(dut, 0x8000_000C)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x61)

    # Check the response for another high address.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x63)


class TestIMem_SV:
    """Test the instruction memory with default configuration."""

    runner: Runner
    hdl_top: str

    @classmethod
    def setup_class(cls):
        sources = [
            HDL_SV_DIR / "core" / "ibus_if.sv",
            HDL_SV_DIR / "core" / "imem.sv",
        ]
        cls.hdl_top = "IMemTop"
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    def test_reset(self):
        cases = [
            "t_reset_sync",
            "t_reset_after_request",
            "t_reset_and_request",
        ]
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

    def test_request(self):
        cases = [
            "t_request_single",
            "t_request_burst",
            "t_request_unaligned",
            "t_request_high_address",
        ]
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )


@cocotb.test()
async def t_data_8b(dut):
    """Test requests for 8-bit data width."""
    fill_mem(dut, [0xAB, 0xCD, 0xEF, 0x12])

    # Reset the DUT.
    await setup_dut(dut)

    # Issue a single request.
    drive_request(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response on the next clock edge.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0xAB)

    # Start burst requests.
    drive_request(dut, 0x1)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response for the first request.
    drive_request(dut, 0x2)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0xCD)

    # Check the response for the second request.
    drive_request(dut, 0x3)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0xEF)

    # Check the response for the third request.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x12)


@cocotb.test()
async def t_data_64b(dut):
    """Test requests for 64-bit data width."""
    fill_mem(dut, [0x1234_5678_9ABC_DEF0, 0x0FED_CBA9_8765_4321])

    # Reset the DUT.
    await setup_dut(dut)

    # Issue a single request.
    drive_request(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response on the next clock edge.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x1234_5678_9ABC_DEF0)

    # Start burst requests.
    drive_request(dut, 0x8)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    # Check the response for the first request.
    drive_request(dut, 0x4)  # Unaligned address
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x0FED_CBA9_8765_4321)

    # Check the response for the second request.
    drive_request(dut, 0x8)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x1234_5678_9ABC_DEF0)

    # Check the response for the third request.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x0FED_CBA9_8765_4321)


@cocotb.test()
async def t_size_256_addr_trunc(dut):
    """Test address truncation for 256 bytes size."""
    # Fill memory with recognizable test data
    # mem[0]=0x1000, mem[1]=0x1001, ..., mem[63]=0x103F
    fill_mem(dut, [0x1000 + i for i in range(64)])

    # Reset the DUT.
    await setup_dut(dut)

    # addr=0 reads mem[0]
    drive_request(dut, 0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x1000)

    # addr=256 also reads mem[0] (high bits truncated)
    drive_request(dut, 256)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x1000)

    # addr=252 reads mem[63] (last valid address within 256 bytes)
    drive_request(dut, 252)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x1000 + 63)

    # addr=252+256 also reads mem[63] (address wraps around)
    drive_request(dut, 252 + 256)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x1000 + 63)


@cocotb.test()
async def t_size_256_boundary(dut):
    """Test boundary addresses for 256 bytes size."""
    # Fill memory with address-indexed data
    fill_mem(dut, [0x2000 + i for i in range(64)])

    # Reset the DUT.
    await setup_dut(dut)

    # Mid-range address (offset 128 = 32 words)
    drive_request(dut, 128)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x2000 + 32)

    # Last valid aligned address (252 = mem[63])
    drive_request(dut, 252)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x2000 + 63)

    # Unaligned address at boundary (253, 254, 255 all map to mem[63])
    drive_request(dut, 253)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x2000 + 63)

    # Address wraps to start (256 wraps to 0, reads mem[0])
    drive_request(dut, 256)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x2000)

    # Address wraps past boundary (512 wraps to 0, reads mem[0])
    drive_request(dut, 512)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x2000)

    # Address wraps correctly (300 -> 44, reads mem[11])
    drive_request(dut, 300)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert dut.ack.value == 0

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_response_correct(dut, 0x2000 + 11)


class TestIMemParam_SV:
    """Test the instruction memory parameters."""

    sources = [
        HDL_SV_DIR / "core" / "ibus_if.sv",
        HDL_SV_DIR / "core" / "imem.sv",
    ]
    hdl_top = "IMemTop"

    def test_data_8b(self):
        parameters = {
            "DATA_WIDTH": 8,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            parameters=parameters,
        )
        cases = ["t_reset_sync", "t_data_8b"]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

    def test_data_64b(self):
        parameters = {
            "DATA_WIDTH": 64,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            parameters=parameters,
        )
        cases = ["t_reset_sync", "t_data_64b"]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

    def test_256_size(self):
        parameters = {
            "SIZE_BYTES": 256,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            parameters=parameters,
        )
        cases = [
            "t_reset_sync",
            "t_size_256_addr_trunc",
            "t_size_256_boundary",
        ]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )
