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


async def settle(): # 组合逻辑 读操作
    await Timer(1, unit="step")


async def clock_tick(dut):  # 时序逻辑 写操作 推进时间
    await RisingEdge(dut.clk)
    await settle()


async def setup_dut(dut):
    """Setup DUT with clock, reset, and stable input defaults."""
    """初始化被测芯片 时钟接通 复位 输入信号都设置为默认值 """
    # CLK_PERIOD_NS = 10
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    dut.rst.value = 1 # 内部寄存器清零
    dut.wen.value = 0 # 输入管脚清零
    dut.waddr.value = 0
    dut.wdata.value = 0
    dut.raddr1.value = 0
    dut.raddr2.value = 0
    await ClockCycles(dut.clk, 2) 
    await settle() 
    dut.rst.value = 0
    await clock_tick(dut)



# 读写函数
def drive_write(dut, addr: int, data: int, *, wen: int = 1):
    dut.wen.value = wen
    dut.waddr.value = addr
    dut.wdata.value = data


def drive_read(dut, addr1: int, addr2: int):
    dut.raddr1.value = addr1
    dut.raddr2.value = addr2

# 写入寄存器
async def write_reg(dut, addr: int, data: int):
    drive_write(dut, addr, data)
    await clock_tick(dut)
    dut.wen.value = 0 # 写使能清零
    await settle()

# 检测2个读取数据是否正确
def assert_read(dut, expected1: int, expected2: int):
    assert dut.rdata1.value == expected1
    assert dut.rdata2.value == expected2

# test_reset*****************
"""
芯片刚断电开机，按下复位键，内部寄存器能否正确清零。把setup_dut拆开测
"""
@cocotb.test()
async def t_reset_sync(dut):
    """Test synchronous reset clears registers."""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    dut.rst.value = 1
    dut.wen.value = 0
    dut.waddr.value = 0
    dut.wdata.value = 0
    drive_read(dut, 0, 0) # 读0号寄存器
    await ClockCycles(dut.clk, 2)
    await settle()
    assert_read(dut, 0, 0)

    dut.rst.value = 0  
    await clock_tick(dut)
    assert_read(dut, 0, 0)


"""
验证芯片正常工作、里面已经存了数据，此时按下复位键，数据能否被瞬间洗掉。
"""
@cocotb.test()
async def t_reset_after_write(dut):
    """Test reset clears written registers."""
    await setup_dut(dut)

    await write_reg(dut, 1, 0x1001) 
    await write_reg(dut, 2, 0x2002)
    drive_read(dut, 1, 2)
    await settle()
    assert_read(dut, 0x1001, 0x2002)

    dut.rst.value = 1
    await clock_tick(dut)
    assert_read(dut, 0, 0)

"""
当复位键被按下
如果试图同时往里写数据，芯片能不能拒绝接收”？
"""
@cocotb.test()
async def t_reset_and_write(dut):
    """Test writes are ignored while reset is asserted."""
    await setup_dut(dut)

    drive_read(dut, 1, 0)
    dut.rst.value = 1
    drive_write(dut, 1, 0x1001)
    await clock_tick(dut) # 写之后是tick or settle
    assert_read(dut, 0, 0)

"""
普通写后读，
"""
@cocotb.test()
async def t_write_and_read(dut):
    """Test normal writes and the two combinational read ports."""
    await setup_dut(dut)

    await write_reg(dut, 1, 0x1101)
    await write_reg(dut, 2, 0x2202)

    drive_read(dut, 1, 2)
    await settle()
    assert_read(dut, 0x1101, 0x2202)

"""
测试不给写使能时，数据是否被篡改
"""
@cocotb.test()
async def t_write_disabled(dut):
    """Test wen=0 prevents register updates."""
    await setup_dut(dut)

    await write_reg(dut, 3, 0x3303)

    drive_read(dut, 3, 3)
    await settle()
    assert_read(dut, 0x3303, 0x3303)

    drive_write(dut, 3, 0x4404, wen=0)
    await clock_tick(dut)
    assert_read(dut, 0x3303, 0x3303)

"""
连续写
"""
@cocotb.test()
async def t_write_burst(dut):
    """Test back-to-back writes."""
    await setup_dut(dut)

    drive_write(dut, 4, 0x4404)
    await clock_tick(dut)

    drive_write(dut, 5, 0x5505)
    await clock_tick(dut)

    drive_write(dut, 6, 0x6606)
    await clock_tick(dut)

    dut.wen.value = 0 # 关闭写使能
    drive_read(dut, 4, 5)
    await settle()
    assert_read(dut, 0x4404, 0x5505)

    drive_read(dut, 6, 0)
    await settle()
    assert_read(dut, 0x6606, 0)

"""
检测x0
"""
@cocotb.test()
async def t_write_x0(dut):
    """Test x0 ignores writes and always reads as zero."""
    await setup_dut(dut)

    drive_read(dut, 0, 0)
    drive_write(dut, 0, 0x0001)
    await settle()
    assert_read(dut, 0, 0)

    await clock_tick(dut)
    assert_read(dut, 0, 0)

    dut.wen.value = 0
    await settle()
    assert_read(dut, 0, 0)

"""
写后读旁路测试read-after-write bypass 也叫数据前推data forwarding
"""
@cocotb.test()
async def t_read_after_write_bypass(dut):
    """Test same-cycle read-after-write bypass."""
    await setup_dut(dut)

    await write_reg(dut, 7, 0x7001)

    drive_read(dut, 7, 0) # 还没写入就读
    drive_write(dut, 7, 0x7002)
    await settle()
    assert_read(dut, 0x7002, 0)

    await clock_tick(dut) # 时钟步进后再读
    dut.wen.value = 0
    await settle()
    assert_read(dut, 0x7002, 0)

    drive_read(dut, 7, 8)
    drive_write(dut, 8, 0x8001)
    await settle()
    assert_read(dut, 0x7002, 0x8001)

# 基础配置测试类
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

    def test_bypass(self):
        cases = [
            "t_read_after_write_bypass",
        ]
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

"""
测试数据位宽被设置为64位时，能否正确读出
"""
@cocotb.test()
async def t_data_width_64b(dut):
    """Test 64-bit REG_DATA_WIDTH parameter."""
    await setup_dut(dut)

    await write_reg(dut, 1, 0x1234_5678_9ABC_DEF0)
    drive_read(dut, 1, 0)
    await settle()
    assert_read(dut, 0x1234_5678_9ABC_DEF0, 0)

"""
测试地址选择位宽被设置为4位时，能否正确读出
"""
@cocotb.test()
async def t_sel_width_4b(dut):
    """Test 4-bit REG_SEL_WIDTH parameter."""
    await setup_dut(dut)

    await write_reg(dut, 15, 0x150F)
    drive_read(dut, 15, 0)
    await settle()
    assert_read(dut, 0x150F, 0)

"""
测试zero_x0作为普通寄存器时是否能够读写
"""
@cocotb.test()
async def t_x0_as_normal_reg(dut):
    """Test x0 as normal register can be read and written."""
    await setup_dut(dut)

    await write_reg(dut, 0, 0x150F)
    drive_read(dut, 0, 0)
    await settle()
    assert_read(dut, 0x150F, 0x150F)

class TestRegFileParam_SV:
    """Test the register file parameters."""

    sources = [
        HDL_SV_DIR / "core" / "reg_file.sv",
    ]
    hdl_top = "RegFile"
    # 定义数据位宽为64位的测试
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
    
    def test_zero_x0(self):
        parameters = {
            "ZERO_X0": 0 ,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            parameters=parameters,
        )
        cases = ["t_x0_as_normal_reg"]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )
