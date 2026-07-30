# CLAUDE.md

本文件为 Claude Code（claude.ai/code）在此仓库中工作时提供指导。

## 项目概述

COREX（Co-modeling RISC-V Example Core）是一个用 SystemVerilog 实现的 **RV32I 三级流水线 CPU**，由北京大学微处理器研发中心（MPRC）开发。验证采用 **cocotb + Verilator** 进行单元测试，并使用**交叉编译的 C 程序**进行集成测试。

## 构建与测试命令

### 环境准备

```bash
conda activate corex_env
```

### 单元测试（cocotb，单个模块）

```bash
SIM=verilator python3 -m pytest -v sim/unit/core/test_decoder.py       # 运行单个测试文件
SIM=verilator python3 -m pytest -v -s sim/unit/core/test_decoder.py    # 带打印输出
SIM=verilator python3 -m pytest -v sim/unit/core/test_core_lzq.py      # 核心集成测试
```

### C 程序测试（全流水线集成）

```bash
cd my_c_test
make TEST=adder          # 编译单个 C 程序为 hex 文件
make run TEST=adder      # 编译 + 运行对应的 cocotb 测试
make run-all             # 编译并运行所有 C 测试
make clean               # 清理构建产物
```

前置条件：需要安装 `riscv64-unknown-elf-gcc` 交叉编译器。

## 架构设计

### 流水线结构（三级）

```
IF（取指）  →  ID/EX（译码 + 执行）  →  MEM/WB（访存 + 写回）
```

- **IF 阶段**（[ifu.sv](hdl_sv/core/ifu.sv)）：PC 寄存器、下一 PC 多路选择（处理分支、JAL、JALR）、通过 `IBusIf` 接口从指令存储器取指。
- **ID/EX 阶段**：译码和执行在**同一周期**内完成（无 ID/EX 流水线寄存器）。
  - [decoder.sv](hdl_sv/core/decoder.sv)：指令字段提取、立即数生成（I/S/B/U/J 类型）、带写回旁路的寄存器文件读取、分支/JAL 目标地址计算、存储字节使能生成。
  - [control_unit.sv](hdl_sv/core/control_unit.sv)：根据 opcode 生成主控制信号——ALUOp、操作数选择、extend_sel、regWrite、memRead/Write、next_PC_sel。
  - [execute.sv](hdl_sv/core/execute.sv)：ALU 控制编码、操作数 A/B 多路选择（rs1/PC/PC+4/0；rs2/imm）、ALU 实例化、JALR 目标地址计算。
  - [ALU.sv](hdl_sv/core/ALU.sv)：通过 6 位 ALU_Control 支持所有 RV32I 算术/逻辑/移位/比较操作。
- **MEM/WB 阶段**（[dmem.sv](hdl_sv/core/dmem.sv)）：带字节使能（`DBusIf`）的数据存储器读写，写回多路选择（访存数据 vs ALU 结果）。

### 流水线寄存器（[pipeline_reg.sv](hdl_sv/core/pipeline_reg.sv)）

通用参数化模块，控制通路与数据通路分离：
- **控制通路**：支持复位和刷新（优先级：reset > flush > enable）。
- **数据通路**：无复位/刷新（PPA 优化）；数据有效性由控制通路保证。
- 两个实例：**IF/ID**（IF 与 ID 之间）和 **EX/MEM**（EX 与 MEM 之间）。

### 刷新与停顿

- `flush` 在以下情况置位：分支跳转成功（`pc_sel=01 & branch_taken`）、JAL（`pc_sel=10`）、JALR（`pc_sel=11`）。
- `flush` 通过 `flush_d` 扩展 1 个周期，为 `real_if_id_flush` 形成 2 周期窗口——这覆盖了 EX 阶段分支解析结果到达 IF/ID 寄存器的延迟。
- `stall` 目前固定为 `1'b0`（未实现流水线停顿）。
- 刷新时，IF/ID 寄存器控制输出变为 0，[core.sv](hdl_sv/core/core.sv) 向译码阶段注入 `NOP`（`addi x0, x0, 0`）。

### 寄存器文件与旁路

- [reg_file.sv](hdl_sv/core/reg_file.sv)：32×32 位，两个组合读端口，一个同步写端口。x0 硬连线为零。
- **写回旁路**（[decoder.sv](hdl_sv/core/decoder.sv)）：当 `rs1`/`rs2` 与 WB 阶段的 `write_reg` 匹配（且写使能有效）时，数据直接转发——避免了写后读（RAW）的一周期停顿。

### 存储器接口

- `IBusIf` / `DBusIf`：SystemVerilog interface，通过 `modport master/slave` 实现 CPU↔存储器通信。
- `IMemTop` / `DMemTop`：为单元测试封装的顶层模块，将 interface 端口展开为普通信号端口。
- DMem 支持通过 `$readmemh` 从 hex 文件初始化，用于 C 程序测试。

### C 测试流程

1. [my_c_test/src/](my_c_test/src/) 中的 C 源码 → 使用 `riscv64-unknown-elf-gcc` 交叉编译（`-march=rv32i -mabi=ilp32 -nostdlib`）。
2. 链接 [bsp/crt0.s](my_c_test/bsp/crt0.s)（设置栈指针、调用 `main`、返回后死循环）和 [bsp/link.ld](my_c_test/bsp/link.ld)（程序起始地址 `0x00000000`）。
3. `objcopy -O verilog` 生成 hex 文件。
4. [my_c_test/testcases/](my_c_test/testcases/) 中的 Python 测试用例通过层次化路径（`dut.u_ifu.IMem.imem.mem`）将 hex 加载到 IMem，运行核心，并检查 DMem 中的结果。

### 测试层次

| 层次 | 位置 | 用途 |
|------|------|------|
| 单元测试 | [sim/unit/core/](sim/unit/core/) | 逐模块验证（ALU、Decoder、Execute、RegFile 等） |
| 核心集成测试 | `test_core_lzq.py` | 手写指令序列的全流水线测试 |
| C 程序测试 | [my_c_test/testcases/](my_c_test/testcases/) | 端到端：C → hex → 在核心上运行 → 检查 DMem |

### Verilator 构建源文件列表

所有 cocotb 测试必须按依赖顺序包含全部 HDL 源文件。标准列表（参考 [my_c_test/testcases/](my_c_test/testcases/) 中的模式）：

```
control_unit.sv → ibus_if.sv → dbus_if.sv → imem.sv → dmem.sv →
reg_file.sv → pipeline_reg.sv → decoder.sv → ALU.sv → execute.sv →
ifu.sv → core.sv
```

## 添加新的 C 测试

1. 编写 `my_c_test/src/<name>.c`——程序必须将结果写入已知的 DMem 地址（例如 `*(volatile int*)0x100 = result`）。
2. 参照已有模式编写 `my_c_test/testcases/test_core_<name>.py`（加载 hex、填充 IMem、运行、检查 DMem）。
3. 运行 `make TEST=<name>` 然后 `make run TEST=<name>`。

## 注意事项

- Verilator 源码内置于 [verilator/](verilator/) 目录（v5.040 版本）。该目录有自己的 `.git`——顶层 `.gitignore` 将其排除在主仓库之外。
- `sim_build/` 是 Verilator 构建输出目录，已被 gitignore 忽略。
- `CoreTop` 的 `program_address` 输入用于设置初始 PC；在 `start` 脉冲或复位时锁存。
- 所有 HDL 模块的作者信息记录在文件头部注释中（Ran Ji、Chun Yang、Ziqing Lin）。
