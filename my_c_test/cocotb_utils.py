# COREX: Co-modeling RISC-V Example Core
#
# Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
# All rights reserved.
#
# Author: Chun Yang

"""Base utilities for cocotb unit tests."""

import os
import shutil
from pathlib import Path
from typing import Mapping, Sequence

from cocotb_tools.runner import Runner, get_runner

# Get the simulator name from environment or use default.
SIM = os.getenv("SIM", "verilator")

# 读取环境变量 COVERAGE，判断是否开启覆盖率收集
COVERAGE = False
# 如果不使用coverage COVERAGE = os.getenv("COVERAGE", "0") == "1"
# 支持从环境变量读取具体的覆盖率类型 (line / toggle / user / all)
COVERAGE_TYPE = os.getenv("COVERAGE_TYPE", "all")

# Default clock period in nanoseconds.
CLK_PERIOD_NS = 10

# Flag to always rebuild HDL regardless of source changes
ALWAYS_BUILD = True

# Project paths
SIM_UNIT_DIR = Path(__file__).resolve().parent  # 当前脚本所在目录
COREX_DIR = SIM_UNIT_DIR.parent                  # 整个项目的根目录
BUILD_ROOT = COREX_DIR / "sim_build"            # 仿真编译输出的临时目录
HDL_SV_DIR = COREX_DIR / "hdl_sv"               # SystemVerilog 源码存放目录


def setup_runner(
    sources: Sequence[Path],      # 输入：硬件源码文件路径列表
    hdl_toplevel: str,            # 输入：RTL 顶层模块名
    build_id: str | None = None,  # 输入（可选）：编译标识符
    parameters: Mapping[str, object] = {},  # 输入（可选）：硬件 Parameter 参数
    simulator: str = SIM,         # 输入：使用的仿真器
    extra_args: list[str] | None = None, # 支持外部自定义参数扩展
) -> Runner:
    """Setup cocotb runner and build HDL design."""

    build_tag = build_id or hdl_toplevel
    safe_tag = build_tag.replace(".", "_").replace(os.sep, "_")
    build_dir = BUILD_ROOT / safe_tag

    runner = get_runner(simulator)

    # 1. 首先把测试脚本（如 test_core_program.py）里传进来的 extra_args 全部保留
    compile_args = list(extra_args) if extra_args else []

    # 2. 如果开启了 COVERAGE 环境变量，且测试脚本里没有显式指定 --coverage 相关的参数，再根据 COVERAGE_TYPE 补全
    if COVERAGE:

        has_cov_arg = any("--coverage" in arg or "-cm" in arg for arg in compile_args)
        
        if not has_cov_arg:
            if simulator == "verilator":
                if COVERAGE_TYPE == "line":
                    compile_args.append("--coverage-line")
                elif COVERAGE_TYPE == "toggle":
                    compile_args.append("--coverage-toggle")
                elif COVERAGE_TYPE == "expr" or COVERAGE_TYPE == "branch":
                    compile_args.append("--coverage-expr")   # <--- 补充条件/表达式覆盖率
                elif COVERAGE_TYPE == "user":
                    compile_args.append("--coverage-user")
                elif COVERAGE_TYPE == "line+expr":
                    compile_args.extend(["--coverage-line", "--coverage-expr"])
                else:  # default or "all"
                    compile_args.append("--coverage") # --coverage 默认会开启 line + user + expr
            elif simulator == "vcs":
                compile_args.extend(["-cm", "line+cond+fsm+tgl"])

    runner.build(
        sources=sources,
        hdl_toplevel=hdl_toplevel,
        always=ALWAYS_BUILD,
        build_dir=build_dir,
        parameters=parameters,
        build_args=compile_args,
    )
    return runner


def collect_coverage(test_name: str = "default"):
    """
    通用函数：在测试运行结束后，提取并整理 Verilator 生成的 coverage.dat
    """
    if not COVERAGE:
        return

    cov_dir = COREX_DIR / "build" / "coverage"
    cov_dir.mkdir(parents=True, exist_ok=True)

    # Verilator 默认会在当前运行路径下生成 coverage.dat
    default_cov_file = Path("coverage.dat")
    if default_cov_file.exists():
        target_file = cov_dir / f"coverage_{test_name}.dat"
        shutil.move(default_cov_file, target_file)
        print(f"[Coverage] Saved coverage to {target_file}")