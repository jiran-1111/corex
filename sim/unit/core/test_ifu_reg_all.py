import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, FallingEdge, ReadOnly, RisingEdge, Timer
from ..cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner

NOP = 0x0000_0013

# -----------------------------------------------------------------------------
# 辅助函数：将指令列表装载到 IMem 内部
# -----------------------------------------------------------------------------
def load_imem(dut, program):
    """把指令数组灌入 IMemTop 内部的 mem 存储器中"""
    for idx, inst in enumerate(program):
        # 兼容单独模块测试 (u_ifu.IMem) 或 顶层测试
        if hasattr(dut, "u_ifu"):
            dut.u_ifu.IMem.imem.mem[idx].value = inst
        else:
            dut.IMem.imem.mem[idx].value = inst

# -----------------------------------------------------------------------------
# 辅助函数：初始化控制端口（模拟 EX 阶段和 Hazard Unit）
# -----------------------------------------------------------------------------
async def init_frontend_signals(dut):
    dut.rst.value = 1
    dut.start.value = 0
    dut.stall.value = 0
    dut.flush.value = 0
    dut.program_address.value = 0
    
    # EX 阶段反馈控制接口清零
    dut.ex_pc_sel.value = 0        # 3'b000: 默认 PC + 4
    dut.ex_branch_taken.value = 0
    dut.ex_branch_target.value = 0
    dut.ex_jal_target.value = 0
    dut.ex_jalr_target.value = 0

    # 启动 10ns 时钟周期
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    
    # 复位 3 个周期
    await ClockCycles(dut.clk, 3)
    await FallingEdge(dut.clk)
    dut.rst.value = 0
    await FallingEdge(dut.clk)

# -----------------------------------------------------------------------------
# 测试用例：IF + IMem + IF/ID PipelineReg 控制与跳转流测试
# -----------------------------------------------------------------------------
@cocotb.test()
async def t_frontend_control_and_pipeline(dut):
    """测试 IFU + IMem + IF/ID Reg 的流水线行为、Stall、Flush 和分支跳转"""
    
    program = [
        0x00000463,  # 0x00: beq x0, x0, 8       (Branch Target -> 0x08)
        0x00100493,  # 0x04: addi x9, x0, 1     (Skipped)
        0x00500113,  # 0x08: addi x2, x0, 5     (Branch 到达点)
        0x00101663,  # 0x0C: bne x0, x0, 8      (Not taken)
        0x00600193,  # 0x10: addi x3, x0, 6
        0x0080026f,  # 0x14: jal x4, 0x1C       (JAL Target -> 0x1C)
        0x00500293,  # 0x18: addi x5, x0, 88    (Skipped)
        0x028003e7,  # 0x1C: jalr x7, 0x28(x0)  (JALR Target -> 0x28)
        0x00800413,  # 0x20: addi x8, x0, 77    (Skipped)
        0x00900493,  # 0x24: addi x9, x0, 66    (Skipped)
        0x00a00513,  # 0x28: addi x10, x0, 10   (JALR 到达点)
    ]
    
    # 1. 装载内存并复位 DUT
    load_imem(dut, program)
    await init_frontend_signals(dut)

    # -------------------------------------------------------------------------
    # 场景 A: 验证正常顺序流水线
    # -------------------------------------------------------------------------
    await FallingEdge(dut.clk)
    dut.program_address.value = 0x00
    dut.start.value = 1

    await RisingEdge(dut.clk)
    dut.start.value = 0  # 撤销 start

    await Timer(1, unit="ps")
    
    assert dut.id_valid.value == 1, "ID 阶段 valid 应有效"
    assert dut.id_pc.value == 0x00, f"ID 阶段 PC 应匹配 0x00，实际为 {hex(dut.id_pc.value)}"
    assert dut.id_instruction.value == program[0], f"ID 阶段应取到 program[0]=0x{program[0]:08x}，实际为 0x{int(dut.id_instruction.value):08x}"

    # -------------------------------------------------------------------------
    # 场景 B: 模拟 EX 阶段发生 Branch 跳转 (beq 取跳转目标 0x08) + Flush 冲刷
    # -------------------------------------------------------------------------
    await FallingEdge(dut.clk)
    dut.ex_pc_sel.value = 1         # 3'b001: Branch 跳转
    dut.ex_branch_taken.value = 1
    dut.ex_branch_target.value = 0x08
    dut.flush.value = 1             # 冲刷流水线

    # 沿 1: 硬件采样到 Branch + Flush，IFU 将 PC 重置为 0x08，同时 IF/ID 寄存器被清空 (Bubble)
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    assert dut.id_valid.value == 0, "Flush 当拍 id_valid 必须被清零变成 Bubble！"


    # 下降沿撤销控制信号
    await FallingEdge(dut.clk)
    dut.ex_pc_sel.value = 0
    dut.ex_branch_taken.value = 0
    dut.flush.value = 0

    # 沿 2: IMem 完成 0x08 地址的数据读取，并在上升沿打入 ID 阶段
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    # 【上升沿 3】: IF/ID Reg 精确锁存 0x08 指令与 PC
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    assert dut.id_valid.value == 1, "跳转后 ID 阶段应该恢复有效"
    assert dut.id_pc.value == 0x08, f"Branch 跳转成功，期望 PC=0x08，实际={hex(dut.id_pc.value)}"
    assert dut.id_instruction.value == program[2], f"应取到 0x08 处指令，实际为 0x{int(dut.id_instruction.value):08x}"

    # -------------------------------------------------------------------------
    # 场景 C: 验证 Stall (暂停) 保持特性
    # -------------------------------------------------------------------------
    await FallingEdge(dut.clk)
    dut.stall.value = 1  # 锁存流水线

    # 在 stall 期间运行 3 个周期，确认 ID 阶段锁存的数据完全不动
    locked_id_pc = dut.id_pc.value
    locked_id_inst = dut.id_instruction.value

    for _ in range(3):
        await RisingEdge(dut.clk)
        await Timer(1, unit="ps")
        assert dut.id_pc.value == locked_id_pc, "Stall 期间 id_pc 不应发生变化"
        assert dut.id_instruction.value == locked_id_inst, "Stall 期间 id_instruction 不应发生变化"

    # 下降沿解冻 Stall
    await FallingEdge(dut.clk)
    dut.stall.value = 0

    # 流水线恢复，继续流动
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    assert dut.id_pc.value == 0x0C, f"Stall 解除后，流水线应推进至 0x0C，实际为 {hex(dut.id_pc.value)}"

class TestCore_SV:
    """Test the minimal three-stage core."""

    runner: Runner
    hdl_top: str

    @classmethod
    def setup_class(cls):
        sources = [
            HDL_SV_DIR / "core" / "imem.sv",
            HDL_SV_DIR / "core" / "pipeline_reg.sv",
            HDL_SV_DIR / "core" / "core.sv",
            HDL_SV_DIR / "core" / "ifu.sv",
            HDL_SV_DIR / "core" / "ibus_if.sv"
        ]
        cls.hdl_top = "CoreTop"
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    def test_raw_stall(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=__name__,
            testcase="t_frontend_control_and_pipeline",
        )