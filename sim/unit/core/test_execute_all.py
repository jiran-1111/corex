# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ran Ji

import cocotb
from cocotb.triggers import Timer
import random
from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner

async def setup_dut(dut):
    """Initialize DUT inputs to default states."""
    dut.clk.value = 0
    dut.rst.value = 0
    dut.stall.value = 0
    dut.ALU_Operation.value = 0
    dut.funct7.value = 0
    dut.funct3.value = 0
    dut.ALU_ASrc.value = 0
    dut.ALU_BSrc.value = 0
    dut.PC.value = 0
    dut.regRead_1.value = 0
    dut.regRead_2.value = 0
    dut.extend.value = 0
    dut.branch_op.value = 0  # 默认关闭分支使能
    await Timer(1, unit="ns")

def to_unsigned(val, width):
    """Truncate integer to unsigned with specified bit-width."""
    return val & ((1 << width) - 1)

def to_signed(val, width):
    """Convert unsigned value to Python signed integer."""
    val = val & ((1 << width) - 1)
    if val >= (1 << (width - 1)):
        return val - (1 << width)
    return val


@cocotb.test()
async def t_execute_mux_A(dut):
    """Test Case: Verifying Operand A Multiplexer (regRead_1 vs PC vs PC+4 vs ZERO)"""
    await setup_dut(dut)
    
    dut.ALU_Operation.value = 0b001  # I-Type (pass-through / ADDI behavior)
    dut.funct3.value = 0b000         # ADD
    dut.ALU_BSrc.value = 1           # Select 'extend'
    dut.extend.value = 0             # Add zero to pass operand_A directly to output
    
    dut.regRead_1.value = 0xAAAA_BBBB
    dut.PC.value = 0x1000_0000

    # 1. ALU_ASrc = 00 -> Select regRead_1
    dut.ALU_ASrc.value = 0b00
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0xAAAA_BBBB

    # 2. ALU_ASrc = 01 -> Select PC
    dut.ALU_ASrc.value = 0b01
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x1000_0000

    # 3. ALU_ASrc = 10 -> Select PC + 4
    dut.ALU_ASrc.value = 0b10
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x1000_0004

    # 4. ALU_ASrc = 11 -> Select 0 (LUI 特性)
    dut.ALU_ASrc.value = 0b11
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x0000_0000


@cocotb.test()
async def t_execute_mux_B(dut):
    """Test Case: Verifying Operand B Multiplexer (regRead_2 vs Immediate Extend)"""
    await setup_dut(dut)
    
    dut.ALU_Operation.value = 0b001  # I-Type
    dut.funct3.value = 0b000         # ADD
    dut.ALU_ASrc.value = 0b00        # Select regRead_1
    dut.regRead_1.value = 0          # Add zero to pass operand_B directly to output
    
    dut.regRead_2.value = 0x5555_6666
    dut.extend.value = 0x1234_5678

    # 1. ALU_BSrc = 0 -> Select regRead_2
    dut.ALU_BSrc.value = 0
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x5555_6666

    # 2. ALU_BSrc = 1 -> Select extend (Immediate)
    dut.ALU_BSrc.value = 1
    await Timer(1, unit="ns")
    assert dut.ALU_result.value == 0x1234_5678


