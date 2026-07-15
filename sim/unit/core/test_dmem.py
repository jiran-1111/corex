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


# Default configuration (32-bit DATA_WIDTH)
DEFAULT_WORD_BYTES = 4


async def setup_dut(dut):
    """Setup DUT with clock and reset.

    Protocol: DMem read ack is asynchronous; write ack is synchronous.
    """
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    dut.rst.value = 1
    clear_request(dut)
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)


def fill_mem(dut, words: list[int], start: int = 0):
    for i, word in enumerate(words):
        dut.dmem.mem[start + i].value = word


def all_wbe(dut) -> int:
    return (1 << len(dut.wbe.value)) - 1


def clear_request(dut):
    dut.read.value = 0
    dut.write.value = 0
    dut.addr.value = 0
    dut.wdata.value = 0
    dut.wbe.value = 0


def drive_read(dut, addr: int):
    dut.read.value = 1
    dut.write.value = 0
    dut.addr.value = addr
    dut.wdata.value = 0
    dut.wbe.value = 0


def drive_write(dut, addr: int, data: int, wbe: int | None = None):
    dut.read.value = 0
    dut.write.value = 1
    dut.addr.value = addr
    dut.wdata.value = data
    dut.wbe.value = all_wbe(dut) if wbe is None else wbe


def drive_read_write(dut, addr: int, data: int, wbe: int | None = None):
    dut.read.value = 1
    dut.write.value = 1
    dut.addr.value = addr
    dut.wdata.value = data
    dut.wbe.value = all_wbe(dut) if wbe is None else wbe


def is_gnt_no_err(dut) -> bool:
    return dut.gnt.value == 1 and dut.err.value == 0


def is_read_response_correct(dut, expected_data: int) -> bool:
    return dut.rack.value == 1 and dut.wack.value == 0 and dut.rdata.value == expected_data


def is_write_response(dut) -> bool:
    return dut.rack.value == 0 and dut.wack.value == 1


def is_no_response(dut) -> bool:
    return dut.rack.value == 0 and dut.wack.value == 0


async def write_word(dut, addr: int, data: int, wbe: int | None = None):
    drive_write(dut, addr, data, wbe)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_write_response(dut)

    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)


@cocotb.test()
async def t_reset_sync(dut):
    """Test synchronous reset."""
    # Start the clock.
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())
    clear_request(dut)
    await ClockCycles(dut.clk, 2)

    # Assert rst on a clock edge.
    dut.rst.value = 1
    await RisingEdge(dut.clk)

    # Check responses on the next clock edge.
    await RisingEdge(dut.clk)
    assert is_no_response(dut)

    # Keep rst asserted for a few cycles.
    await ClockCycles(dut.clk, 2)
    assert is_no_response(dut)

    # Deassert rst on a clock edge.
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # Check the control signals on the next clock edge.
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)


@cocotb.test()
async def t_reset_after_request(dut):
    """Test reset after a request is made."""
    fill_mem(dut, [0x10, 0x11, 0x12, 0x13])

    # Reset the DUT.
    await setup_dut(dut)

    # Issue a read request. DMem read is asynchronous; sample it on the next edge.
    drive_read(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x10)

    # Issue a write request. DMem writes synchronously on the next clock edge.
    drive_write(dut, 1 * DEFAULT_WORD_BYTES, 0x21)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # Assert rst. The previous write response is still observed on this edge.
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_write_response(dut)

    # The reset clears the write response on the next clock edge.
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # Keep rst asserted for a few cycles.
    await ClockCycles(dut.clk, 2)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # Deassert rst and start a new read request.
    dut.rst.value = 0
    drive_read(dut, 3 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x13)

    # The write before reset committed.
    drive_read(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x21)

    drive_read(dut, 2 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x12)


