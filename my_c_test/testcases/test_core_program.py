# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Ran Ji

"""通用 C 程序集成测试：一个脚本运行 my_c_test/src/ 下所有 C 程序。

取代原来每个 C 程序一个 test_core_<name>.py 的写法。程序之间的差异只收敛为
「hex 路径 + 超时周期 + 结果检查项」，全部记录在下方 PROGRAMS 注册表里。

新增一个 C 程序只需两步，不用再写 cocotb 脚本：
  1. 写 src/<name>.c——结果写入 0x1000 起始的 DMem，结束前写 0x2000 = 1；
  2. 在 PROGRAMS 里加一行（max_cycles + checks）。
然后 `make run TEST=<name>` 即可。

程序结束约定（统一）：程序把结果写到 0x1000 起的数据区，运行结束前往
DONE_ADDR(0x2000) 写 1。测试轮询到 0x2000 == 1 后读取结果比对。
"""

import os
import sys
from pathlib import Path

import pytest
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer

# 复用上一级目录的通用辅助工具
sys.path.append(str(Path(__file__).parent.parent))
from cocotb_utils import CLK_PERIOD_NS, Runner, setup_runner

NOP = 0x00000013  # addi x0, x0, 0

DONE_ADDR = 0x2000  # 程序结束标志：写 1 表示运行完毕


def soft_mul_expected():
    """soft_mul_bit 程序的 golden：1234*5678 与按位反转后的异或（与 C 实现一致）。"""
    x, y = 1234, 5678
    product = (x * y) & 0xFFFFFFFF
    bit_reversed = 0
    temp = product
    for _ in range(32):
        bit_reversed = ((bit_reversed << 1) | (temp & 1)) & 0xFFFFFFFF
        temp >>= 1
    checksum = (product ^ bit_reversed) & 0xFFFFFFFF
    return {0x1000: product, 0x1004: checksum}


# ==============================================================================
# 程序注册表：name -> (max_cycles, {字节地址: 期望值})
#   期望值为 int   = 读取单个 32-bit 字并比对（无符号）
#   期望值为 list  = 从该地址起连续读取 len(list) 个字并整体比对
# ==============================================================================
PROGRAMS = {
    "adder":          (100,  {0x1000: 8}),                            # 3 + 5
    "sum":            (1000, {0x1000: 55}),                           # 1..10 累加
    "jar":            (1000, {0x1000: 123}),                          # 函数调用
    "crc32":          (6000, {0x1000: 0xCBF43926}),                   # "123456789"
    "factorial":      (5000, {0x1000: 720, 0x1004: 6}),               # 6! 与调用次数
    "fibonacci":      (3000, {0x1000: [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]}),
    "sort":           (5000, {0x1000: [11, 12, 22, 25, 34, 45, 64, 90]}),
    "binary_search":  (2000, {0x1000: 5, 0x1004: 0xFFFFFFFF}),        # 第二个目标未找到 = -1
    "soft_mul_bit":   (5000, soft_mul_expected()),                    # 1234*5678 与位翻转
    "str_toggle":     (5000, {0x1004: 1299}),                         # 大小写反转 checksum

    # === c_test 三人移植（2026-08-24，均适配 corex 裸机约定）===
    "zsq_fibonacci":    (3000, {0x1000: [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]}),
    "zsq_bubble_sort":  (5000, {0x1000: [11, 12, 22, 25, 34, 45, 64, 90]}),
    "zsq_mem_ops":      (1000, {0x1020: 50}),                         # 5+10+15+20
    "zsq_quick_sort":   (5000, {0x1000: [11, 12, 22, 25, 34, 45, 64, 90]}),
    "zsq_sum_loop":     (1000, {0x1000: 55}),                         # 1..10 累加
    "ljt_matrix":       (2000, {0x1000: [19, 22, 43, 50]}),           # 2×2 矩阵乘
    "ljt_reverse":      (1000, {0x1000: [88, 69, 82, 79, 67]}),       # "COREX" 反转 ASCII
    "ljt_sort":         (1000, {0x1000: [1, 2, 5, 7]}),               # 冒泡 {7,2,5,1}
    "ljt_binary_search": (1000, {0x1000: 3, 0x1004: 0xFFFFFFFF}),     # 找 7→3，找 6→-1
    "ljt_factorial":    (5000, {0x1000: 720, 0x1004: 6}),             # 6! 与调用次数
    "ljt_crc32":        (6000, {0x1000: 0xCBF43926}),                 # CRC32("123456789")
    "dim_transform":    (1000, {0x1000: 78}),                         # (173&0x1f)+65
}