@cocotb.test()
async def t_execute_random_ops(dut):
    """Test Case: Integrated Random Operations and Mux Logic Routing (Arithmetic/Logic/Shift/Compare)"""
    await setup_dut(dut)
    data_width = int(dut.DATA_WIDTH.value)
    addr_width = int(dut.ADDR_WIDTH.value)

    op_combinations = [
        # (ALU_Op, f3, f7)
        (0b000, 0b000, 0b0000000),  # ADD (R-Type)
        (0b000, 0b000, 0b0100000),  # SUB (R-Type)
        (0b000, 0b010, 0b0000000),  # SLT (R-Type)
        (0b000, 0b011, 0b0000000),  # SLTU (R-Type)
        (0b000, 0b100, 0b0000000),  # XOR (R-Type)
        (0b000, 0b110, 0b0000000),  # OR  (R-Type)
        (0b000, 0b111, 0b0000000),  # AND (R-Type)
        (0b001, 0b000, 0b0000000),  # ADDI (I-Type)
        (0b001, 0b010, 0b0000000),  # SLTI (I-Type)
        (0b001, 0b011, 0b0000000),  # SLTIU (I-Type)
        (0b001, 0b100, 0b0000000),  # XORI (I-Type)
        (0b000, 0b001, 0b0000000),  # SLL (R-Type Shift)
        (0b001, 0b101, 0b0000000),  # SRLI (I-Type Shift)
        (0b001, 0b101, 0b0100000)   # SRAI (I-Type Shift)
    ]

    for _ in range(150):
        alu_op, f3, f7 = random.choice(op_combinations)
        
        val_reg1 = random.randint(0, (1 << data_width) - 1)
        val_reg2 = random.randint(0, (1 << data_width) - 1)
        val_ext  = random.randint(0, (1 << data_width) - 1)
        val_pc   = random.randint(0, (1 << addr_width) - 4) & ~0x3

        asrc = random.choice([0b00, 0b01, 0b10])
        bsrc = random.choice([0, 1])

        dut.ALU_Operation.value = alu_op
        dut.funct3.value = f3
        dut.funct7.value = f7
        dut.ALU_ASrc.value = asrc
        dut.ALU_BSrc.value = bsrc
        dut.branch_op.value = 0  # 确保非分支指令期间 branch_op 为 0
        
        dut.regRead_1.value = val_reg1
        dut.regRead_2.value = val_reg2
        dut.extend.value = val_ext
        dut.PC.value = val_pc
        
        await Timer(1, unit="ns")

        expected_A = val_pc if asrc == 0b01 else (val_pc + 4 if asrc == 0b10 else (0 if asrc == 0b11 else val_reg1))
        expected_B = val_ext if bsrc == 1 else val_reg2

        shamt_width = (data_width).bit_length() - 1
        shamt = expected_B & ((1 << shamt_width) - 1)

        s_a = to_signed(expected_A, data_width)
        s_b = to_signed(expected_B, data_width)

        if (alu_op, f7) == (0b000, 0b0000000) and f3 == 0b000:    # ADD
            expected_res = expected_A + expected_B
        elif (alu_op, f7) == (0b000, 0b0100000) and f3 == 0b000:  # SUB
            expected_res = expected_A - expected_B
        elif f3 == 0b010:                                         # SLT / SLTI
            expected_res = 1 if s_a < s_b else 0
        elif f3 == 0b011:                                         # SLTU / SLTIU
            expected_res = 1 if expected_A < expected_B else 0
        elif f3 == 0b100:                                         # XOR / XORI
            expected_res = expected_A ^ expected_B
        elif f3 == 0b110:                                         # OR / ORI
            expected_res = expected_A | expected_B
        elif f3 == 0b111:                                         # AND / ANDI
            expected_res = expected_A & expected_B
        elif f3 == 0b001:                                         # SLL / SLLI
            expected_res = expected_A << shamt
        elif f3 == 0b101 and f7 == 0b0000000:                     # SRL / SRLI
            expected_res = expected_A >> shamt
        elif f3 == 0b101 and f7 == 0b0100000:                     # SRA / SRAI
            expected_res = s_a >> shamt
        else:
            expected_res = expected_A + expected_B

        expected_res = to_unsigned(expected_res, data_width)
        
        assert dut.ALU_result.value == expected_res, \
            f"Failed: OP={alu_op:b} F3={f3:b} A={expected_A:x} B={expected_B:x} Got={int(dut.ALU_result.value):x} Exp={expected_res:x}"
        assert dut.branch_taken.value == 0, "Error: non-branch instruction triggered branch_taken!"


@cocotb.test()
async def t_execute_branch_ops(dut):
    """Test Case: Verifying B-Type Branches and J-Type Jump routing and results"""
    await setup_dut(dut)
    data_width = int(dut.DATA_WIDTH.value)

    # (funct3, name)
    branches = [
        (0b000, "BEQ"), (0b001, "BNE"), (0b100, "BLT"), 
        (0b101, "BGE"), (0b110, "BLTU"), (0b111, "BGEU")
    ]

    for f3, name in branches:
        for trial in range(10): # 每个分支指令测试 10 组随机数据
            val_reg1 = random.randint(0, (1 << data_width) - 1)
            val_reg2 = random.randint(0, (1 << data_width) - 1)
            
            # 50% 概率让它们相等，用来针对性测试 BEQ/BNE
            if random.random() < 0.5:
                val_reg2 = val_reg1

            s_a, s_b = to_signed(val_reg1, data_width), to_signed(val_reg2, data_width)

            # 计算黄金参考模型
            if f3 == 0b000:   taken = (val_reg1 == val_reg2)
            elif f3 == 0b001: taken = (val_reg1 != val_reg2)
            elif f3 == 0b100: taken = (s_a < s_b)
            elif f3 == 0b101: taken = (s_a >= s_b)
            elif f3 == 0b110: taken = (val_reg1 < val_reg2)
            elif f3 == 0b111: taken = (val_reg1 >= val_reg2)

            # 激励输入
            dut.ALU_Operation.value = 0b010  # B-Type Operations
            dut.funct3.value = f3
            dut.ALU_ASrc.value = 0b00        # rs1
            dut.ALU_BSrc.value = 0          # rs2
            dut.regRead_1.value = val_reg1
            dut.regRead_2.value = val_reg2
            
            # 测试情况 1：控制信号 branch_op 有效
            dut.branch_op.value = 1
            await Timer(1, unit="ns")
            assert dut.branch_taken.value == int(taken), f"Failed {name}: A={val_reg1:x}, B={val_reg2:x}, Exp={taken}, Got={dut.branch_taken.value}"

            # 测试情况 2：如果 branch_op 被拉低（如流水线气泡），绝不能跳转
            dut.branch_op.value = 0
            await Timer(1, unit="ns")
            assert dut.branch_taken.value == 0, f"Failed {name} safety lock: branch_op=0 but branch_taken=1!"


@cocotb.test()
async def t_execute_jalr_target(dut):
    """Test Case: Verifying JALR target address calculation and bit0 clearing"""
    await setup_dut(dut)
    
    # 设置测试数据（带有奇数地址，校验 bit[0] 清零特性）
    dut.regRead_1.value = 0x1000_0003  # 最低位为 1
    dut.extend.value    = 0x0000_0005  # 最低位为 1
    # 期望结果: (0x1000_0003 + 0x0000_0005) & ~1 = 0x1000_0008 & ~1 = 0x1000_0008
    
    dut.ALU_Operation.value = 0b011  # JAL / JALR
    dut.ALU_ASrc.value = 0b10        # 写回 rd 的内容选择 PC+4
    dut.PC.value = 0x2000_0000
    
    await Timer(1, unit="ns")
    
    # 1. 验证写回寄存器的 ALU 输出为 PC+4
    assert dut.ALU_result.value == 0x2000_0004, f"JAL/JALR ALU Output failed, got {hex(dut.ALU_result.value)}"
    # 2. 验证 JALR 计算出的跳转目标地址是否清除了最低位
    assert dut.JALR_target.value == 0x1000_0008, f"JALR target calculation failed, got {hex(dut.JALR_target.value)}"


class TestExecute_SV:
    """Testrunner configuration class for Execution Unit SystemVerilog simulation."""
    sources = [
        HDL_SV_DIR / "core" / "ALU.sv",
        HDL_SV_DIR / "core" / "execute.sv"
    ]
    hdl_top = "execute"

    def test_execute_normal(self):
        """Execute all target unit tests and randomized test suites."""
        cases = [
            "t_execute_mux_A",
            "t_execute_mux_B",
            "t_execute_random_ops",
            "t_execute_branch_ops",
            "t_execute_jalr_target"  # 新增的 JALR 地址校验测试点
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