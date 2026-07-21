# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.


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
    dut.rst.value = 0
    dut.start.value = 1
    await RisingEdge(dut.clk)
    await Timer(1, unit="step")
    dut.start.value = 0 
    
    await clock_tick(dut)

# 把汇编指令参数打包编码为32位机器码 
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


def b_type(
    imm: int, 
    rs2: int, 
    rs1: int, 
    funct3: int, 
    opcode: int = 0x63
) -> int:
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


def s_type(
    imm: int, 
    rs2: int, 
    rs1: int, 
    funct3: int, 
    opcode: int = 0x23
) -> int:
    imm &= 0xFFF
    return (
        ((imm >> 5) & 0x7F) << 25
        | (rs2 << 20)
        | (rs1 << 15)
        | (funct3 << 12)
        | (imm & 0x1F) << 7
        | opcode
    )


def j_type(
    imm: int, 
    rd: int, 
    opcode: int = 0x6F
) -> int:
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
    """读取 DMem 内部指定字（Word）索引的数据。 验证存储指令如store"""
    return int(dut.u_dmem.dmem.mem[index].value)


async def run_cycles(dut, cycles: int):
    for _ in range(cycles):
        await clock_tick(dut)

@cocotb.test()
async def t_core_control_stall_only(dut):
    """测试控制跳转（增加详细流水线追踪日志）。"""
    program = [
        b_type(8, 0, 0, 0),     # 0x00: beq x0, x0, 0x08 (Taken)
        i_type(99, 0, 0, 1),    # 0x04: skipped -> x1 不应被写为 99
        i_type(5, 0, 0, 2),     # 0x08: addi x2, x0, 5  -> x2 = 5
        b_type(8, 0, 0, 1),     # 0x0c: bne x0, x0, 0x14 (Not taken)
        i_type(6, 0, 0, 3),     # 0x10: addi x3, x0, 6  -> x3 = 6
        j_type(8, 4),           # 0x14: jal x4, 0x1c   -> x4 = 0x18
        i_type(88, 0, 0, 5),    # 0x18: skipped -> x5 不应被写为 88
        i_type(0x28, 0, 0, 7, opcode=0x67),  # 0x1c: jalr x7, 0x28(x0) -> x7 = 0x20
        i_type(77, 0, 0, 8),    # 0x20: skipped -> x8 不应被写为 77
        i_type(66, 0, 0, 9),    # 0x24: skipped -> x9 不应被写为 66
        i_type(10, 0, 0, 10),   # 0x28: addi x10, x0, 10 -> x10 = 10
    ]
    fill_mem(dut, program)

    await setup_dut(dut)

    dut._log.info("=" * 80)
    dut._log.info(f"{'Cycle':<6} | {'IF_PC':<8} | {'WB_Wen':<6} | {'WB_Rd':<6} | {'WB_Data':<10} | {'Flush/Stall Status'}")
    dut._log.info("=" * 80)

    for i in range(25):
        await RisingEdge(dut.clk)
        
        # 1. 抓取 IF 级 PC
        if_pc = hex(int(dut.u_ifu.inst_PC.value)) if hasattr(dut.u_ifu, 'inst_PC') else "N/A"

        # 2. 抓取 RegFile 写回信号
        rf_wen = int(dut.u_decoder.u_regfile.wen.value) if hasattr(dut.u_decoder.u_regfile, 'wen') else 0
        rf_waddr = int(dut.u_decoder.u_regfile.waddr.value) if hasattr(dut.u_decoder.u_regfile, 'waddr') else 0
        rf_wdata = int(dut.u_decoder.u_regfile.wdata.value) if hasattr(dut.u_decoder.u_regfile, 'wdata') else 0

        # 3. 抓取 Flush / Stall 调试信号 (如果 signal 名字不同请根据 RTL 稍作调整)
        flush_str = ""
        if hasattr(dut, 'flush'):
            flush_str += f"flush={int(dut.flush.value)} "
        if hasattr(dut, 'stall'):
            flush_str += f"stall={int(dut.stall.value)}"

        # 打印单周期详细状态
        dut._log.info(
            f"Cycle {i:<2} | {if_pc:<8} | {rf_wen:<6} | x{rf_waddr:<5} | {rf_wdata:<10} | {flush_str}"
        )

    dut._log.info("=" * 80)

    # 4. 寄存器结果检查并输出明确的错误点
    expected_regs = {
        1: 0,   # skipped by beq
        2: 5,   # addi
        3: 6,   # addi
        4: 0x18,# jal link addr
        5: 0,   # skipped by jal
        7: 0x20,# jalr link addr
        8: 0,   # skipped by jalr
        9: 0,   # skipped by jalr
        10: 10, # addi
    }

    for reg_idx, expected in expected_regs.items():
        actual = read_reg(dut, reg_idx)
        assert actual == expected, (
            f"\n[Reg Check Failed] Register x{reg_idx} Error!\n"
            f"  Expected: {expected} (0x{expected:x})\n"
            f"  Actual:   {actual} (0x{actual:x})"
        )



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
            HDL_SV_DIR / "core" / "core.sv",
        ]
        cls.hdl_top = "CoreTop"
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    def test_raw_stall(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_control_stall_only",
        )