@cocotb.test()
async def t_reset_and_request(dut):
    """Test a request issued during reset."""
    fill_mem(dut, [0x20, 0x21, 0x22, 0x23])

    # Reset the DUT.
    await setup_dut(dut)
    clear_request(dut)
    await RisingEdge(dut.clk)

    # Assert rst and issue a read request at the same time.
    dut.rst.value = 1
    drive_read(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # Send a write request during reset.
    drive_write(dut, 1 * DEFAULT_WORD_BYTES, 0x31)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # Check the response on the next clock edge.
    drive_write(dut, 1 * DEFAULT_WORD_BYTES, 0x31)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # Send a read request during reset.
    drive_read(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # Deassert rst and start a new write request.
    dut.rst.value = 0
    drive_write(dut, 2 * DEFAULT_WORD_BYTES, 0x32)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # Reset finishes. The write after reset completes.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_write_response(dut)

    # The cleared request is reflected on the next clock edge.
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # The write during reset did not commit; the write after reset did.
    drive_read(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x21)

    drive_read(dut, 2 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x32)


@cocotb.test()
async def t_read_single(dut):
    """Test a single read request."""
    fill_mem(dut, [0x30, 0x31, 0x32, 0x33])

    # Reset the DUT.
    await setup_dut(dut)

    # Issue a read request and check the response.
    drive_read(dut, 0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x30)

    # No request is made.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    # Issue a new requset and check the response.
    drive_read(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x31)


@cocotb.test()
async def t_read_burst(dut):
    """Test burst (back-to-back) read requests."""
    fill_mem(dut, [0x40, 0x41, 0x42, 0x43])

    # Reset the DUT.
    await setup_dut(dut)

    drive_read(dut, 0 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x40)

    drive_read(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x41)

    drive_read(dut, 2 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x42)

    drive_read(dut, 3 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x43)

    # Check that no more responses are made.
    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)


@cocotb.test()
async def t_read_unaligned(dut):
    """Test unaligned read requests."""
    fill_mem(dut, [0x50, 0x51, 0x52, 0x53])

    await setup_dut(dut)

    # All four byte offsets map to the same 32-bit word.
    for offset in range(4):
        drive_read(dut, DEFAULT_WORD_BYTES + offset)
        await RisingEdge(dut.clk)
        assert is_gnt_no_err(dut)
        assert is_read_response_correct(dut, 0x51)


@cocotb.test()
async def t_read_high_address(dut):
    """Test reads to high addresses (address truncation to valid range)."""
    fill_mem(dut, [0x60, 0x61, 0x62, 0x63])

    await setup_dut(dut)

    drive_read(dut, 0x4000_0004)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x61)

    drive_read(dut, 0x8000_000C)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x63)


@cocotb.test()
async def t_write_single(dut):
    """Test a single write request."""
    await setup_dut(dut)

    await write_word(dut, 0, 0x7101)
    drive_read(dut, 0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x7101)

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    await write_word(dut, 1 * DEFAULT_WORD_BYTES, 0x7202)
    drive_read(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x7202)


@cocotb.test()
async def t_read_after_write(dut):
    """Test a write request followed by a read request."""
    await setup_dut(dut)

    await write_word(dut, 0, 0x1101)
    drive_read(dut, 0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1101)

    await write_word(dut, 1 * DEFAULT_WORD_BYTES, 0x2202)
    drive_read(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x2202)

    drive_read(dut, 0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1101)


@cocotb.test()
async def t_write_burst(dut):
    """Test back-to-back write requests."""
    await setup_dut(dut)

    writes = [0x4404, 0x5505, 0x6606]
    drive_write(dut, 0, writes[0])
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    for i, data in enumerate(writes[1:], start=1):
        drive_write(dut, i * DEFAULT_WORD_BYTES, data)
        await RisingEdge(dut.clk)
        assert is_gnt_no_err(dut)
        assert is_write_response(dut)

    clear_request(dut)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_write_response(dut)

    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_no_response(dut)

    for i, data in enumerate(writes):
        drive_read(dut, i * DEFAULT_WORD_BYTES)
        await RisingEdge(dut.clk)
        assert is_gnt_no_err(dut)
        assert is_read_response_correct(dut, data)


@cocotb.test()
async def t_write_unaligned(dut):
    """Test unaligned write requests."""
    fill_mem(dut, [0x50, 0x51, 0x52, 0x53])

    await setup_dut(dut)

    # All four byte offsets map to the same 32-bit word.
    for offset, data in enumerate([0x8100, 0x8101, 0x8102, 0x8103]):
        await write_word(dut, DEFAULT_WORD_BYTES + offset, data)
        drive_read(dut, DEFAULT_WORD_BYTES)
        await RisingEdge(dut.clk)
        assert is_gnt_no_err(dut)
        assert is_read_response_correct(dut, data)


