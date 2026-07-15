# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ran Ji
# 

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer
from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, setup_runner

async def setup_dut(dut):
    """初始化译码器测试平台"""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    # 给所有输入赋默认初值，避免 X 态传播
    dut.instruction.value = 0
    dut.PC.value = 0
    dut.extend_sel.value = 0
    dut.reg_write.value = 0
    dut.write_reg.value = 0
    dut.write_data.value = 0
    dut.rs1_data_bypass.value = 0
    dut.rs2_data_bypass.value = 0
    dut.ALU_result_writeback.value = 0

    # 复位 RegFile
    dut.rst.value = 1
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

# ==========================================================================
# 1. 基础指令解析测试 (R, I, U-type)
# ==========================================================================

@cocotb.test()
async def t_decode_R_type(dut):
    """测试 R-type 指令: add x5, x6, x10 (0x00a302b3)"""
    await setup_dut(dut)

    dut.instruction.value = 0x00a302b3
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0x33
    assert dut.rd.value == 5
    assert dut.funct3.value == 0
    assert dut.rs1.value == 6
    assert dut.rs2.value == 10
    assert dut.funct7.value == 0

@cocotb.test()
async def t_decode_I_type(dut):
    """测试 I-type 算术指令: addi x5, x6, -10 (0xff630293)"""
    await setup_dut(dut)
    dut.extend_sel.value = 0 # 0: I-type

    dut.instruction.value = 0xff630293  # addi x5, x6, -10
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0x13
    assert dut.rd.value == 5
    assert dut.rs1.value == 6
    # 采用新版 cocotb 推荐的方法进行有符号转换 (避免 DeprecationWarning)
    assert dut.extend_imm.value.to_signed() == -10

@cocotb.test()
async def t_decode_LUI(dut):
    """测试 U-type LUI 指令: lui x5, 0x12345 (0x123452b7)"""
    await setup_dut(dut)
    dut.extend_sel.value = 2 # 2: U-type (根据你的 32位 extend_imm 计算逻辑)

    dut.instruction.value = 0x123452b7
    await Timer(1, unit="ns")
    assert dut.opcode.value == 0x37
    assert dut.extend_imm.value == 0x12345000

@cocotb.test()
async def t_decode_AUIPC(dut):
    """测试 U-type AUIPC 指令: auipc x5, 0x12345 (0x12345297)"""
    await setup_dut(dut)
    dut.extend_sel.value = 2 # 2: U-type

    dut.instruction.value = 0x12345297
    await Timer(1, unit="ns")
    assert dut.opcode.value == 0x17
    assert dut.extend_imm.value == 0x12345000

# ==========================================================================
# 2. 存储 (S-type) 与 加载 (I-type Load) 指令测试
# ==========================================================================

@cocotb.test()
async def t_decode_S_type(dut):
    """测试 S-type 存储指令: sw x20, 24(x5) (0x0142ac23)"""
    await setup_dut(dut)
    dut.extend_sel.value = 1 # 1: S-type

    dut.instruction.value = 0x0142ac23
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0x23
    assert dut.rs1.value == 5
    assert dut.rs2.value == 20
    assert dut.extend_imm.value == 24

@cocotb.test()
async def t_decode_I_type_Load(dut):
    """测试 I-type 加载指令: lw x5, -4(x6) (0xffc32283)"""
    await setup_dut(dut)
    dut.extend_sel.value = 0 # 0: I-type

    dut.instruction.value = 0xffc32283
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0x03
    assert dut.rd.value == 5
    assert dut.rs1.value == 6
    assert dut.extend_imm.value.to_signed() == -4

# ==========================================================================
# 3. 分支跳转 (B-type / J-type) 及 PC 目标计算测试
# ==========================================================================