def load_hex_file(filepath):
    """解析 objcopy -O verilog 生成的 hex 文件为 32-bit word 列表（小端序）。"""
    raw_bytes = []
    with open(filepath, "r") as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("//") or line.startswith("@"):
                continue
            for part in line.split():
                raw_bytes.append(int(part, 16))

    words = []
    for i in range(0, len(raw_bytes), 4):
        if i + 3 < len(raw_bytes):
            b0 = raw_bytes[i]
            b1 = raw_bytes[i + 1]
            b2 = raw_bytes[i + 2]
            b3 = raw_bytes[i + 3]
            words.append((b3 << 24) | (b2 << 16) | (b1 << 8) | b0)
    return words


def fill_mem(dut, words: list[int]):
    """通过层次化路径填充 IFU 内部 IMEM，剩余空间用 NOP 填充。"""
    imem_size = len(dut.u_ifu.IMem.imem.mem)
    for i in range(imem_size):
        dut.u_ifu.IMem.imem.mem[i].value = NOP

    for i, word in enumerate(words):
        dut.u_ifu.IMem.imem.mem[i].value = word

    dut._log.info(f"Successfully loaded {len(words)} instructions into IMem.")


def read_dmem(dut, byte_addr: int) -> int:
    """按字节地址读取 DMem 对应字（Word）的无符号值。"""
    return int(dut.u_dmem.dmem.mem[byte_addr // 4].value)


async def clock_tick(dut):
    await RisingEdge(dut.clk)
    await Timer(1, unit="step")


async def setup_dut(dut, start_pc: int = 0):
    """启动时钟、复位 2 拍、拉高 start 一拍开始执行。"""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
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
    await clock_tick(dut)


@cocotb.test()
async def t_core_program(dut):
    """运行指定 C 程序（由环境变量 CORETEST_PROGRAM 决定）并验证结果。"""
    TEST_DIR = Path(__file__).parent.parent
    program = os.environ["CORETEST_PROGRAM"]
    if program not in PROGRAMS:
        raise ValueError(f"未知测试程序: {program}，请在 PROGRAMS 注册表中添加")

    max_cycles, checks = PROGRAMS[program]
    hex_path = TEST_DIR / "build" / program / "test.hex"

    words = load_hex_file(hex_path)
    fill_mem(dut, words)
    await setup_dut(dut, start_pc=0)

    # 轮询 DONE_ADDR 直到程序写完 1
    done = False
    for cycle in range(max_cycles):
        await RisingEdge(dut.clk)
        if read_dmem(dut, DONE_ADDR) == 1:
            dut._log.info(f"检测到程序完成标志 (0x{DONE_ADDR:X} = 1)，用时 {cycle} 周期！")
            done = True
            break
    assert done, (
        f"测试超时！在 {max_cycles} 个周期内未检测到 0x{DONE_ADDR:X} == 1"
    )

    # 按注册表逐项比对结果
    for addr, expected in checks.items():
        if isinstance(expected, list):
            actual = [read_dmem(dut, addr + i * 4) for i in range(len(expected))]
            dut._log.info(f"DMem[0x{addr:X}:0x{addr + len(expected) * 4:X}] = {actual} (预期 {expected})")
            assert actual == expected, f"0x{addr:X} 处校验失败！预期 {expected}, 实际 {actual}"
        else:
            actual = read_dmem(dut, addr)
            dut._log.info(f"DMem[0x{addr:X}] = {actual} (预期 {expected})")
            assert actual == expected, f"0x{addr:X} 处校验失败！预期 {expected}, 实际 {actual}"

    dut._log.info(f"{program} 测试完全通过！")


class TestCore_SV:
    """Test the minimal five-stage core with C programs."""

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
            hdl_dir / "core.sv",
        ]
        cls.hdl_top = "CoreTop"
        cls.runner = setup_runner(sources=sources, hdl_toplevel=cls.hdl_top)

    @pytest.mark.parametrize("program", sorted(PROGRAMS))
    def test_c_program(self, program):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=f"testcases.{Path(__file__).stem}",
            testcase="t_core_program",
            extra_env={"CORETEST_PROGRAM": program},
        )
