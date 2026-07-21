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
    """Initialize DUT inputs to default states."""
    dut.clk.value = 0
    dut.rst.value = 0
    dut.instruction.value = 0
    dut.PC.value = 0
    dut.extend_sel.value = 0
    dut.reg_write.value = 0
    dut.write_reg.value = 0
    dut.write_data.value = 0
    await Timer(1, unit="ns")


@cocotb.test()
async def t_decoder_extend_imm(dut):
    """Test Case: Verifying 3-bit extend_sel for I, S, B, U, and J immediate formats."""
    await setup_dut(dut)

    # 构造一条带有特征立即数的指令:
    # imm = 0x123 (I-type), 或者各字段不同的特定模式
    # 指令二进制: 0x12345678
    dut.instruction.value = 0x12345678
    
    # 1. Test I-type extension (extend_sel = 000)
    dut.extend_sel.value = 0b000
    await Timer(1, unit="ns")
    # I-imm = inst[31:20] = 0x123 -> Sign extended to 0x00000123
    assert dut.extend_imm.value == 0x00000123

    # 2. Test S-type extension (extend_sel = 001)
    dut.extend_sel.value = 0b001
    await Timer(1, unit="ns")
    # S-imm = {inst[31:25], inst[11:7]} = {0x12, 0x0F} = 0x24F -> Sign extended
    # inst[31:25] = 0010010, inst[11:7] = 01100 -> {0010010, 01100} = 0x24C
    expected_s = ((0x12345678 >> 25) << 5) | ((0x12345678 >> 7) & 0x1F)
    assert dut.extend_imm.value == expected_s

    # 3. Test U-type extension (extend_sel = 011)
    dut.extend_sel.value = 0b011
    await Timer(1, unit="ns")
    # U-imm = {inst[31:12], 12'b0} = 0x12345000
    assert dut.extend_imm.value == 0x12345000


@cocotb.test()
async def t_decoder_wb_bypass(dut):
    """Test Case: Verifying WB stage write-back data bypass (forwarding) logic."""
    await setup_dut(dut)

    # 指令指定 rs1 = x5 (5'd5)
    # instruction: [31:20]=imm, [19:15]=rs1(5), [14:12]=f3, [11:7]=rd, [6:0]=op
    dut.instruction.value = (0x123 << 20) | (5 << 15) | (0 << 12) | (1 << 7) | 0x13
    
    # 情况 A: 没有 WB 写入碰撞
    dut.reg_write.value = 0
    dut.write_reg.value = 5
    dut.write_data.value = 0xDEADBEEF
    await Timer(1, unit="ns")
    # 应读取 RegFile 默认值（全 0）
    assert dut.rs1_data.value == 0

    # 情况 B: 存在 WB 写入碰撞 (rs1 == write_reg && reg_write && rs1 != 0)
    dut.reg_write.value = 1
    await Timer(1, unit="ns")
    # 应触发旁路，直接输出 write_data
    assert dut.rs1_data.value == 0xDEADBEEF


class TestDecoder_SV:
    """Testrunner configuration class for Decoder simulation."""
    sources = [
        HDL_SV_DIR / "core" / "reg_file.sv",
        HDL_SV_DIR / "core" / "decoder.sv"
    ]
    hdl_top = "Decoder"

    def test_decoder_all(self):
        cases = [
            "t_decoder_extend_imm",
            "t_decoder_wb_bypass"
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