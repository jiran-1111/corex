# corex

该项目实现了一个RV32I指令的五级流水线，通过cocotb和c语言程序进行测试。

## setup-conda环境

```bash
# Ubuntu22.04

# 安装依赖
sudo apt update
sudo apt install -y git help2man perl make g++ flex bison ccache autoconf \
    libfl2 libfl-dev zlib1g zlib1g-dev liblz4-dev

# 创建环境
conda create -n corex_env python=3.10 -y

# 激活环境
conda activate corex_env

# cocotb pytest
pip install cocotb pytest

# verilator-v5.040
git clone https://github.com/verilator/verilator.git
cd verilator
git checkout v5.040
autoconf
./configure
make -j$(nproc)
sudo make install

cd ..
cd corex

# 运行测试
SIM=verilator python3 -m pytest -v sim/unit/core/test_imem.py //显示详细信息
SIM=verilator python3 -m pytest -v -s sim/unit/core/test_decoder.py
```


## 文件结构

```
.
├── README.md
├── cspell.json
├── docs                   # 文档 流水线结构图
├── hdl_sv
│   └── core               # 流水线设计部分
├── my_c_test              # c语言测试部分
│   ├── Makefile
│   ├── README.md
│   ├── __pycache__
│   ├── bsp                # 汇编入口 链接脚本
│   ├── build
│   ├── cocotb_utils.py
│   ├── src                # c语言源文件  
│   ├── sim_build
│   └── testcases          # 测试用例
├── sim
│   └── unit
│       └── core           # 流水线cocotb测试部分
├── sim_build
└── verilator              # verilator编译部分
```

## 测试

### 1、cocotb测试
```bash
conda activate corex_env
SIM=verilator python3 -m pytest -v -s sim/unit/core/test_decoder.py
```
较为重要的测试

- test_core_lzq

由于有些模块的测试是初期编写（如test_ifu_all.py），由于端口名不一致有可能无法运行，优先运行test_core_lzq.py和test_core_all.py

### 2、c语言测试
```bash
cd ~/pku_workspace/corex/my_c_test
make run-all           # 编译并运行全部 C 程序测试
make clean
make TEST=adder        # 编译单个程序
make run TEST=adder    # 编译 + 运行单个程序的测试
```

所有 C 程序共用一个通用 cocotb 脚本 `testcases/test_core_program.py`（内置 `PROGRAMS` 注册表），新增程序只需写 `.c` + 注册表加一行，无需新脚本。

- **stdio 环境**：`bsp/libc/` 提供最小 `printf`（`#include <stdio.h>` 可用），输出写入 DMem `0x2800` 控制台缓冲。
- **结果约定（二选一，可混用）**：写 `0x1000` 起始的 DMem 并结束前写 `0x2000 = 1`；或直接 `printf`（脚本检查 `0x2800` 控制台字符串）。
- **指令集**：RV32I 完整访存（LB/LBU/LH/LHU/LW + SB/SH/SW）；乘法用 libgcc 软件例程（`-lgcc`）。

可以通过的测试（22 个）：

- adder、sum、jar、crc32、factorial、fibonacci、sort、binary_search、soft_mul_bit、str_toggle
- zsq_fibonacci、zsq_bubble_sort、zsq_mem_ops、zsq_quick_sort、zsq_sum_loop（来自 c_test/zsq）
- ljt_matrix、ljt_reverse、ljt_sort、ljt_binary_search、ljt_factorial、ljt_crc32（来自 c_test/ljt）
- dim_transform（来自 c_test/dim）