#
# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#

from pathlib import Path
import sys

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer


sys.path.append(str(Path(__file__).parent.parent))

from cocotb_utils import CLK_PERIOD_NS, Runner, setup_runner


NOP = 0x00000013   # addi x0,x0,0


def load_hex_file(filepath):
    """
    解析 objcopy -O verilog 生成的 hex 文件
    """
    raw_bytes = []

    with open(filepath, 'r') as f:
        for line in f:
            line = line.strip()

            if not line:
                continue

            if line.startswith("//"):
                continue

            if line.startswith("@"):
                continue

            parts = line.split()

            for part in parts:
                raw_bytes.append(int(part, 16))


    words = []

    for i in range(0, len(raw_bytes), 4):

        if i + 3 < len(raw_bytes):

            b0 = raw_bytes[i]
            b1 = raw_bytes[i+1]
            b2 = raw_bytes[i+2]
            b3 = raw_bytes[i+3]

            word = (
                (b3 << 24)
                |
                (b2 << 16)
                |
                (b1 << 8)
                |
                b0
            )

            words.append(word)


    return words



def fill_mem(dut, words):

    """
    初始化 IMEM
    """

    imem_size = len(dut.u_ifu.IMem.imem.mem)


    # 默认填充NOP
    for i in range(imem_size):

        dut.u_ifu.IMem.imem.mem[i].value = NOP


    for i, word in enumerate(words):

        dut.u_ifu.IMem.imem.mem[i].value = word


    dut._log.info(
        f"Successfully loaded {len(words)} instructions into IMem."
    )



def read_dmem(dut, byte_addr):

    """
    根据字节地址读取DMEM
    """

    word_index = byte_addr // 4

    return int(
        dut.u_dmem.dmem.mem[word_index].value
    )



async def setup_dut(dut, start_pc=0):

    clock = Clock(
        dut.clk,
        CLK_PERIOD_NS,
        unit="ns"
    )

    cocotb.start_soon(clock.start())


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


    await RisingEdge(dut.clk)





@cocotb.test()
async def t_core_c_func_call_test(dut):
    """
    测试C语言函数调用

    验证:
    1. jal 是否正确
    2. jalr 返回是否正确
    3. store是否正确
    """

    TEST_DIR = Path(__file__).parent.parent


    hex_path = (
        TEST_DIR
        /
        "build"
        /
        "jar"
        /
        "test.hex"
    )


    words = load_hex_file(hex_path)


    fill_mem(
        dut,
        words
    )


    await setup_dut(
        dut,
        start_pc=0
    )



    max_cycles = 1000


    done = False


    for cycle in range(max_cycles):

        await RisingEdge(dut.clk)


        done_flag = read_dmem(
            dut,
            0x2000
        )


        if done_flag == 1:

            dut._log.info(
                f"检测到完成标志，用时 {cycle} cycles"
            )

            done = True

            break



    assert done, (
        "程序没有执行结束，"
        "可能jal/jalr/函数返回存在问题"
    )



    result = read_dmem(
        dut,
        0x1000
    )


    dut._log.info(
        f"x变量结果 = {result}"
    )


    assert result == 123, (
        f"函数调用失败，"
        f"期望x=123，实际={result}"
    )


    dut._log.info(
        "C函数调用测试通过！"
    )





class TestCore_SV:

    runner: Runner
    hdl_top: str


    @classmethod
    def setup_class(cls):

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


        cls.runner = setup_runner(
            sources=sources,
            hdl_toplevel=cls.hdl_top
        )



    def test_c_func_call(self):

        self.runner.test(

            hdl_toplevel=self.hdl_top,

            test_module=(
                f"testcases."
                f"{Path(__file__).stem}"
            ),

            testcase=(
                "t_core_c_func_call_test"
            ),

        )