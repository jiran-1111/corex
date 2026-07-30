# cocotb覆盖率调研

## 1.概述

cocotb的覆盖率测试通常分为两个维度：python代码覆盖率、RTL代码覆盖率(code coverage)和功能覆盖率(functional Coverage)。

### 1.1 RTL代码覆盖率
主要衡量RTL代码被执行的程度，包括行覆盖率(line)、条件覆盖率(branch/condition)、翻转覆盖率(toggle)、状态机覆盖率(FSM)。

代码覆盖率必须由底层仿真器直接统计，cocotb仅仅负责在编译和运行阶段将相应的编译、仿真选项传递给仿真器

verilator使用 版本要求 ：Verilator 5.036+（cocotb 2.0 推荐）

|覆盖率类型 |Verilator 参数 |
|:--|:--|
|全部（行+分支+翻转+表达式） |--coverage |
|仅行/分支 |--coverage-line |
|仅信号翻转| --coverage-toggle |
|表达式覆盖 |--coverage-expr （v5.036+） |
|用户自定义功能覆盖点 |--coverage-user|

```Makefile
SIM := verilator
TOPLEVEL_LANG := verilog

# 根据 COVERAGE_TYPE 选择粒度
COVERAGE_TYPE ?= all
ifeq ("$(COVERAGE_TYPE)", "all")
    EXTRA_ARGS += --coverage
else ifeq ("$(COVERAGE_TYPE)", "line")
    EXTRA_ARGS += --coverage-line
else ifeq ("$(COVERAGE_TYPE)", "toggle")
    EXTRA_ARGS += --coverage-toggle
endif

# 波形（可选）
EXTRA_ARGS += --trace --trace-structs

include $(shell cocotb-config --makefiles)/Makefile.sim

```

运行后仿真器输出 coverage.dat ，可用 verilator_coverage 或第三方工具分析：

```bash
# Verilator 自带报告
verilator_coverage coverage.dat 
--write-info coverage.info
# 转换为 LCOV 格式后生成 HTML
genhtml coverage.info -o cov_html
```
### 1.2 python代码覆盖率

#### 1.2.1 方案A：临时启用
```bash
# 1. 安装依赖
pip install coverage

# 2. 运行测试（Makefile 或 pytest 方式均可）
export COCOTB_USER_COVERAGE=1
# 可选：自定义配置文件
export COVERAGE_RCFILE=path/to/.coveragerc

make SIM=verilator
# 或
pytest
```

#### 1.2.2 方案B：永久启用（全环境
```bash
# 1. 安装 sitecustomize hook（参考 coverage 官方文档）
# 2. 创建 .coveragerc
cat > .coveragerc << 'EOF'
[run]
branch = True
source = my_test_package
EOF

# 3. 运行
export COVERAGE_PROCESS_START=.coveragerc
make SIM=verilator
```

#### 通过coverage run启动cocotb仿真

```
coverage run -m pytest  # 如果你使用的是 pytest + cocotb runner
# 或者使用 coverage 监控 python 进程
coverage run --source=. -m cocotb.runner ...
```


#### 1.2.3 查看和合并结果
```bash
# 查看终端摘要
coverage report
# 生成 HTML 报告
coverage html -d htmlcov
# 多目录/并行测试后合并
coverage combine path/to/test1/.coverage path/to/test2/.coverage
```
### 1.3 功能覆盖率

用于衡量设计功能需求或边界条件是否被测试用例真实覆盖到。功能覆盖率的定义与采样在python端完成。

#### 1.3.1 方案A：cocotb-coverage

提供类似systemverilog的covergroup和coverpoint语法糖。通过装饰器实现数据采样。

示例代码：
```python
import cocotb
from cocotb_coverage.coverage import CoverPoint, CoverCross, coverage_section

# 1. 定义采样函数与 CoverPoint
@coverage_section(
    CoverPoint("top.a", xf=lambda a, b: a, bins=list(range(0, 16))),
    CoverPoint("top.b", xf=lambda a, b: b, bins=list(range(0, 16))),
    CoverCross("top.cross_a_b", items=["top.a", "top.b"])
)
def sample_coverage(a, b):
    pass

@cocotb.test()
async def test_alu(dut):
    # 2. 激励驱动与覆盖率采样
    for a in range(16):
        for b in range(16):
            dut.a.value = a
            dut.b.value = b
            await cocotb.triggers.Timer(1, units="ns")

            # 采样当前数据
            sample_coverage(a, b)
```

导出与查看结果，可在测试结束时导出XML

```bash
from cocotb_coverage.coverage import coverage_db
coverage_db.export_to_xml("functional_coverage.xml")
```
#### 1.3.2 方案B：PyVSC SystemVerilog兼容型
PyVSC(Python Verification Stimulus and Coverage)PyUCIS基础设施的一部分，旨在为Python带来 与SystemVerilog语法和概念高度相似的约束随机（CRV）与功能覆盖率支持。  

优势：支持标准的UCIS(Unified Coverage Interoperability Standard)格式，导出的数据库可以无缝兼容商业EDA软件的查看器。

示例代码：

```python
import vsc

@vsc.covergroup
class alu_covergroup(object):
    def __init__(self):
        # 定义 coverpoint
        self.cp_op = vsc.coverpoint(self.op, bins={"ADD": 0, "SUB": 1, "MUL": 2})
        self.cp_a  = vsc.coverpoint(self.a, bins={"low": vsc.bin_slice(0, 15)})

    def sample(self, op, a):
        self.op = op
        self.a = a
        super().sample()

# 在 cocotb 测试中使用
cg = alu_covergroup()
cg.sample(op=1, a=10)

# 导出 UCIS 数据
vsc.write_coverage_db("cov.ucis")
```

## 2. 安装
```bash
pip install coverage
```


## 3. 参考资料
cocotb官方覆盖率文档：https://docs.cocotb.org/en/development/coverage.html

cocotb-coverage文档：https://cocotb-coverage.readthedocs.io/en/latest/

cocotb仿真器支持（含覆盖率参数）：https://github.com/cocotb/cocotb/blob/master/docs/source/simulator_support.rst