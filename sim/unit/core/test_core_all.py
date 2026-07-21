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
    
    # 2. 解除复位并给一个单周期的 start 脉冲
    dut.rst.value = 0
  
    dut.start.value = 1  # 给出 start 脉冲
    
    await RisingEdge(dut.clk)
    await Timer(1, unit="step")
    

    dut.start.value = 0  # <---【关键修改】及时拉低 start，允许 PC 开始自增！
    
    await clock_tick(dut)


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


def b_type(imm: int, rs2: int, rs1: int, funct3: int, opcode: int = 0x63) -> int:
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


def s_type(imm: int, rs2: int, rs1: int, funct3: int, opcode: int = 0x23) -> int:
    imm &= 0xFFF
    return (
        ((imm >> 5) & 0x7F) << 25
        | (rs2 << 20)
        | (rs1 << 15)
        | (funct3 << 12)
        | (imm & 0x1F) << 7
        | opcode
    )


def j_type(imm: int, rd: int, opcode: int = 0x6F) -> int:
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
    """读取 DMem 内部指定字（Word）索引的数据。"""
    # 假设 DMemTop 内部的 Ram 存储器实例名为 u_dmem 或 mem
    return int(dut.u_dmem.dmem.mem[index].value)


async def run_cycles(dut, cycles: int):
    for _ in range(cycles):
        await clock_tick(dut)

# 通过
@cocotb.test()
async def t_core_raw_stall_only(dut):
    """read-after-write without control-flow"""
    program = [
        i_type(5, 0, 0, 1),      # 0x00: addi x1, x0, 5
        i_type(7, 1, 0, 2),      # 0x04: addi x2, x1, 7
        r_type(0, 2, 1, 0, 3),   # 0x08: add x3, x1, x2
        i_type(1, 3, 0, 4),      # 0x0c: addi x4, x3, 1
    ]
    fill_mem(dut, program)
    """
    await setup_dut(dut)
    dut._log.info(f"Fetched Inst at PC 0: {hex(dut.u_ifu.instruction.value)}")
    #await run_cycles(dut, 30)
    # 在 test 循环中加入打印
    
    for i in range(20):
        await RisingEdge(dut.clk)
        dut._log.info(
            f"Cycle {i}: PC={hex(dut.u_ifu.inst_PC.value)} "
            f"| WB_data={dut.u_decoder.u_regfile.wdata.value}"
        )
    """
    await setup_dut(dut)
    await run_cycles(dut, 30)
    assert read_reg(dut, 1) == 5
    assert read_reg(dut, 2) == 12
    assert read_reg(dut, 3) == 17
    assert read_reg(dut, 4) == 18




