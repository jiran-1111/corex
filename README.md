# corex

该项目实现了一个RV32I指令的三级流水线，通过cocotb和c语言程序进行测试。

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

### 2、c语言测试
```bash
cd ~/pku_workspace/corex/my_c_test
make run-all 
make clean
make TEST=adder
make run TEST=adder
```

可以通过的测试

- adder
- binary_search
- cec32
- factorial
- fibonacci
- jar
- sort
- sum