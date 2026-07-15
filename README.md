## corex

### setup

```bash
# Ubuntu22.04

# install dependencies
sudo apt update
sudo apt install git help2man perl python3 make g++ flex bison ccache autoconf 
sudo apt install libfl2 libfl-dev zlib1g zlib1g-dev liblz4-dev

# install cocotb / pytest
python3 -m pip install cocotb pytest

# install verilator-v5.040
git clone https://github.com/verilator/verilator.git
cd verilator
git checkout v5.040
autoconf
./configure
make -j$(nproc)
sudo make install
cd ..

# run test
# clone corex here
cd corex
SIM=verilator python3 -m pytest -q sim/unit/core/test_my_module.py
SIM=verilator python3 -m pytest -v sim/unit/core/test_imem.py //显示详细信息
# xxx passed in xxx s
```

my_env

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

```
- HDL 设计在 hdl_sv
 目前只有 3 个核心文件：
- ibus_if.sv ：指令总线接口定义（req/addr → gnt/ack/err/rdata）
- imem.sv ：指令存储器 IMem（只读 RAM）+ 单元测试用的顶层 IMemTop
- pipeline_reg.sv ：通用流水寄存器模块（控制/数据分离）
- 测试在 sim/unit
- cocotb_utils.py ：统一的“编译/构建/运行仿真”的封装（用 cocotb_tools.runner）
- test_imem.py ：IMem 的所有单元测试
- verilator/ ：仓库里直接带了一份 Verilator 源码（方便固定版本/离线使用）
- sim_build/ ：仿真构建产物输出目录（runner.build 生成）
- README ：环境安装与跑测试的命令在 README.md
```