@cocotb.test()
async def t_core_control_stall_only(dut):
    """详细日志版：测试控制跳转及流水线 Flush 机制"""
    program = [
        b_type(8, 0, 0, 0),                  # 0x00: beq x0, x0, 0x08
        i_type(99, 0, 0, 1),                 # 0x04: skipped
        i_type(5, 0, 0, 2),                  # 0x08: addi x2, x0, 5
        b_type(8, 0, 0, 1),                  # 0x0c: bne x0, x0, 0x14 (not taken)
        i_type(6, 0, 0, 3),                  # 0x10: addi x3, x0, 6
        j_type(8, 4),                        # 0x14: jal x4, 0x1c
        i_type(88, 0, 0, 5),                 # 0x18: skipped
        i_type(0x28, 0, 0, 7, opcode=0x67),  # 0x1c: jalr x7, 0x28(x0)
        i_type(77, 0, 0, 8),                 # 0x20: skipped
        i_type(66, 0, 0, 9),                 # 0x24: skipped
        i_type(10, 0, 0, 10),                # 0x28: addi x10, x0, 10
    ]
    fill_mem(dut, program)
    await setup_dut(dut)

    dut._log.info("=" * 70)
    dut._log.info(" STARTING CONTROL STALL TRACE")
    dut._log.info("=" * 70)

    # 运行 25 个周期并在每个周期记录详细流水线状态
    for cycle in range(25):
        await RisingEdge(dut.clk)
        
        # 1. 提取当前 IFU 的 PC 指针
        pc_val = int(dut.u_ifu.inst_PC.value)
        
        # 2. 提取 Flush 及相关跳转子信号
        try:
            flush_val = int(dut.flush.value)
            jump_flush_val = int(dut.id_jump_flush.value)
            pc_sel_val = int(dut.ex_pc_sel.value)
            branch_taken_val = int(dut.ex_branch_taken.value)
            
            # 格式化 Flush 诊断日志
            flush_info = f"| FLUSH={flush_val} (JMP_FLUSH={jump_flush_val}, PC_SEL={pc_sel_val}, B_TAKEN={branch_taken_val})"
        except AttributeError:
            flush_info = "| FLUSH=未知信号"

        # 3. 提取 Regfile 写回信号（适配常见信号名：we / write_en / reg_write）
        try:
            wb_we = int(dut.u_decoder.u_regfile.we.value)
            wb_rd = int(dut.u_decoder.u_regfile.waddr.value)
            wb_data = int(dut.u_decoder.u_regfile.wdata.value)
            wb_info = f"| WB -> x{wb_rd} = {wb_data} (hex: {hex(wb_data)})" if (wb_we and wb_rd != 0) else "| WB -> [None]"
        except AttributeError:
            # 如果信号名不一样，回退到普通打印
            wb_data = int(dut.u_decoder.u_regfile.wdata.value)
            wb_info = f"| WB_data = {hex(wb_data)}"

        # 4. 打印周期摘要（包含 PC、Flush 状态和写回状态）
        dut._log.info(f"[Cycle {cycle:02d}] IFU_PC = {hex(pc_val):<6} {flush_info:<55} {wb_info}")

    dut._log.info("=" * 70)
    dut._log.info(" CHECKING REGISTER RESULTS")
    dut._log.info("=" * 70)

    # 逐项断言，附带极详细的错误定位日志
    checks = [
        (1, 0,    "0x04 addi x1 (应被 beq 跳过，若不为0说明 Flush 机制失效，错执行了被跳过的指令)"),
        (2, 5,    "0x08 addi x2 (beq 目标地址，应正常写入 5)"),
        (3, 6,    "0x10 addi x3 (bne 未触发跳转，应顺序执行写入 6)"),
        (4, 0x18, "0x14 jal  x4 (应将下一条地址 0x18 作为 link address 写入 x4)"),
        (5, 0,    "0x18 addi x5 (应被 jal 跳过，若不为0说明 jal 的 Flush 失效)"),
        (7, 0x20, "0x1c jalr x7 (应将下一条地址 0x20 作为 link address 写入 x7)"),
        (8, 0,    "0x20 addi x8 (应被 jalr 跳过)"),
        (9, 0,    "0x24 addi x9 (应被 jalr 跳过)"),
        (10, 10,  "0x28 addi x10 (jalr 终点目标，应正常写入 10)"),
    ]

    failed = False
    for reg_idx, expected, msg in checks:
        actual = read_reg(dut, reg_idx)
        if actual != expected:
            dut._log.error(f"❌ [FAIL] x{reg_idx}: 期望值 = {expected} ({hex(expected)}), 实际值 = {actual} ({hex(actual)})")
            dut._log.error(f"    └─ 原因信息: {msg}")
            failed = True
        else:
            dut._log.info(f"  [PASS] x{reg_idx} = {actual} ({hex(actual)})")

    assert not failed, "控制跳转测试失败！请查看上方标 ❌ 的具体错误原因。"

