# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ran Ji

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, FallingEdge, Timer

from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, setup_runner

# Default configuration (32-bit DATA_WIDTH)
DEFAULT_WORD_BYTES = 4


async def setup_ifu_dut(dut, start_pc: int = 0x0000_0000):
    """Setup IFU DUT with clock, default signals, and reset."""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    # Initialize input signals to default state
    dut.rst.value = 1
    dut.start.value = 0
    dut.stall.value = 0
    dut.program_address.value = start_pc

    # Initialize new control inputs to avoid undefined (X) states
    dut.JAL_target.value = 0
    dut.JALR_target.value = 0
    dut.branch_target.value = 0
    dut.pc_sel_execute.value = 0
    dut.branch_taken.value = 0

    await ClockCycles(dut.clk, 1)
    dut.rst.value = 0
    await RisingEdge(dut.clk)


def fill_ifu_imem(dut, words: list[int], start: int = 0):
    """Fill the instantiated internal instruction memory directly via hierarchical path, 
    automatically handling DATA_WIDTH (32-bit vs 64-bit) compatibility."""
    # 动态获取当前仿真实例中物理内存单元的位宽
    mem_width = len(dut.IMem.imem.mem[0])
    
    if mem_width == 64:
        # 64位宽下，一个 memory 单元存放 2 个 32位指令 (低32位和高32位)
        for i in range(0, len(words), 2):
            low_word = words[i]
            high_word = words[i+1] if (i+1) < len(words) else 0
            combined_val = (high_word << 32) | low_word
            dut.IMem.imem.mem[start + (i // 2)].value = combined_val
    else:
        # 默认 32 位宽
        for i, word in enumerate(words):
            dut.IMem.imem.mem[start + i].value = word


def is_pc_correct(dut, expected_pc: int) -> bool:
    """Check if the current instruction PC matches the expected value safely."""
    return dut.inst_PC.value.to_unsigned() == expected_pc


@cocotb.test()
async def t_ifu_reset(dut):
    """Test IFU reset state and steady state at the moment of reset deassertion."""
    await setup_ifu_dut(dut, start_pc=0x1000)
    
    assert is_pc_correct(dut, 0x1000)
    assert dut.fetch.value == 0


@cocotb.test()
async def t_ifu_normal_sequential(dut):
    """Test standard sequential instruction fetch (PC + 4) with PC & Instruction synchronization."""
    instructions = [
        0x00100093, 
        0x00200113,
        0x00300193, 
        0x00400213  
    ]
    fill_ifu_imem(dut, instructions, start=0)

    await setup_ifu_dut(dut, start_pc=0x0)
    dut.start.value = 1
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk) #PC_reg 成功被写入了 program_address（0x0），fetch 成功被拉高为 1。
    
    dut.start.value = 0

    data_width = dut.DATA_WIDTH.value

    for i in range(4):
        dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
        await RisingEdge(dut.clk)
        await Timer(1, unit="ps")
        
        expected_pc = i * 4
        expected_inst = instructions[i]
        
        current_pc = dut.inst_PC.value.to_unsigned()
        current_inst = dut.instruction.value.to_unsigned()

        assert current_pc == expected_pc

        # 默认 32 位总线，直接比对整个字
        assert current_inst == expected_inst
            
        assert dut.fetch.value == 1


@cocotb.test()
async def t_ifu_stall_long_duration(dut):
    """Test long duration stall holding capability and successful resumption."""
    instructions = [0x11111111, 0x22222222, 0x33333333, 0x44444444]
    fill_ifu_imem(dut, instructions, start=0)

    await setup_ifu_dut(dut, start_pc=0x0)

    dut.start.value = 1
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk) # inst_pc=0x0 pc_reg=0x0
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    dut.start.value = 0
    await RisingEdge(dut.clk) # inst_pc=0x0 pc_reg=0x4
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    
    # Assert stall on the falling edge
    await FallingEdge(dut.clk)
    dut.stall.value = 1
    await RisingEdge(dut.clk) # inst_pc = 0x0 pc_reg=0x4 inst_PC_reg <= inst_PC_reg;
    
    
    locked_pc = dut.inst_PC.value.to_unsigned()
    assert dut.PC_reg.value.to_unsigned() == 0x4
    assert locked_pc == 0x0
    # Hold stall for multiple cycles
    await ClockCycles(dut.clk, 10)
    assert is_pc_correct(dut, locked_pc)

    # Deassert stall signal
    await FallingEdge(dut.clk)
    dut.stall.value = 0
    await RisingEdge(dut.clk)

    # Delta delay to allow signals to propagate after the clock edge
    await Timer(1, unit="ps")

    expected_next_pc = locked_pc + 4
    assert is_pc_correct(dut, expected_next_pc)


@cocotb.test()
async def t_ifu_normal_sequential_1(dut):
    """Test standard sequential instruction fetch (PC + 4) with PC & Instruction synchronization."""
    instructions = [
        0x00100093, 
        0x00200113,
        0x00300193, 
        0x00400213  
    ]
    fill_ifu_imem(dut, instructions, start=0)

    await setup_ifu_dut(dut, start_pc=0x0)
    dut.start.value = 1
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk) #PC_reg 成功被写入了 program_address（0x0），fetch 成功被拉高为 1。
    
    dut.start.value = 0

    data_width = dut.DATA_WIDTH.value

    
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")

@cocotb.test()
async def t_ifu_reset_during_run(dut):
    """Test unexpected synchronous/asynchronous reset assertion during running state."""
    instructions = [
        0x00100093, 
        0x00200113,
        0x00300193, 
        0x00400213  
    ]
    fill_ifu_imem(dut, instructions, start=0)
    
    await setup_ifu_dut(dut, start_pc=0x0)

    dut.start.value = 1
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk) # inst_pc=0x0 pc_reg=0x0
    
    dut.start.value = 0

    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk) # inst_pc=0x0 pc_reg=0x4
    await Timer(1, unit="ps")
    dut._log.info(f"pc_reg={dut.PC_reg.value}, instr_pc={dut.inst_PC.value}, ")
    await RisingEdge(dut.clk) # inst_pc=0x4 pc_reg=0x8
    await Timer(1, unit="ps")


    assert dut.PC_reg.value.to_unsigned() == 0x8
    assert dut.inst_PC.value.to_unsigned() == 0x4
    
    # Trigger reset during execution
    
    await FallingEdge(dut.clk)
    dut.rst.value = 1
    dut.program_address.value = 0x2000
    
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    
    assert is_pc_correct(dut, 0x2000)
    assert dut.fetch.value == 0
    


@cocotb.test()
async def t_ifu_multiple_starts(dut):
    """Test repeated start pulses given during runtime for PC redirection."""
    instructions = [0x10, 0x20, 0x30, 0x40]
    fill_ifu_imem(dut, instructions, start=0)
    await setup_ifu_dut(dut, start_pc=0x0)

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    await ClockCycles(dut.clk, 2) 

    # Re-direct address with another start pulse
    await FallingEdge(dut.clk)
    assert dut.inst_PC.value.to_unsigned() ==  0x4
    dut.program_address.value = 0x4
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
   
    await Timer(1, unit="ps")
    assert is_pc_correct(dut, 0x4)


"""
R-type:
- add x12,x10,x11    00b50633
- xor x15,x13,x14    00e6c7b3

I-type:
- addi x5,x5,4       00428293
- lw x10,8(x11)      0085a503

S-type:
- sw x10, 16(x9)     00a4a823

B-type:
- beq x10, x11, 16   00b50863
- bne x10, x11, -8   fe051ce3

U-type:
- lui x10, 0x2000    02000537

J-type:
- jal x1, 2000       7d0000ef
"""

@cocotb.test()
async def t_ifu_J_type(dut):
    """Test for J-type instructions (JAL and JALR) pipeline behavior"""
    
    instructions = [0] * 200
    instructions[0] = 0x00428293  # 0x00: addi
    instructions[1] = 0x7d0000ef  # 0x04: jal
    instructions[2] = 0x00e6c7b3  # 0x08: xor
    instructions[128] = 0x000500e7 # 0x200: jalr (JAL 靶点)
    instructions[130] = 0x00b50633 # 0x208: add (JALR 靶点)
    instructions[131] = 0x00428293  # 0x21c: addi

    fill_ifu_imem(dut, instructions, start=0)
    await setup_ifu_dut(dut, start_pc=0x0)
    
    dut.stall.value = 0
    dut.pc_sel_execute.value = 0
    dut.branch_taken.value = 0
    dut.JAL_target.value = 0
    dut.JALR_target.value = 0

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns') 
    assert dut.inst_PC.value == 0x00
    assert dut.PC_reg.value == 0x04
    assert dut.instruction.value == 0x00428293
    
    dut.pc_sel_execute.value = 2  # 选择 JAL_target
    dut.JAL_target.value = 0x200
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.PC_reg.value == 0x200
    assert dut.inst_PC.value == 0x04, f"Expected inst_PC 0x04, got {hex(int(dut.inst_PC.value))}"
    assert dut.instruction.value == 0x7d0000ef

    dut.pc_sel_execute.value = 3  # JALR
    dut.JALR_target.value = 0x208
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns') 
    # 此时指令从 IMem 返回，物理地址对应 0x200
    assert dut.inst_PC.value == 0x200
    assert dut.PC_reg.value == 0x208
    assert dut.instruction.value == 0x000500e7

    dut.pc_sel_execute.value = 0  
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')

    assert dut.inst_PC.value == 0x208  # 成功跳到 0x208
    assert dut.instruction.value == 0x00b50633
    
    assert dut.PC_reg.value == 0x20c
    dut._log.info(f"inst_PC={hex(int(dut.inst_PC.value))}, PC_reg={hex(int(dut.PC_reg.value))}, instruction={hex(int(dut.instruction.value))}")
    dut._log.info("J-type (JAL/JALR) Test PASSED!")


@cocotb.test()
async def t_ifu_J_type_real(dut):
    """Test for J-type instructions (JAL and JALR) pipeline behavior"""
    
    instructions = [0] * 200
    instructions[0] = 0x00428293  # 0x00: addi
    instructions[1] = 0x7d0000ef  # 0x04: jal
    instructions[2] = 0x00e6c7b3  # 0x08: xor
    instructions[128] = 0x000500e7 # 0x200: jalr (JAL 靶点)
    instructions[130] = 0x00b50633 # 0x208: add (JALR 靶点)
    instructions[131] = 0x00428293  # 0x21c: addi

    fill_ifu_imem(dut, instructions, start=0)
    await setup_ifu_dut(dut, start_pc=0x0)
    
    dut.stall.value = 0
    dut.pc_sel_execute.value = 0
    dut.branch_taken.value = 0
    dut.JAL_target.value = 0
    dut.JALR_target.value = 0

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns') 
    assert dut.inst_PC.value == 0x00
    assert dut.PC_reg.value == 0x04
    #assert dut.instruction.value == 0x00428293
    
    #dut.pc_sel_execute.value = 2  # 选择 JAL_target
    #dut.JAL_target.value = 0x200
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.PC_reg.value == 0x08
    assert dut.inst_PC.value == 0x04, f"Expected inst_PC 0x04, got {hex(int(dut.inst_PC.value))}"

    dut.pc_sel_execute.value = 2  # 选择 JAL_target
    dut.JAL_target.value = 0x200

    await RisingEdge(dut.clk)
    await Timer(1, unit='ns') 
    assert dut.inst_PC.value == 0x08
    assert dut.PC_reg.value == 0x200

    dut.pc_sel_execute.value = 0
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')

    assert dut.inst_PC.value == 0x200  
    assert dut.PC_reg.value == 0x204

    dut.pc_sel_execute.value = 3  # JALR
    dut.JALR_target.value = 0x208

    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.inst_PC.value == 0x204  
    assert dut.PC_reg.value == 0x208

    dut.pc_sel_execute.value = 0  # JALR

    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.inst_PC.value == 0x208  
    assert dut.PC_reg.value == 0x20c

    
    
    dut._log.info(f"inst_PC={hex(int(dut.inst_PC.value))}, PC_reg={hex(int(dut.PC_reg.value))}, instruction={hex(int(dut.instruction.value))}")
    dut._log.info("J-type (JAL/JALR) Test PASSED!")

@cocotb.test()
async def t_ifu_B_type(dut):
    """Test for branch instructions (BEQ, BNE) pipeline behavior"""
    
    instructions = [0] * 200
    instructions[0] = 0x00b50863  # 0x00: beq x10, x11, 16
    instructions[1] = 0x00428293  # 0x04: addi
    
    # 0x10 (beq 靶点)
    instructions[4] = 0xfe051ce3  # 0x10: bne x10, x11, -8
    instructions[5] = 0x00e6c7b3  # 0x14: xor

    fill_ifu_imem(dut, instructions, start=0)
    await setup_ifu_dut(dut, start_pc=0x0)
    
    dut.stall.value = 0
    dut.pc_sel_execute.value = 0
    dut.branch_taken.value = 0
    dut.branch_target.value = 0

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    # ========================================================
    # 步骤一：测试 BEQ 发生跳转
    # ========================================================
    dut.pc_sel_execute.value = 1  
    dut.branch_taken.value = 1          
    dut.branch_target.value = 0x10
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.inst_PC.value == 0x00
    assert dut.PC_reg.value == 0x10
    assert dut.instruction.value == 0x00b50863 
    
    
    dut.pc_sel_execute.value = 1
    dut.branch_taken.value = 0
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.inst_PC.value == 0x10, f"Branch target failed! Got {hex(int(dut.inst_PC.value))}"
    assert dut.PC_reg.value == 0x14

    dut._log.info("B-type (BEQ/BNE) Test PASSED!")

@cocotb.test()
async def t_ifu_R_type(dut):
    """Test R-type instructions : ADD, SUB"""
    
    instructions = [0] * 10
    instructions[0] = 0x00b50633  # 0x00: add x12, x10, x11
    instructions[1] = 0x40b50633  # 0x04: sub x12, x10, x11

    fill_ifu_imem(dut, instructions, start=0)
    await setup_ifu_dut(dut, start_pc=0x0)
    
    dut.stall.value = 0
    dut.pc_sel_execute.value = 0
    dut.branch_taken.value = 0

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.inst_PC.value == 0x00
    assert dut.PC_reg.value == 0x04
    assert dut.instruction.value == 0x00b50633
    
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.inst_PC.value == 0x04
    assert dut.PC_reg.value == 0x08
    assert dut.instruction.value == 0x40b50633
    
    dut._log.info("R-type Test PASSED!")

@cocotb.test()
async def t_ifu_I_type(dut):
    """Test I-type instructions : ADDI"""
    
    instructions = [0] * 10
    instructions[0] = 0x00428293  # 0x00: addi x5, x5, 4
    instructions[1] = 0x0085a503  # 0x04: lw x10, 8(x11)

    fill_ifu_imem(dut, instructions, start=0)
    await setup_ifu_dut(dut, start_pc=0x0)
    
    dut.stall.value = 0
    dut.pc_sel_execute.value = 0
    dut.branch_taken.value = 0

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.inst_PC.value == 0x00
    assert dut.PC_reg.value == 0x04
    assert dut.instruction.value == 0x00428293

    await RisingEdge(dut.clk)
    await Timer(1, unit='ns')
    assert dut.inst_PC.value == 0x04
    assert dut.PC_reg.value == 0x08
    assert dut.instruction.value == 0x0085a503
    
    dut._log.info("I-type Test PASSED!")


class TestIfu_SV:

    sources = [
        HDL_SV_DIR / "core" / "ibus_if.sv",
        HDL_SV_DIR / "core" / "imem.sv",
        HDL_SV_DIR / "core" / "ifu.sv",
    ]
    hdl_top = "Ifu"
        
    def test_ifu_core(self):
        cases = [
            "t_ifu_reset",
            "t_ifu_normal_sequential",
            "t_ifu_stall_long_duration",
            "t_ifu_reset_during_run",
            "t_ifu_multiple_starts",
            "t_ifu_normal_sequential_1",
            "t_ifu_J_type",
            "t_ifu_B_type",
            "t_ifu_R_type",
            "t_ifu_I_type",
            "t_ifu_J_type_real"  # 加入控制流分支/跳转测试
        ]
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
        )
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )

    def test_ADDR_WIDTH_64b(self):
        """Verify hardware compatibility when expanded to a 64-bit data bus width."""
        parameters = {
            "ADDR_WIDTH": 64,
        }
        runner = setup_runner(
            sources=self.sources,
            hdl_toplevel=self.hdl_top,
            parameters=parameters,
        )
        cases = ["t_ifu_reset", "t_ifu_normal_sequential","t_ifu_J_type"]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )