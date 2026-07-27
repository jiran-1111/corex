from pathlib import Path
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge

from cocotb_utils import CLK_PERIOD_NS, HDL_SV_DIR, Runner, setup_runner


def load_hex_file(hex_path):
    """读取编译生成的 test.hex 文件，解析为 32-bit Word 列表"""
    words = []
    if not Path(hex_path).exists():
        raise FileNotFoundError(f"找不到 hex 编译文件: {hex_path}")

    with open(hex_path, "r") as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("@") or line.startswith("//"):
                continue
            # 处理按空格分隔的十六进制字节
            bytes_list = line.split()
            for i in range(0, len(bytes_list), 4):
                if i + 3 < len(bytes_list):
                    # verilog hex 格式通常是小端序（Little-Endians）
                    word_str = "".join(reversed(bytes_list[i : i + 4]))
                    words.append(int(word_str, 16))
    return words


def read_dmem(dut, byte_addr):
    """根据字节地址读取 DMem 对应 Word 的数值"""
    word_index = byte_addr // 4
    return int(dut.u_dmem.dmem.mem[word_index].value)


@cocotb.test()
async def t_core_c_sum_test(dut):
    """运行 C 语言 1~10 累加测试并验证 0x1000 处的计算结果 (应为 55)"""

    # 1. 动态获取测试名称并加载编译出的 hex 文件
    TEST_DIR = Path(__file__).parent.parent
    test_name = Path(__file__).stem.replace("test_core_", "")
    hex_path = TEST_DIR / "build" / test_name / "test.hex"

    words = load_hex_file(hex_path)

    # 2. 将指令加载到 IMem 中
    for i, val in enumerate(words):
        dut.u_ifu.IMem.imem.mem[i].value = val
    dut._log.info(f"Successfully loaded {len(words)} instructions into IMem.")

    # 3. 启动时钟 (100MHz, 10ns 周期)
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # 4. 硬件复位
    dut.rst.value = 1
    await ClockCycles(dut.clk, 5)
    dut.rst.value = 0
    await ClockCycles(dut.clk, 1)

    # 5. 轮询检测仿真完成标志位 (0x2000 == 1)
    max_cycles = 1000  # 设置最大等待超时周期
    completed = False

    for cycle in range(max_cycles):
        await RisingEdge(dut.clk)

        # 检查标志位 0x2000 是否被写入 1
        if read_dmem(dut, byte_addr=0x2000) == 1:
            dut._log.info(f"测试完成标志位已在第 {cycle} 个周期置 1！")
            completed = True
            break

    assert completed, f"测试超时！在 {max_cycles} 个周期内未检测到 0x2000 == 1"

    # 6. 验证计算结果：1 到 10 累加和应为 55 (0x37)
    actual_sum = read_dmem(dut, byte_addr=0x1000)
    expected_sum = sum(range(1, 11))  # 55

    dut._log.info(f"DMem[0x1000] 读取到的累加结果: {actual_sum}")
    assert (
        actual_sum == expected_sum
    ), f"结果不匹配! 期望值: {expected_sum}, 实际读取值: {actual_sum}"

    dut._log.info("恭喜！1~10 累加 C 语言测试通过！")

class TestCore_SV:
    """Test the minimal three-stage core."""

    runner: Runner
    hdl_top: str

    @classmethod
    def setup_class(cls):
        # 注意：脚本现在在 testcases/ 目录下，向上两级到达项目根目录
        COREX_ROOT = Path(__file__).parent.parent.parent
        hdl_dir = COREX_ROOT / "hdl_sv" / "core"
        sources = [
            hdl_dir / "control_unit.sv",
            hdl_dir / "ibus_if.sv",
            hdl_dir / "dbus_if.sv",
            hdl_dir / "imem.sv",
            hdl_dir / "dmem.sv",
            hdl_dir / "reg_file.sv",
            hdl_dir / "pipeline_reg.sv",
            hdl_dir / "decoder.sv",
            hdl_dir / "ALU.sv",
            hdl_dir / "execute.sv",
            hdl_dir / "ifu.sv",
            hdl_dir / "core.sv"
        ]
        cls.hdl_top = "CoreTop"
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    def test_c_add(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=f"testcases.{Path(__file__).stem}",
            testcase="t_core_c_sum_test",
        )