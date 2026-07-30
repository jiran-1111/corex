# 我的cocotb覆盖率更新日志

## 1. rtl代码覆盖率
### 1.1 修改my_c_test/makefile
```makefile
# ==========================================
# RTL 覆盖率测试目标
# ==========================================

# 1. 带覆盖率运行单个测试
run-cov: all
	COVERAGE=1 python -m pytest testcases/test_core_$(TEST).py -s -v --log-cli-level=INFO

# 2. 带覆盖率运行所有测试并自动生成 HTML 报告
run-all-cov: build-all
	COVERAGE=1 python -m pytest testcases/
	@$(MAKE) cov-report

# 3. 收集并生成 Verilator 代码覆盖率 HTML 报告
cov-report:
	@echo "==> Collecting Verilator Coverage..."
	@mkdir -p build/coverage
	# 将所有的 .dat 覆盖率文件汇总合并
	verilator_coverage --write build/coverage/coverage.dat build/coverage/*.dat
	# 转换为 lcov 格式
	verilator_coverage --write-info build/coverage/coverage.info build/coverage/coverage.dat
	# 生成 HTML 报告
	genhtml build/coverage/coverage.info --output-directory build/coverage/html
	@echo "==> Coverage Report generated at: build/coverage/html/index.html"

.PHONY: run-cov run-all-cov cov-report
```

### 1.2 修改my_c_test/cocotb_utils.py
```python
import os
import shutil
from pathlib import Path
from typing import Mapping, Sequence

from cocotb_tools.runner import Runner, get_runner

# Get the simulator name from environment or use default.
SIM = os.getenv("SIM", "verilator")

# 读取环境变量 COVERAGE，判断是否开启覆盖率收集
COVERAGE = os.getenv("COVERAGE", "0") == "1"

# Default clock period in nanoseconds.
CLK_PERIOD_NS = 10

# Flag to always rebuild HDL regardless of source changes
ALWAYS_BUILD = True

# Project paths
SIM_UNIT_DIR = Path(__file__).resolve().parent  # 当前脚本所在目录
COREX_DIR = SIM_UNIT_DIR.parent          # 整个项目的根目录
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

    # ----------------------------------------------------
    # 自动开启代码覆盖率编译选项
    # ----------------------------------------------------
    compile_args = list(extra_args) if extra_args else []
    
    if COVERAGE:
        if simulator == "verilator":
            compile_args.append("--coverage")
        elif simulator == "vcs":
            compile_args.extend(["-cm", "line+cond+fsm+tgl"])

    runner.build(
        sources=sources,
        hdl_toplevel=hdl_toplevel,
        always=ALWAYS_BUILD,
        build_dir=build_dir,
        parameters=parameters,
        build_args=compile_args,  # <--- 修改这里：使用 build_args 替代 extra_args
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
```

### 1.3 修改cocotb脚本
```python
from cocotb_utils import collect_coverage
class TestCore_SV:
    @classmethod
    def setup_class(cls):
        cls.runner = setup_runner(
            sources=sources, 
            hdl_toplevel=cls.hdl_top,
            extra_args=["--coverage"]    # 增加rtl覆盖率测试
        )

    def test_c_add(self):
        self.runner.test(
            hdl_toplevel=self.hdl_top,
            test_module=f"testcases.{Path(__file__).stem}",
            testcase="t_core_c_add_test"
        )
        collect_coverage("c_add")# 增加rtl覆盖率测试
```

### 1.4 查看
```bash
cd /home/ranrr/pku_workspace/corex/my_c_test
make run TEST=adder

find ~/pku_workspace/ -name "*.dat" # 找到coverage.dat所在地址
cd coverage.data所在地址 如 cd /home/ranrr/pku_workspace/corex/sim_build/CoreTop/
verilator_coverage --annotate html coverage.dat
```
```bash
binary_search结果：
"--coverage"Enables all types of coverage.
Total coverage (212/400) 53.00%
See lines with '%00' in html

"--coverage-line"Enables basic block line coverage.
Total coverage (126/186) 67.00%
See lines with '%00' in html

"--coverage-toggle"Enables signal toggle coverage.
Total coverage (90/214) 42.00%
See lines with '%00' in html

"--coverage-expr"Enables expression coverage.
Total coverage (0/11) 0.00%
See lines with '%00' in html

"--coverage-user"Enables user-defined coverage points
Total coverage (0/0) 0.00%

"--coverage-line", "--coverage-expr"
Total coverage (122/186) 65.00%
See lines with '%00' in html

```
可在sim_build/CoreTop/html下查看各个代码文件的执行情况

%000000（或包含 %00）：代表这行代码在仿真过程中一次都没有被执行过（需要补充测试用例的地方）。

非零数字（如 000005）：代表这行代码在仿真过程中被执行了 5 次。

## 2. python代码覆盖率测试

### 2.1 安装
```bash
pip install coverage
```
### 2.2 运行测试并收集覆盖率

## 3. 功能覆盖率测试