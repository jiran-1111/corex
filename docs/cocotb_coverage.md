# cocotb覆盖率调研
cocotb的覆盖率测试通常分为三个维度：RTL代码覆盖率、python代码覆盖率、功能覆盖率。

## 1. RTL 代码覆盖率
主要衡量RTL代码被执行的程度，包括行覆盖率(line)、表达式覆盖率(expr)、翻转覆盖率(toggle)等。

代码覆盖率必须由底层仿真器直接统计，cocotb仅仅负责在编译和运行阶段将相应的编译、仿真选项传递给仿真器。

verilator使用 版本要求 ：Verilator 5.036+（cocotb 2.0 推荐）

|覆盖率类型 |Verilator 参数 |
|:--|:--|
|全部（行+分支+翻转+表达式） |--coverage |
|仅行/分支 |--coverage-line |
|仅信号翻转| --coverage-toggle |
|表达式覆盖 |--coverage-expr （v5.036+） |
|用户自定义功能覆盖点 |--coverage-user|

该参数可在cocotb脚本 cls.runner = setup_runner(extra_args=["--coverage"]) 位置修改


### 1.1 修改 my_c_test / Makefile
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

### 1.2 修改 my_c_test / cocotb_utils.py
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

### 1.3 修改 cocotb 脚本 my_c_test / testcases / test_core_adder.py
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
cd coverage.data所在地址 
如：cd /home/ranrr/pku_workspace/corex/sim_build/CoreTop/
verilator_coverage --annotate html coverage.dat
```
结果：
```bash
binary_search结果：
"--coverage"   Enables all types of coverage.
Total coverage (212/400) 53.00%
See lines with '%00' in html

"--coverage-line"   Enables basic block line coverage.
Total coverage (126/186) 67.00%
See lines with '%00' in html

"--coverage-toggle"   Enables signal toggle coverage.
Total coverage (90/214) 42.00%
See lines with '%00' in html

"--coverage-expr"   Enables expression coverage.
Total coverage (0/11) 0.00%
See lines with '%00' in html

"--coverage-user"   Enables user-defined coverage points
Total coverage (0/0) 0.00%

"--coverage-line", "--coverage-expr"   Both line and expr coverage test
Total coverage (122/186) 65.00%
See lines with '%00' in html

```
可以在sim_build/CoreTop/html下查看各个代码文件的执行情况

%000000（或包含 %00）：代表这行代码在仿真过程中一次都没有被执行过（需要补充测试用例的地方）。

非零数字（如 000005）：代表这行代码在仿真过程中被执行了 5 次。

## 2. python代码覆盖率测试

### 2.1 安装
```bash
pip install coverage
```
### 2.2 运行测试并收集覆盖率

#### a.方案一
安装 pytest-cov 插件
```bash
pip install pytest-cov
```
修改 my_c_test \ Makefile
```makefile
run-cov: all
	COVERAGE=1 python -m pytest testcases/test_core_$(TEST).py \
		--cov=testcases \
		--cov-report=html:build/coverage/python_html \
		-s -v --log-cli-level=INFO
```

运行 make run-cov TEST=adder

生成 html : Coverage HTML written to dir build/coverage/python_html
#### b.方案二

新增 testcases / confest.py 脚本
```python
import os
import atexit
import coverage

# 只有当环境变量 COVERAGE=1 时才启动 Python 覆盖率收集
if os.environ.get("COVERAGE") == "1":
    # 指定只监控 testcases 目录，并明确报告保存的绝对路径
    cov_file = os.path.abspath("build/coverage/.coverage")
    os.makedirs(os.path.dirname(cov_file), exist_ok=True)
    
    cov = coverage.Coverage(
        data_file=cov_file,
        source=["testcases"],
        branch=True
    )
    cov.start()

    # 仿真进程退出时自动保存数据并生成网页
    def save_coverage():
        cov.stop()
        cov.save()
        cov.html_report(directory="build/coverage/python_html")
        print(f"\n[Coverage] Python coverage report generated at build/coverage/python_html/index.html")

    atexit.register(save_coverage)
```

运行 make run-cov TEST=adder

```bash
make run-cov TEST=binary_search
python3 -m http.server 8000 
浏览器输入 http://localhost:8000/build/coverage/python_html/
```

## 3. 功能覆盖率测试

用于衡量设计功能需求或边界条件是否被测试用例真实覆盖到。功能覆盖率的定义与采样在python端完成。

### 3.1 安装
```bash
pip install cocotb-coverage
```
### 3.2 修改 my_c_test / testcases / test_core_adder.py
增加功能覆盖率的代码
```python
# ==============================================================================
# 1. 定义功能覆盖率模型 (Functional Coverage Model)
# ==============================================================================
@CoverPoint(
    "top.dmem.read_result",
    xf=lambda idx, val: "ZERO" if val == 0 else ("EXPECTED_8" if val == 8 else "OTHER"),
    bins=["ZERO", "EXPECTED_8", "OTHER"]
)
@CoverPoint(
    "top.dmem.read_index",
    xf=lambda idx, val: f"ADDR_0x{idx*4:03X}",
    bins=["ADDR_0x100", "OTHER_ADDR"]
)
@CoverCross(
    "top.dmem.result_x_addr",
    items=["top.dmem.read_result", "top.dmem.read_index"]
)
def sample_dmem_coverage(index: int, value: int):
    """采样函数：当从 DMEM 读取计算结果时触发采样"""
    pass

@cocotb.test()
async def t_core_c_add_test(dut):
    
    # ==========================================================================
    # 3. 导出并打印功能覆盖率报告
    # ==========================================================================
    dut._log.info("\n" + "="*50 + "\nFunctional Coverage Summary\n" + "="*50)
    #coverage_db.report_detailed(print_xml=False)
    coverage_db.report_coverage(cocotb.log.info, bins=True)
    # 导出一份 XML 文件便于后期汇总或统计
    xml_out = TEST_DIR / "build" / "coverage" / "functional_coverage_adder.xml"
    xml_out.parent.mkdir(parents=True, exist_ok=True)
    coverage_db.export_to_xml(str(xml_out))
```

### 3.3 环境问题： cocotb-coverage 导致 cocotb 降级
```bash
pip install --no-deps cocotb-coverage
Requirement already satisfied: cocotb-coverage in /home/ranrr/anaconda3/envs/corex_env/lib/python3.10/site-packages (1.2.0)
python -c "from cocotb_tools.runner import get_runner; import cocotb_coverage; print('Environment Ready')"
Environment Ready
```
### 3.4 测试结果
```bash
make run TEST=adder
                                                     ==================================================
                                                        Functional Coverage Summary
                                                        ==================================================
   250.00ns INFO     test                               top : <cocotb_coverage.coverage.CoverItem object at 0x7f1f0da4a560>, coverage=5, size=11 
   250.00ns INFO     test                                  top.dmem : <cocotb_coverage.coverage.CoverItem object at 0x7f1f0ddec820>, coverage=5, size=11 
   250.00ns INFO     test                                     top.dmem.read_index : <cocotb_coverage.coverage.CoverPoint object at 0x7f1f0da4a590>, coverage=1, size=2 
   250.00ns INFO     test                                        BIN ADDR_0x100 : 22
   250.00ns INFO     test                                        BIN OTHER_ADDR : 0
   250.00ns INFO     test                                     top.dmem.read_result : <cocotb_coverage.coverage.CoverPoint object at 0x7f1f0ddef340>, coverage=2, size=3 
   250.00ns INFO     test                                        BIN ZERO : 21
   250.00ns INFO     test                                        BIN EXPECTED_8 : 1
   250.00ns INFO     test                                        BIN OTHER : 0
   250.00ns INFO     test                                     top.dmem.result_x_addr : <cocotb_coverage.coverage.CoverCross object at 0x7f1f0ddec7c0>, coverage=2, size=6 
   250.00ns INFO     test                                        BIN ('ZERO', 'ADDR_0x100') : 21
   250.00ns INFO     test                                        BIN ('ZERO', 'OTHER_ADDR') : 0
   250.00ns INFO     test                                        BIN ('EXPECTED_8', 'ADDR_0x100') : 1
   250.00ns INFO     test                                        BIN ('EXPECTED_8', 'OTHER_ADDR') : 0
   250.00ns INFO     test                                        BIN ('OTHER', 'ADDR_0x100') : 0
   250.00ns INFO     test                                        BIN ('OTHER', 'OTHER_ADDR') : 0
   250.00ns INFO     cocotb.regression                  testcases.test_core_adder.t_core_c_add_test passed
```
## 4. 参考资料
cocotb官方覆盖率文档：https://docs.cocotb.org/en/development/coverage.html

cocotb-coverage文档：https://cocotb-coverage.readthedocs.io/en/latest/

cocotb仿真器支持（含覆盖率参数）：https://github.com/cocotb/cocotb/blob/master/docs/source/simulator_support.rst