@cocotb.test()
async def t_core_alu_stall_and_redirect(dut):
    """测试 ALU 指令及流水线冲刷。"""
    program = [
        i_type(5, 0, 0, 1),      # 0x00: addi x1, x0, 5
        i_type(7, 1, 0, 2),      # 0x04: addi x2, x1, 7
        r_type(0, 2, 1, 0, 3),   # 0x08: add x3, x1, x2
        j_type(8, 4),            # 0x0c: jal x4, 0x14
        i_type(99, 0, 0, 5),     # 0x10: skipped
        b_type(8, 3, 3, 0),      # 0x14: beq x3, x3, 0x1c
        i_type(88, 0, 0, 6),     # 0x18: skipped
        i_type(2, 4, 0, 7),      # 0x1c: addi x7, x4, 2
        i_type(0x2C, 0, 0, 9),   # 0x20: addi x9, x0, 0x2c
        i_type(0, 9, 0, 10, opcode=0x67),  # 0x24: jalr x10, 0(x9)
        i_type(123, 0, 0, 11),   # 0x28: skipped
        i_type(1, 10, 0, 12),    # 0x2c: addi x12, x10, 1
        b_type(8, 1, 0, 0),      # 0x30: beq x0, x1, 0x38 (not taken)
        i_type(13, 0, 0, 13),    # 0x34: addi x13, x0, 13
        i_type(1, 13, 0, 14),    # 0x38: addi x14, x13, 1
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    #await run_cycles(dut, 60)
    for i in range(20):
        await RisingEdge(dut.clk)
        dut._log.info(
            f"Cycle {i}: PC={hex(dut.u_ifu.inst_PC.value)} "
            f"| WB_data={dut.u_decoder.u_regfile.wdata.value}"
        )

    assert read_reg(dut, 1) == 5
    assert read_reg(dut, 2) == 12
    assert read_reg(dut, 3) == 17
    assert read_reg(dut, 4) == 0x10
    assert read_reg(dut, 5) == 0
    assert read_reg(dut, 6) == 0
    assert read_reg(dut, 7) == 0x12
    assert read_reg(dut, 9) == 0x2C
    assert read_reg(dut, 10) == 0x28
    assert read_reg(dut, 11) == 0
    assert read_reg(dut, 12) == 0x29
    assert read_reg(dut, 13) == 13
    assert read_reg(dut, 14) == 14

@cocotb.test()
async def t_core_control_stall_jal_only(dut):
    """对照测试：将 JALR 替换为 JAL，验证纯 PC 相对跳转及 Flush 机制"""
    program = [
        b_type(8, 0, 0, 0),                  # 0x00: beq x0, x0, 0x08
        i_type(99, 0, 0, 1),                 # 0x04: skipped
        i_type(5, 0, 0, 2),                  # 0x08: addi x2, x0, 5
        b_type(8, 0, 0, 1),                  # 0x0c: bne x0, x0, 0x14 (not taken)
        i_type(6, 0, 0, 3),                  # 0x10: addi x3, x0, 6
        j_type(8, 4),                        # 0x14: jal x4, 0x1c (跳转到 0x1c)
        i_type(88, 0, 0, 5),                 # 0x18: skipped
        j_type(12, 7),                       # 0x1c: jal x7, 0x28 (修改点：用 JAL 替换原本的 JALR，跳转到 0x28)
        i_type(77, 0, 0, 8),                 # 0x20: skipped
        i_type(66, 0, 0, 9),                 # 0x24: skipped
        i_type(10, 0, 0, 10),                # 0x28: addi x10, x0, 10
    ]
    fill_mem(dut, program)
    await setup_dut(dut)

    dut._log.info("=" * 70)
    dut._log.info(" STARTING CONTROL STALL TRACE (JAL-ONLY CONTRAST TEST)")
    dut._log.info("=" * 70)

    # 运行 25 个周期并在每个周期记录详细流水线状态
    for cycle in range(25):
        await RisingEdge(dut.clk)
        
        # 1. 提取当前 IFU 的 PC 指针
        pc_val = int(dut.u_ifu.inst_PC.value)
        
        # 2. 提取 Flush 及相关跳转子信号
        try:
            flush_val = int(dut.flush.value)
            jump_flush_val = int(dut.id_jump_flush.value)
            pc_sel_val = int(dut.ex_pc_sel.value)
            branch_taken_val = int(dut.ex_branch_taken.value)
            
            # 格式化 Flush 诊断日志
            flush_info = f"| FLUSH={flush_val} (JMP_FLUSH={jump_flush_val}, PC_SEL={pc_sel_val}, B_TAKEN={branch_taken_val})"
        except AttributeError:
            flush_info = "| FLUSH=未知信号"

        # 3. 提取 Regfile 写回信号
        try:
            wb_we = int(dut.u_decoder.u_regfile.we.value)
            wb_rd = int(dut.u_decoder.u_regfile.waddr.value)
            wb_data = int(dut.u_decoder.u_regfile.wdata.value)
            wb_info = f"| WB -> x{wb_rd} = {wb_data} (hex: {hex(wb_data)})" if (wb_we and wb_rd != 0) else "| WB -> [None]"
        except AttributeError:
            wb_data = int(dut.u_decoder.u_regfile.wdata.value)
            wb_info = f"| WB_data = {hex(wb_data)}"

        # 4. 打印周期摘要
        dut._log.info(f"[Cycle {cycle:02d}] IFU_PC = {hex(pc_val):<6} {flush_info:<55} {wb_info}")

    dut._log.info("=" * 70)
    dut._log.info(" CHECKING REGISTER RESULTS (JAL-ONLY)")
    dut._log.info("=" * 70)

    # 逐项断言检查
    checks = [
        (1, 0,    "0x04 addi x1 (应被 beq 跳过)"),
        (2, 5,    "0x08 addi x2 (beq 目标，应为 5)"),
        (3, 6,    "0x10 addi x3 (bne 未触发，应正常写入 6)"),
        (4, 0x18, "0x14 jal  x4 (链接地址应为 0x18)"),
        (5, 0,    "0x18 addi x5 (应被第一个 jal 跳过)"),
        (7, 0x20, "0x1c jal  x7 (链接地址应为 0x20)"),
        (8, 0,    "0x20 addi x8 (应被第二个 jal 跳过，若不为0说明 JAL 的 Flush 或 PC跳转失效)"),
        (9, 0,    "0x24 addi x9 (应被第二个 jal 跳过)"),
        (10, 10,  "0x28 addi x10 (第二个 jal 终点目标，应正常写入 10)"),
    ]

    failed = False
    for reg_idx, expected, msg in checks:
        actual = read_reg(dut, reg_idx)
        if actual != expected:
            dut._log.error(f"❌ [FAIL] x{reg_idx}: 期望值 = {expected} ({hex(expected)}), 实际值 = {actual} ({hex(actual)})")
            dut._log.error(f"    └─ 原因信息: {msg}")
            failed = True
        else:
            dut._log.info(f"  [PASS] x{reg_idx} = {actual} ({hex(actual)})")

    assert not failed, "JAL 控制跳转对照测试失败！请查看上方标 ❌ 的具体错误原因。"
# 通过
@cocotb.test()
async def t_core_load_store(dut):
    """测试 Load/Store 访存操作。"""
    program = [
        i_type(16, 0, 0, 1),             # 0x00: addi x1, x0, 16
        i_type(0x12, 0, 0, 2),           # 0x04: addi x2, x0, 0x12
        s_type(0, 2, 1, 2),              # 0x08: sw x2, 0(x1) -> 写到地址 16 (word index 4)
        i_type(0, 1, 2, 3, opcode=0x03), # 0x0c: lw x3, 0(x1)
        i_type(1, 3, 0, 4),              # 0x10: addi x4, x3, 1
        s_type(4, 4, 1, 2),              # 0x14: sw x4, 4(x1) -> 写到地址 20 (word index 5)
        i_type(4, 1, 2, 5, opcode=0x03), # 0x18: lw x5, 4(x1)
        r_type(0, 5, 3, 0, 6),           # 0x1c: add x6, x3, x5
    ]
    fill_mem(dut, program)

    await setup_dut(dut)
    #await run_cycles(dut, 60)
    """
    for i in range(20):
        await RisingEdge(dut.clk)
        dut._log.info(
            f"Cycle {i}: PC={hex(dut.u_ifu.inst_PC.value)} "
            f"| WB_data={dut.u_decoder.u_regfile.wdata.value}"
        )
    """
    await setup_dut(dut)
    await run_cycles(dut, 60)
    
    assert read_reg(dut, 1) == 16
    assert read_reg(dut, 2) == 0x12
    assert read_reg(dut, 3) == 0x12
    assert read_reg(dut, 4) == 0x13
    assert read_reg(dut, 5) == 0x13
    assert read_reg(dut, 6) == 0x25
    assert read_dmem(dut, 4) == 0x12     # 地址 16 对应 word index 4
    assert read_dmem(dut, 5) == 0x13     # 地址 20 对应 word index 5


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
            HDL_SV_DIR / "core" / "core_new.sv",
        ]
        cls.hdl_top = "CoreTop"
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    def test_raw_stall(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_raw_stall_only",
        )
    
    def test_core_program(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_alu_stall_and_redirect",
        )

    

    def test_control_stall(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_control_stall_only",
        )

    def test_load_store(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_load_store",
        )

    def test_control_stall_jal_only(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_core_control_stall_jal_only",
        )
    