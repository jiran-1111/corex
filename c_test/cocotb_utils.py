# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Chun Yang

"""Base utilities for cocotb unit tests."""

import os
from pathlib import Path
from typing import Mapping, Sequence

from cocotb_tools.runner import Runner, get_runner

# Get the simulator name from environment or use default.
# 从环境变量中获取仿真器名称（如：verilator, icarus, vcs等），如果没有设置，默认使用 verilator

SIM = os.getenv("SIM", "verilator")

# Default clock period in nanoseconds.
CLK_PERIOD_NS = 10

# Flag to always rebuild HDL regardless of source changes
# 这是一个强制构建标志。设置为 True 意味着每次运行测试都会重新编译 HDL 源码，防止修改了 RTL 但仿真器没刷新的情况

ALWAYS_BUILD = True

# Project paths
SIM_UNIT_DIR = Path(__file__).resolve().parent # 当前脚本所在目录
COREX_DIR = SIM_UNIT_DIR.parent.parent # 整个项目的根目录
BUILD_ROOT = COREX_DIR / "sim_build" # 仿真编译输出的临时目录
HDL_SV_DIR = COREX_DIR / "hdl_sv" # SystemVerilog 源码存放目录


def setup_runner(
    sources: Sequence[Path],      # 输入：硬件源码文件路径列表（如 [reg_file.sv]）
    hdl_toplevel: str,# 输入：RTL 顶层模块名（如 "RegFile"）
    build_id: str | None = None,  # 输入（可选）：编译标识符，
    parameters: Mapping[str, object] = {},  # 输入（可选）：硬件的 Parameter 参数字典
    simulator: str = SIM, # 输入：使用的仿真器
) -> Runner:
    """Setup cocotb runner and build HDL design."""

    # Create a unique build directory based on build_id or hdl_toplevel.
    # 1. 生成唯一的编译目录名
    # 如果没传 build_id，就用顶层模块名。把点号和路径分隔符换成下划线，避免创建多层非法文件夹

    build_tag = build_id or hdl_toplevel
    safe_tag = build_tag.replace(".", "_").replace(os.sep, "_")
    build_dir = BUILD_ROOT / safe_tag
    # 2. 获取 cocotb 的仿真运行器
    runner = get_runner(simulator)
    # 3. 驱动仿真器进行硬件编译（HDL Build）
    runner.build(
        sources=sources,
        hdl_toplevel=hdl_toplevel,
        always=ALWAYS_BUILD,
        build_dir=build_dir,
        parameters=parameters,
    )
    return runner