@cocotb.test()
async def t_decode_B_type(dut):
    """测试 B-type 条件跳转: beq x5, x6, offset=16 (0x01028863 -> 修正为 0x00628863)"""
    await setup_dut(dut)
    dut.PC.value = 0x2000

    # beq x5, x6, 16 (真正的指令码为 0x00628863)
    dut.instruction.value = 0x00628863
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0x63
    assert dut.rs1.value == 5
    assert dut.rs2.value == 6
    # 验证 B-type 跳转目标计算 (PC + 16)
    assert dut.branch_target.value == 0x2000 + 16

@cocotb.test()
async def t_decode_J_type(dut):
    """测试 J-type 无条件跳转: jal x1, offset=-2048 (0xffdff0ef)"""
    await setup_dut(dut)
    dut.PC.value = 0x4000

    # jal x1, -2048 (指令码为 0xffdff0ef)
    # 这里的 extend_sel 随便赋什么都可以，因为 JAL 目标地址是用独立的 JAL_target 线路计算的
    dut.instruction.value = 0xffdff0ef 
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0x6f
    assert dut.rd.value == 1
    # 验证跳转目标计算
    assert dut.JAL_target.value == 0x4000 - 4

# ==========================================================================
# 4. 数据通路与 1 位 Bypass（数据前传）测试
# ==========================================================================

@cocotb.test()
async def t_decode_with_reg_and_bypass(dut):
    """测试 RegFile 的常规读取，以及 1 位前传 Bypass 机制"""
    await setup_dut(dut)

    # 1. 写入 RegFile 初始背景值
    dut.u_regfile.regs[5].value = 0x1111_1111
    dut.u_regfile.regs[6].value = 0x2222_2222
    await Timer(1, unit="ns")

    # 解析指令: add x7, x5, x6 (0x006283b3)
    dut.instruction.value = 0x006283b3
    dut.rs1_data_bypass.value = 0
    dut.rs2_data_bypass.value = 0
    await Timer(1, unit="ns")

    # 无旁路时：正常从 RegFile 读取对应数据
    assert dut.rs1_data.value == 0x1111_1111
    assert dut.rs2_data.value == 0x2222_2222

    # 2. 模拟 RAW 冲突发生，拉高 1 位旁路信号
    dut.ALU_result_writeback.value = 0x9999_9999
    dut.rs1_data_bypass.value = 1 # 截胡 rs1
    dut.rs2_data_bypass.value = 0 # rs2 保持原样
    await Timer(1, unit="ns")

    # 验证截胡结果：rs1 应被前传数据覆盖，rs2 保持 RegFile 读取的数据
    assert dut.rs1_data.value == 0x9999_9999
    assert dut.rs2_data.value == 0x2222_2222
@cocotb.test()
async def t_decode_J_type_1(dut):
    """测试 J-type 无条件跳转: jal x1, offset=2048 (0x000000ef)"""
    await setup_dut(dut)
    dut.PC.value = 0x4000  # 16384

    # jal x1, 2048 (指令码为 0x000000ef)
    dut.instruction.value = 0x001000ef 
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0x6f
    assert dut.rd.value == 1
    
    # 打印一下，方便万一不对时在终端里直观debug
    dut._log.info(f"JAL_target calculated by DUT: {int(dut.JAL_target.value)}")
    
    # 验证跳转目标计算 (PC + 2048)
    assert dut.JAL_target.value == 0x4000 + 2048

# ==========================================================================
# 5. 仿真运行入口
# ==========================================================================

class TestDecoder_SV:
    sources = [
        HDL_SV_DIR / "core" / "decoder.sv",
        HDL_SV_DIR / "core" / "reg_file.sv"
    ]
    hdl_top = "Decoder"
    
    def test_decode_normal(self):
        cases = [
            "t_decode_R_type",
            "t_decode_I_type",
            "t_decode_LUI",
            "t_decode_AUIPC",
            "t_decode_S_type",
            "t_decode_I_type_Load",
            "t_decode_B_type",
            "t_decode_J_type_1",
            "t_decode_with_reg_and_bypass",
            "t_decode_J_type"
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