@cocotb.test()
async def t_write_high_address(dut):
    """Test writes to high addresses (address truncation to valid range)."""
    fill_mem(dut, [0x60, 0x61, 0x62, 0x63])

    await setup_dut(dut)

    await write_word(dut, 0x4000_0004, 0x9101)
    drive_read(dut, 1 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x9101)

    await write_word(dut, 0x8000_000C, 0x9303)
    drive_read(dut, 3 * DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x9303)


@cocotb.test()
async def t_write_byte_enable(dut):
    """Test byte-enable writes."""
    fill_mem(dut, [0x1122_3344])

    await setup_dut(dut)

    await write_word(dut, 0, 0x0000_00AA, 0b0001)
    drive_read(dut, 0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1122_33AA)

    await write_word(dut, 0, 0x0000_BB00, 0b0010)
    drive_read(dut, 0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1122_BBAA)

    await write_word(dut, 0, 0xCCCC_0000, 0b1100)
    drive_read(dut, 0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0xCCCC_BBAA)


class TestDMem_SV:
    """Test the data memory with default configuration."""

    runner: Runner
    hdl_top: str

    @classmethod
    def setup_class(cls):
        sources = [
            HDL_SV_DIR / "core" / "dbus_if.sv",
            HDL_SV_DIR / "core" / "dmem.sv",
        ]
        cls.hdl_top = "DMemTop"
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

    def test_read(self):
        cases = [
            "t_read_single",
            "t_read_burst",
            "t_read_unaligned",
            "t_read_high_address",
        ]
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

    def test_write(self):
        cases = [
            "t_write_single",
            "t_read_after_write",
            "t_write_burst",
            "t_write_unaligned",
            "t_write_high_address",
            "t_write_byte_enable",
        ]
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )


@cocotb.test()
async def t_data_8b(dut):
    """Test read/write requests for 8-bit data width."""
    fill_mem(dut, [0xAB, 0xCD, 0xEF, 0x12])

    await setup_dut(dut)

    drive_read(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0xAB)

    drive_read(dut, 0x1)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0xCD)

    await write_word(dut, 0x2, 0x5A)
    drive_read(dut, 0x2)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x5A)


@cocotb.test()
async def t_data_64b(dut):
    """Test read/write requests for 64-bit data width."""
    fill_mem(dut, [0x1234_5678_9ABC_DEF0, 0x0FED_CBA9_8765_4321])

    await setup_dut(dut)

    drive_read(dut, 0x0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1234_5678_9ABC_DEF0)

    drive_read(dut, 0x4)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1234_5678_9ABC_DEF0)

    drive_read(dut, 0x8)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x0FED_CBA9_8765_4321)

    await write_word(dut, 0x8, 0xA5A5_5A5A_DEAD_BEEF)
    drive_read(dut, 0x8)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0xA5A5_5A5A_DEAD_BEEF)


@cocotb.test()
async def t_size_256_addr_trunc(dut):
    """Test read/write address truncation for 256 bytes size."""
    fill_mem(dut, [0x1000 + i for i in range(64)])

    await setup_dut(dut)

    drive_read(dut, 0)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1000)

    drive_read(dut, 256)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1000)

    drive_read(dut, 252)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1000 + 63)

    drive_read(dut, 252 + 256)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x1000 + 63)

    await write_word(dut, 256 + DEFAULT_WORD_BYTES, 0x2222)
    drive_read(dut, DEFAULT_WORD_BYTES)
    await RisingEdge(dut.clk)
    assert is_gnt_no_err(dut)
    assert is_read_response_correct(dut, 0x2222)


class TestDMemParam_SV:
    """Test the data memory parameters."""

    sources = [
        HDL_SV_DIR / "core" / "dbus_if.sv",
        HDL_SV_DIR / "core" / "dmem.sv",
    ]
    hdl_top = "DMemTop"

    def test_data_8b(self):
        parameters = {
            "DATA_WIDTH": 8,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            build_id=f"{self.hdl_top}.data_8b",
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
            build_id=f"{self.hdl_top}.data_64b",
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
            build_id=f"{self.hdl_top}.size_256",
            parameters=parameters,
        )
        cases = [
            "t_reset_sync",
            "t_size_256_addr_trunc",
        ]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )
