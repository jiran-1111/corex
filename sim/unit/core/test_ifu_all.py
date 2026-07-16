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
    dut.branch.value = 0

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
    await RisingEdge(dut.clk)
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


@cocotb.test()
async def t_ifu_control_flow(dut):
    """Test JAL, JALR, Branch Taken, and Branch Not Taken behaviors with proper handshake."""
    # 填充一段模拟指令
    instructions = [i * 0x1111 for i in range(20)]
    fill_ifu_imem(dut, instructions, start=0)
    
    # 启动 IFU
    await setup_ifu_dut(dut, start_pc=0x0)
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    # 统一的辅助等待函数（保证退出时处于 ack 沿的 delta cycle 内）
    # =========================================================================
    # 带有详细 Debug 日志的辅助函数
    # =========================================================================
    async def wait_for_handshake_and_check(expected_pc, step_name=""):
        dut._log.info(f"--- [DEBUG START: {step_name}] Expecting PC: {hex(expected_pc)} ---")
        
        # 打印当前即时状态
        dut._log.info(
            f"INIT STATUS: clk={dut.clk.value}, stall={dut.stall.value}, "
            f"ack={dut.IMem.ack.value}, inst_PC={hex(dut.inst_PC.value if dut.inst_PC.value.is_resolvable else 0)}, "
            f"pc_sel={dut.pc_sel_execute.value}, branch={dut.branch.value}"
        )
        
        for cycle in range(1, 11):
            await RisingEdge(dut.clk)
            await Timer(1, unit="ps") # 避开采样竞争
            
            curr_pc = dut.inst_PC.value if dut.inst_PC.value.is_resolvable else 0
            curr_ack = dut.IMem.ack.value
            curr_stall = dut.stall.value
            
            dut._log.info(
                f"  Cycle {cycle}: inst_PC={hex(curr_pc)}, "
                f"ack={curr_ack}, stall={curr_stall}, "
                f"ibus_addr={hex(dut.IMem.addr.value if dut.IMem.addr.value.is_resolvable else 0)}"
            )
            
            if curr_ack == 1 and curr_stall == 0:
                dut._log.info(f"  --> Handshake detected at Cycle {cycle}!")
                # 如果当前 PC 已经跑过了我们期望的值，提前打印警告
                if curr_pc != expected_pc:
                    dut._log.warning(
                        f"  [MISMATCH DETECTED] Handshake captured PC {hex(curr_pc)}, but we wanted {hex(expected_pc)}"
                    )
                break
        
        assert dut.inst_PC.value == expected_pc, \
            f"[{step_name}] Expected inst_PC to be {hex(expected_pc)}, got {hex(dut.inst_PC.value)}"
        dut._log.info(f"--- [DEBUG END: {step_name}] PASSED ---\n")

    # =========================================================================
    # 1. 验证 JAL 无条件跳转 (0x1C)
    # =========================================================================
    dut.JAL_target.value = 0x1C
    dut.pc_sel_execute.value = 0x2  # 选中 JAL
    await wait_for_handshake_and_check(0x1C, "JAL to 0x1C")
    
    # =========================================================================
    # 2. 恢复顺序取指 (0x20)
    # =========================================================================
    dut.pc_sel_execute.value = 0x0  
    await RisingEdge(dut.clk) 
    await wait_for_handshake_and_check(0x20, "Recover to 0x20")

    # =========================================================================
    # 3. 验证 Branch Taken (跳转到 0x08)
    # =========================================================================
    dut.branch_target.value = 0x08
    dut.branch.value = 1
    dut.pc_sel_execute.value = 0x1  # 选中 Branch
    await wait_for_handshake_and_check(0x08, "Branch Taken to 0x08")

    # =========================================================================
    # 4. 验证 Branch Not Taken (期望顺序递增至 0x0C)
    # =========================================================================
    dut.branch.value = 0            # 分支不成立
    dut.pc_sel_execute.value = 0x0  # 依然选中 Branch 译码
    
    # 这里我们先保留这个 RisingEdge，看看日志输出中它是否导致跳过了 0x0C
    await RisingEdge(dut.clk)
    await wait_for_handshake_and_check(0x0C, "Branch Not Taken to 0x0C")

    # =========================================================================
    # 5. 验证 JALR 间接跳转 (0x14)
    # =========================================================================
    dut.JALR_target.value = 0x14
    dut.pc_sel_execute.value = 0x3  # 选中 JALR
    await wait_for_handshake_and_check(0x14, "JALR to 0x14")
@cocotb.test()
async def t_ifu_control_flow_robust(dut):
    """
    极深度的 IFU 控制流测试：
    1. 验证 JAL/JALR/Branch 时的 inst_PC 与 instruction 严格同步。
    2. 验证 Stall 状态下控制流信号被阻断/保持的特性。
    """
    # 填充特征分明的指令数据：PC = i * 4, 指令 = i * 0x1111 (0x0, 0x1111, 0x2222, ...)
    instructions = [i * 0x1111 for i in range(20)]
    fill_ifu_imem(dut, instructions, start=0)
    
    # 启动
    await setup_ifu_dut(dut, start_pc=0x0)
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    # 初始化控制信号
    dut.pc_sel_execute.value = 0
    dut.branch.value = 0
    dut.stall.value = 0

    # 辅助断言函数：等待握手并同时检验 PC 和 指令内容
    async def assert_pc_and_instruction(expected_pc, step_name):
        # 等待一个握手完成 (imem_ack 且没有被 stall)
        while True:
            await RisingEdge(dut.clk)
            await Timer(1, "ps") # 避开采样竞争
            if dut.IMem.ack.value == 1 and dut.stall.value == 0:
                break
        
        actual_pc = dut.inst_PC.value.to_unsigned()
        actual_inst = dut.instruction.value.to_unsigned()
        expected_inst = instructions[expected_pc // 4]
        
        dut._log.info(f"[{step_name}] Verified: PC={hex(actual_pc)}, Inst={hex(actual_inst)}")
        
        assert actual_pc == expected_pc, f"[{step_name}] PC 错位！期望 {hex(expected_pc)}, 实际 {hex(actual_pc)}"
        assert actual_inst == expected_inst, f"[{step_name}] 指令错位！期望 {hex(expected_inst)}, 实际 {hex(actual_inst)}"

    # =========================================================================
    # 场景 1：标准 JAL 跳转到 0x1C (第 7 条指令)
    # =========================================================================
    dut._log.info("--- 正在测试: JAL 跳转到 0x1C ---")
    dut.JAL_target.value = 0x1C
    dut.pc_sel_execute.value = 2  # 选中 JAL
    
    # 在这个时钟沿，跳转目标被写入 PC_reg
    await RisingEdge(dut.clk)
    # 撤销跳转信号，模拟流水线只发一个周期的跳转使能
    dut.pc_sel_execute.value = 0 
    
    # 验证跳转后的 PC 及其指令 (0x1C 对应的应该是 7 * 0x1111 = 0x7777)
    await assert_pc_and_instruction(0x1C, "JAL_0x1C")

    # =========================================================================
    # 场景 2：顺序执行一拍 (应到 0x20，对应指令 8 * 0x1111 = 0x8888)
    # =========================================================================
    dut._log.info("--- 正在测试: 跳转后的恢复顺序执行 ---")
    await assert_pc_and_instruction(0x20, "SEQ_0x20")

    # =========================================================================
    # 场景 3：[核心杀手锏] 跳转遭遇 Stall！
    # 如果发出跳转的同时，流水线被 Stall 了，硬件绝对不能更新
    # =========================================================================
    dut._log.info("--- 正在测试: 跳转与 Stall 并存 (跳转不应立即生效) ---")
    dut.branch_target.value = 0x08
    dut.branch.value = 1
    dut.pc_sel_execute.value = 1  # 试图 Branch 跳转到 0x08
    dut.stall.value = 1           # 同时发生 Stall！

    # 走两个时钟，因为有 Stall，PC 和 inst_PC 应当保持在原来的 0x20 纹丝不动
    for _ in range(2):
        await RisingEdge(dut.clk)
        await Timer(1, "ps")
        assert dut.inst_PC.value.to_unsigned() == 0x20, "错误！在 Stall 期间，inst_PC 被非法修改了！"
        assert dut.instruction.value.to_unsigned() == 0x8888, "错误！在 Stall 期间，指令数据被污染了！"

    # 释放 Stall 并在同一个时钟周期释放跳转控制信号（模拟流水线清空/恢复）
    dut.stall.value = 0
    await RisingEdge(dut.clk)
    dut.pc_sel_execute.value = 0
    dut.branch.value = 0

    # 此时跳转应该成功生效，进入 0x08 (对应指令 2 * 0x1111 = 0x2222)
    await assert_pc_and_instruction(0x08, "Stalled_Branch_0x08")

class TestIfu_SV:

    sources = [
        HDL_SV_DIR / "core" / "ibus_if.sv",
        HDL_SV_DIR / "core" / "imem.sv",
        HDL_SV_DIR / "core" / "ifu_new.sv",
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
            "t_ifu_control_flow"  # 加入控制流分支/跳转测试
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
        cases = ["t_ifu_reset", "t_ifu_normal_sequential","t_ifu_control_flow"]
        runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase=cases,
        )