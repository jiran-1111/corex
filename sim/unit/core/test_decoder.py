# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ran Ji
"""
立即数范围： I/S： 12位 U：20 J：21
R-type（寄存器-寄存器运算）：
  31      25 24   20 19   15 14  12 11   7 6      0
 ┌─────────┬───────┬───────┬──────┬──────┬─────────┐
 │ funct7  │  rs2  │  rs1  │funct3│  rd  │ opcode  │
 └─────────┴───────┴───────┴──────┴──────┴─────────┘
   7 位       5 位    5 位   3 位   5 位    7 位

I-type（立即数运算 / 加载）：
  31              20 19   15 14  12 11   7 6      0
 ┌─────────────────┬───────┬──────┬──────┬─────────┐
 │  imm[11:0]      │  rs1  │funct3│  rd  │ opcode  │
 └─────────────────┴───────┴──────┴──────┴─────────┘
    12 位             5 位   3 位   5 位    7 位

U-type（高位立即数）：
  31                          12 11   7 6      0
 ┌─────────────────────────────┬──────┬─────────┐
 │       imm[31:12]            │  rd  │ opcode  │
 └─────────────────────────────┴──────┴─────────┘
           20 位                5 位    7 位
现在可以测试的指令：
- R-type:
ADD / SUB	
SLL	      
SLT	      
SLTU	  
XOR	      
SRL / SRA	
OR	       
AND	  
- I-type:     
ADDI
SLLI
SLTI
SLTIU
XORI
SRLI / SRAI
ORI
ANDI
- U-type:
LUI
AUIPC


寄存器-寄存器（R-type）
指令	语法	             操作	          说明
ADD	    add rd, rs1, rs2	rd ← rs1 + rs2	有符号加法
SUB	    sub rd, rs1, rs2	rd ← rs1 - rs2	有符号减法

立即数算术（I-type）
指令	语法	             操作	                  说明
ADDI	addi rd, rs1, imm	rd ← rs1 + sext(imm)	加立即数（12 位有符号）

高位立即数（U-type）
指令	语法	             操作	                  说明
LUI	    lui rd, imm	        rd ← imm << 12	        20 位立即数加载到高 20 位
AUIPC	auipc rd, imm	    rd ← PC + (imm << 12)	PC 相对高位加载

操作码（opcode）映射
opcode[6:0]	十六进制	格式	指令类别
0110111	    0x37	    U-type	LUI            ^^
0010111	    0x17	    U-type	AUIPC          ^^
1101111	    0x6F	    J-type	JAL
1100111	    0x67	    I-type	JALR
1100011	    0x63	    B-type	分支指令
0000011	    0x03	    I-type	加载指令
0100011	    0x23	    S-type	存储指令
0010011	    0x13	    I-type	立即数算术/逻辑  ^^
0110011	    0x33	    R-type	寄存器算术/逻辑  ^^
0001111	    0x0F	    I-type	FENCE
1110011	    0x73	    I-type	系统 / CSR

算术/逻辑指令（opcode = 0x13 / 0x33）
funct3	R-type 指令	I-type 指令
000	    ADD / SUB	ADDI
001	    SLL	        SLLI
010	    SLT	        SLTI
011	    SLTU	    SLTIU
100	    XOR	        XORI
101	    SRL / SRA	SRLI / SRAI
110	    OR	        ORI
111	    AND	        ANDI

"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, FallingEdge, Timer

from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner

async def setup_dut(dut):
    """Setup the decoder DUT"""
    clock = Clock(dut.clk, CLK_PERIOD_NS,unit="ns")
    cocotb.start_soon(clock.start())

    dut.instruction.value = 0
    dut.extend_sel.value = 0
    dut.reg_write.value = 0
    dut.write_reg.value = 0
    dut.write_data.value = 0

    dut.rst.value = 1
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

def clear_write_port(dut):
    """Clear the write port of the decoder DUT"""
    dut.reg_write.value = 0
    dut.write_reg.value = 0
    dut.write_data.value = 0

@cocotb.test()
async def t_decode_R_type(dut):
    await setup_dut(dut)

    # add x5, x6, x10 (0x00a302b3)
    dut.instruction.value = 0b0000_0000_1010_0011_0000_0010_1011_0011
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0b0110011
    assert dut.rd.value ==0b00101
    assert dut.funct3.value == 0b000
    assert dut.rs1.value == 0b00110
    assert dut.rs2.value == 0b01010
    assert dut.funct7.value == 0b0000

@cocotb.test()
async def t_decode_I_type(dut):
    await setup_dut(dut)
    dut.extend_sel.value = 0
    # addi x5, 10 (0x00a30293)
    dut.instruction.value = 0b0000_0000_1010_0011_0000_0010_1001_0011

    await ClockCycles(dut.clk, 1) 
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0b0010011
    assert dut.rd.value ==0b00101
    assert dut.extend_imm.value == 10

@cocotb.test()
async def t_decode_LUI(dut):
    await setup_dut(dut)

    # lui x5, 0x12345
    dut.extend_sel.value = 1
    dut.instruction.value = 0b0001_0010_0011_0100_0101_0010_1011_0111
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0b0110111
    assert dut.rd.value ==0b00101
    assert dut.extend_imm.value == 0b0001_0010_0011_0100_0101_0000_0000_0000

@cocotb.test()
async def t_decode_AUIPC(dut):
    await setup_dut(dut)

    # aipc x5, 0x12345 (0x00130293)
    dut.extend_sel.value = 1
    dut.instruction.value = 0b0001_0010_0011_0100_0101_0010_1001_0111
    await Timer(1, unit="ns")

    assert dut.opcode.value == 0b0010111
    assert dut.rd.value ==0b00101
    assert dut.extend_imm.value == 0b0001_0010_0011_0100_0101_0000_0000_0000

@cocotb.test()
async def t_decode_R_type_with_reg(dut):
    await setup_dut(dut)

    # 改写寄存器 x6 和 x10 的值
    dut.u_regfile.regs[6].value = 0xAAAA_BBBB
    dut.u_regfile.regs[10].value = 0x1111_2222
    
    # add x5, x6, x10 (0x00a302b3)
    dut.instruction.value = 0b0000_0000_1010_0011_0000_0010_1011_0011
    await Timer(1, unit="ns")

    assert dut.rs1.value == 6
    assert dut.rs2.value == 10

    assert dut.rs1_data.value == 0xAAAA_BBBB
    assert dut.rs2_data.value == 0x1111_2222

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
            "t_decode_R_type_with_reg"
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

