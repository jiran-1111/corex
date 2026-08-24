# CLAUDE.md

本文件为 Claude Code（claude.ai/code）在此仓库中工作时提供指导。

## 项目概述

COREX（Co-modeling RISC-V Example Core）是一个用 SystemVerilog 实现的 **RV32I 五级流水线 CPU**，由北京大学微处理器研发中心（MPRC）开发。验证采用 **cocotb + Verilator** 进行单元测试，并使用**交叉编译的 C 程序**进行集成测试。

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

### 流水线结构（五级）

```
IF（取指） → ID（译码 + 寄存器读取） → EX（ALU + 分支/JALR 判定） → MEM（数据访存） → WB（写回）
```

- **IF 阶段**（[ifu.sv](hdl_sv/core/ifu.sv)）：PC 寄存器、下一 PC 多路选择（处理分支、JAL、JALR）、通过 `IBusIf` 接口从指令存储器取指。IMem 为同步读（`rdata` 滞后 `addr` 一拍），因此 `PC_reg` 超前 `inst_PC_reg` 一拍，IF 输出端总有一条"在途"指令——这是下文 2 周期 flush 窗口的根因。
- **ID 阶段**：译码 + 寄存器文件读取。
  - [decoder.sv](hdl_sv/core/decoder.sv)：指令字段提取、立即数生成（I/S/B/U/J 类型）、带写回旁路的寄存器文件读取、分支/JAL 目标地址计算、存储字节使能生成。
  - [control_unit.sv](hdl_sv/core/control_unit.sv)：根据 opcode 生成主控制信号——ALUOp、操作数选择、extend_sel、regWrite、memRead/Write、next_PC_sel。
- **EX 阶段**（[execute.sv](hdl_sv/core/execute.sv) + [ALU.sv](hdl_sv/core/ALU.sv)）：ALU 控制编码、操作数 A/B 多路选择（rs1/PC/PC+4/0；rs2/imm）、ALU 运算、分支成立判定（`branch_taken`）、JALR 目标计算（`JALR_target = (rs1 + imm) & ~1`）。
- **MEM 阶段**（[dmem.sv](hdl_sv/core/dmem.sv) + [core.sv](hdl_sv/core/core.sv) 的 MEM 段组合逻辑）：带字节使能（`DBusIf`）的数据存储器读写。**支持完整访存宽度**：Load 按 funct3 与地址低位选字节/半字并符号/零扩展（LB/LBU/LH/LHU/LW）；Store 按地址低位计算 `wbe` 与写数据字节偏移（SB/SH/SW）。funct3 随流水传到 MEM（`ex_mem_data_t.funct3`）。
- **WB 阶段**：写回多路选择（访存数据 vs ALU 结果），写入寄存器文件。

### 流水线寄存器（[pipeline_reg.sv](hdl_sv/core/pipeline_reg.sv)）

通用参数化模块，控制通路与数据通路分离：
- **控制通路**：支持复位和刷新（优先级：reset > flush > enable）。
- **数据通路**：无复位/刷新（PPA 优化）；数据有效性由控制通路（valid 位）保证。
- 四个实例：**IF/ID**（`u_if_id_reg`）、**ID/EX**（`u_id_ex_reg`）、**EX/MEM**（`u_ex_mem_reg`）、**MEM/WB**（`u_mem_wb_reg`）。IF/ID、ID/EX 支持 flush；EX/MEM、MEM/WB 无 flush（其有效性与写使能由 valid 位逐级门控，见 [core.sv](hdl_sv/core/core.sv)）。

### 刷新与停顿

- **`stall` = Load-Use 冒险**（已实现）：EX 阶段的 Load 指令（`id_ex_ctrl_out.mem_read`）目标寄存器 `rd` 被 ID 阶段指令作为源寄存器使用（`rd != x0` 且等于 `rs1`/`rs2`）→ 停顿 1 拍：IF/ID `en=0` 保持，ID/EX 被 `id_ex_flush` 清空。同时 `stall` 经 IMem 的 `hold` 门控组合冻结 `rdata_q`，防止 PC/inst_PC 错位（见 [ifu.sv](hdl_sv/core/ifu.sv)）。
- **`id_flush`**：JAL 在 ID 阶段解析（`pc_sel=10`）。
- **`ex_flush`**：分支成立（`pc_sel=01 & branch_taken`）或 JALR（`pc_sel=11`）在 EX 阶段解析。
- `flush_any = id_flush || ex_flush`；`flush_d` 为 `flush_any` 延迟 1 周期。
- **IF/ID flush = `flush_any || flush_d`（2 周期窗口）**：IMem 同步读使 `PC_reg` 超前 `inst_PC_reg` 一拍，跳转解析沿之后还有一条在途指令下一拍才到达 IF/ID 锁存点，需延迟窗口 `flush_d` 覆盖。
- **ID/EX flush = `ex_flush || stall`（1 周期）**：其锁存的陈旧指令与跳转解析同拍到达，`ex_flush` 即可清除，无需扩展。
- 刷新时，流水线寄存器控制输出变为 0，[core.sv](hdl_sv/core/core.sv) 向译码阶段注入 `NOP`（`addi x0, x0, 0`）。

### 寄存器文件与旁路

- [reg_file.sv](hdl_sv/core/reg_file.sv)：32×32 位，两个组合读端口，一个同步写端口。x0 硬连线为零。
- **写回旁路**（[decoder.sv](hdl_sv/core/decoder.sv)）：当 `rs1`/`rs2` 与 WB 阶段的 `write_reg` 匹配（且写使能有效）时，数据直接转发——避免写后读（RAW）的一周期停顿。
- **EX 阶段转发**（[core.sv](hdl_sv/core/core.sv)）：源操作数优先级 **EX/MEM 寄存器的 ALU 结果（Load 除外） > MEM/WB 寄存器的写回数据 > ID/EX 默认值**。EX/MEM 转发显式排除 Load（数据尚未就绪），该场景由 Load-Use stall 处理。

### 存储器接口

- `IBusIf` / `DBusIf`：SystemVerilog interface，通过 `modport master/slave` 实现 CPU↔存储器通信。
- `IMemTop` / `DMemTop`：为单元测试封装的顶层模块，将 interface 端口展开为普通信号端口。
- DMem 支持通过 `$readmemh` 从 hex 文件初始化，用于 C 程序测试。

### C 测试流程

1. [my_c_test/src/](my_c_test/src/) 中的 C 源码 → 使用 `riscv64-unknown-elf-gcc` 交叉编译（`-march=rv32i -mabi=ilp32 -O0 -ffreestanding`）。**可 `#include <stdio.h>`**——[bsp/libc/](my_c_test/bsp/libc/) 提供了最小 `printf`（支持 `%d %u %x %X %c %s %%`），输出写入 DMem `0x2800` 起的控制台缓冲。
2. 链接 [bsp/crt0.s](my_c_test/bsp/crt0.s)（设置栈指针 `0x4000`、调用 `main`、返回后写 `0x2000=1` 完成标志）和 [bsp/link.ld](my_c_test/bsp/link.ld)（程序起始地址 `0x00000000`），尾部 `-nostdlib -lgcc`（libgcc 提供软件乘法 `__mulsi3` 等，RV32I 无 M 扩展）。
3. `objcopy -O verilog` 生成 hex 文件（含 `@address` 标记，text/rodata/data 连续排布）。
4. [my_c_test/testcases/test_core_program.py](my_c_test/testcases/test_core_program.py) 通用脚本解析 `@address`，把**同一份镜像同时灌入 IMem 与 DMem**（IMem 取指令；DMem 提供字面量池/.data/.rodata——corex 的 IMem/DMem 地址空间独立，数据访问全走 DMem）。运行核心，轮询 `0x2000` 完成标志后检查结果：DMem 字或 `0x2800` 控制台字符串。所有 C 程序共用一个脚本（内置 `PROGRAMS` 注册表），不再为每个程序单独写 cocotb 脚本。

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

1. 编写 `my_c_test/src/<name>.c`——结果有两种检查方式：
   - 写 DMem：结果写入 `0x1000` 起始（如 `*(volatile int*)0x1000 = result`），结束前写 `*(volatile int*)0x2000 = 1`；
   - 或直接 `printf(...)`（`#include <stdio.h>`），输出自动落到 `0x2800` 控制台缓冲。两者可混用。
2. 在 `my_c_test/testcases/test_core_program.py` 的 `PROGRAMS` 注册表加一行：
   - DMem 检查：`"<name>": (<max_cycles>, {<字节地址>: <期望值>})`（期望值为 `list` 时从该地址起连续比对多个字）；
   - printf 检查：`"<name>": (<max_cycles>, {"console": "期望字符串"})`。
   **无需再写新的 cocotb 脚本**。
3. 运行 `make TEST=<name>` 编译，然后 `make run TEST=<name>` 运行。

> 现有 22 个程序：10 个原始程序（adder/sum/jar/crc32/factorial/fibonacci/sort/binary_search/
> soft_mul_bit/str_toggle）+ 12 个来自 [c_test/](../c_test/) 三人（zsq/ljt/dim）的程序
> （zsq_* 5 个、ljt_* 6 个、dim_transform）。其中 ljt_* 6 个为 **c_test 原始源码不改动**，
> 直接经 printf 输出检查（验证字节访存与字面量池加载）。

## 注意事项

- Verilator 源码内置于 [verilator/](verilator/) 目录（v5.040 版本）。该目录有自己的 `.git`——顶层 `.gitignore` 将其排除在主仓库之外。
- `sim_build/` 是 Verilator 构建输出目录，已被 gitignore 忽略。
- `CoreTop` 的 `program_address` 输入用于设置初始 PC；在 `start` 脉冲或复位时锁存。
- 所有 HDL 模块的作者信息记录在文件头部注释中（Ran Ji、Chun Yang、Ziqing Lin）。
- 由于有些模块的测试是初期编写（如test_ifu_all.py），由于端口名不一致有可能无法运行，测试时优先运行test_core_lzq.py和test_core_all.py，然后运行c语言测试程序
- 指令集覆盖：**RV32I 已完整支持访存宽度**（LB/LBU/LH/LHU/LW + SB/SH/SW，字节使能按地址低位生成）。FENCE/ECALL/EBREAK 作 NOP 流过（无异常处理）。M 扩展未实现（乘法/除法用 libgcc 软件例程 `__mulsi3` 等，链接时 `-lgcc`）。
- 已知预存在的单元测试缺陷（与 RTL 改动无关，未修复）：`sim/unit/core/test_decoder.py` 的 `t_decode_LUI`/`t_decode_AUIPC` 驱动 `extend_sel=1`（S 型编码）却断言 U 型立即数；`test_control_unit.py` 的 `t_ctrl_LUI`/`t_ctrl_AUIPC` 断言 `extend_sel==1`（RTL 实际为 `3'b011`）及 `t_ctrl_unsupported_opcode`。均为初期测试对 `extend_sel` 编码的错误假设。


## 配置文件自我维护规则 (Self-Maintenance)

- **更新机制**：每当项目中新增了核心架构变动、新的常用命令（如 Makefile 目标）、或新的工程规范时，请**主动更新本 `CLAUDE.md` 文件**。
- **添加新指令**：当我对你说 *“记住这个操作/以后都这么做”* 时，请将相关流程作为规范追加到本文件的 `Custom Instructions` 章节中。
