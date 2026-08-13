# COREX 开发交接文档（Handover Document）

> 由 `handover` skill 基于实际代码生成（collect.py 快照 + 源码精读）。
> 生成日期：2026-08-13

---

## 1. 项目概述

**项目名称**：COREX（Co-modeling RISC-V Example Core）

**定位**：北京大学微处理器研发中心（MPRC）的 RV32I 教学示例核，用 SystemVerilog 实现，用于教学演示与 Co-modeling 验证方法研究。

**实际流水线结构**：**五级** `IF → ID → EX → MEM → WB`（`core.sv` 头注释与代码均为五级；注意 `CLAUDE.md` 仍写"三级流水线"，已过时，见 §5）。

**技术栈与工具链**：
- RTL：SystemVerilog（逻辑类型、interface/modport、参数化模块）
- 仿真：Verilator 5.040 + cocotb 2.0.1（Python 3.10，conda 环境 `corex_env`）
- 集成测试：`riscv64-unknown-elf-gcc` 交叉编译 C 程序 → objcopy 生成 hex → cocotb 加载到 IMem 运行
- 构建：Make（`my_c_test/Makefile`）与 pytest runner

**作者**：Ran Ji（core.sv / ifu.sv / decoder.sv / ALU.sv）、Chun Yang（imem.sv / ibus_if.sv / pipeline_reg.sv）、Ziqing Lin（dmem.sv / dbus_if.sv / reg_file.sv）。

---

## 2. 架构与核心设计

### 2.1 顶层模块结构

```
                     CoreTop (core.sv)
                            │
        ┌───────────────────┼───────────────────┐
        │                   │                   │
      Ifu (ifu.sv)    Decoder + ControlUnit  execute + ALU      DMem (dmem.sv)
      ┌─取指 IF────────┐  ┌─ID──译码────┐   ┌─EX─执行────┐   ┌─MEM 访存─┐
      │ PC_reg          │  │ 字段/立即数   │   │ ALU_Control│   │ 字节写/读 │
      │ inst_PC_reg     │  │ 写回旁路      │   │ 操作数 mux │   │          │
      │ next_PC mux     │  │ 目标地址      │   │ 分支判断   │   │          │
      └────────────────┘  └─────────────┘   └────────────┘   └──────────┘
              │ IF/ID 寄存器       │ ID/EX 寄存器    │ EX/MEM 寄存器 │ MEM/WB 寄存器
              │ (pipeline_reg.sv) │ (pipeline_reg)  │ (pipeline_reg)│ (pipeline_reg)
              └───────────────────┴─────────────────┴───────────────┘
                                                    │
                                              RegFile (reg_file.sv) ← WB 写回
```

流水线寄存器共 **4 个实例**：IF/ID、ID/EX、EX/MEM、MEM/WB，均由通用参数化模块 `PipelineReg` 例化。控制通路与数据通路分离（见 §2.3）。

### 2.2 数据流与控制流

**数据通路**（每条指令逐级前移）：
1. **IF**：`Ifu` 用 `PC_reg` 向 `IMem` 发出取指请求（`req/addr` → `rdata/ack`），输出 `instruction`（`rdata_q`）、`inst_PC`、`valid`（`ack`）。
2. **ID**：`Decoder` 拆字段、生成立即数（I/S/B/U/J 五类）、读寄存器文件（带 WB 写回旁路）、计算 `branch_target`/`JAL_target`；`ControlUnit` 依 opcode 生成主控制信号。
3. **EX**：`execute` 将 ALUOp+funct 编码为 6 位 `ALU_Control`，选择操作数（rs1/PC/PC+4/0 与 rs2/imm），`ALU` 计算；同时判断分支（`branch_taken = branch_op & cmp_out`）、计算 `JALR_target`。
4. **MEM**：`DMem` 读写，写路径带字节使能（`wbe`），读为**异步**（组合 `rdata`）。
5. **WB**：写回 mux 在 `mem_to_reg` 为真时选访存数据，否则选 ALU 结果，写入 `RegFile`。

**控制流（跳转）**：
- **JAL** 在 **ID 阶段**解析（`next_PC_sel=10`，见 `ControlUnit`），目标 `PC + uj_imm`。
- **Branch / JALR** 在 **EX 阶段**解析（`next_PC_sel=01`/`11`）。
- `Ifu` 的 `next_PC` 优先级：**EX 跳转 > ID 跳转 > PC+4**。

**Hazard 与流水线控制**（`core.sv`）：
- `stall = load_use_hazard`：EX 阶段 Load 的目标寄存器被 ID 阶段指令作为源寄存器使用 → **Load-Use 停顿 1 拍**（IF/ID `en=0` 保持、ID/EX 被 `id_ex_flush` 清空）。
- `id_flush`：JAL（ID 解析）。
- `ex_flush`：Branch taken / JALR（EX 解析）。
- `flush_any = id_flush || ex_flush`；`flush_d` 为 `flush_any` 延迟 1 拍。
- **IF/ID flush = `flush_any || flush_d`（2 周期窗口）**；**ID/EX flush = `ex_flush || stall`（1 周期）**。

### 2.3 关键机制

#### (1) 同步读存储器延迟 → IF/ID 需要 2 周期 flush 窗口

`IMem` 为**同步读**（`rdata_q <= mem[addr]`，地址沿 K 送、数据沿 K+1 出）。`Ifu` 内部因此形成两拍深的小流水：

```
沿 K:   PC_reg = X
沿 K+1: rdata_q = mem[X]，inst_PC 跟到 X
沿 K+2: IF/ID 锁存 {mem[X], X}
```

即 **`PC_reg` 超前 `inst_PC_reg` 一拍**，IF 输出端始终有 1 条"在途"指令。当跳转在 EX 解析（沿 N+4 `PC_reg` 切到 TARGET）时，IF 里残留两条顺序取指指令，且到 IF/ID 锁存点的时刻**错开一拍**：

| 在途指令 | 到达 IF/ID 锁存点 | 被谁清除 |
|---------|------------------|---------|
| `I_{A+8}`（已出 rdata_q） | 沿 N+4（跳转解析同拍） | `flush_any` |
| `I_{A+12}`（同步读在途） | 沿 N+5（下一拍） | `flush_d`（延迟窗口） |

因此 `if_id_flush = flush_any || flush_d` 必须覆盖两个沿。**ID/EX 只需 1 拍**：它锁存的陈旧指令与跳转解析同拍到达（`ex_flush` 清除），且下一拍 IF/ID 已被 flush、`id_valid=0` 使 ID/EX 自然锁存无效条目。

#### (2) IMem `hold` 门控（stall 时的数据冻结）

stall 期间 `PC_reg` 冻结在超前地址 `X+4`、`inst_PC_reg` 冻结在 `X`。若 `rdata_q` 继续随 `req` 锁存，会把 `mem[X+4]`（下一条指令）拉进输出，与 `inst_PC=X` 错位并覆盖 IF/ID 等待的指令。因此 `hold=stall` 由**组合逻辑**驱动，在同一拍冻结 `rdata_q`（`imem.sv`：`req && gnt && !hold`）。**不能用"stall 时拉低 fetch"替代**——`fetch` 是时序信号晚一拍生效，对仅 1 拍的 Load-Use stall 来不及抑制。

#### (3) 流水线寄存器：控制通路可 flush、数据通路不 flush

`PipelineReg`（`pipeline_reg.sv`）：
- **控制通路**：优先级 `reset > flush > enable`，flush/reset 时 `ctrl_q` 载入 `RESET_VALUE`。
- **数据通路**：**无 reset/flush**（PPA 优化），仅受 `en` 控制；数据有效性完全由控制通路（valid 位）保证。flush 时 `ctrl_out=0`，`core.sv` 向译码注入 NOP（`id_instruction_real = id_valid ? id_instruction : NOP`，即 `addi x0,x0,0`）。

#### (4) 写回旁路（Decoder 内）与 EX 阶段转发

- **WB→ID 旁路**（`decoder.sv`）：`rs1`/`rs2` 等于 WB 阶段 `write_reg` 且写使能有效时，直接取 `write_data`，避免普通 RAW 一周期停顿。
- **EX 阶段转发**（`core.sv`）：源 1 优先级 **EX/MEM 转发（非 Load 指令的 ALU 结果）> MEM/WB 转发（写回数据）> ID/EX 默认值**。EX/MEM 转发排除 Load（`!mem_read`），因为 Load 数据尚未就绪 → 这正是触发 Load-Use stall 的场景。

#### (5) 总线接口

- `IBusIf`：`req/addr` → `gnt/ack/err/rdata`，modport `master/slave`。
- `DBusIf`：`read/write/addr/wdata/wbe` → `gnt/rack/wack/err/rdata`，读响应 `rack` 为组合（异步读），写响应 `wack` 为同步。
- `IMemTop`/`DMemTop`：为单元测试将 interface 展开为普通端口；`DMemTop` 支持 `INIT_FILE`（`$readmemh`）加载 hex。

---

## 3. 关键模块与目录

### 3.1 文件目录映射（hdl_sv/core/）

| 文件 | 职责 |
|------|------|
| [core.sv](corex/hdl_sv/core/core.sv) | 顶层 `CoreTop`：五级流水线、Hazard/Flush/Stall 控制、EX 转发、4 个流水线寄存器例化 |
| [ifu.sv](corex/hdl_sv/core/ifu.sv) | IF 取指：PC_reg / inst_PC_reg / next_PC 选择、fetch 请求控制 |
| [imem.sv](corex/hdl_sv/core/imem.sv) | 指令存储器：同步读、`hold` 冻结、`ack` 时序 |
| [decoder.sv](corex/hdl_sv/core/decoder.sv) | ID 译码：字段/立即数、写回旁路、目标地址、字节使能 |
| [control_unit.sv](corex/hdl_sv/core/control_unit.sv) | 主控制信号：ALUOp、操作数选择、extend_sel、next_PC_sel 等 |
| [execute.sv](corex/hdl_sv/core/execute.sv) | EX 执行：ALU_Control 编码、操作数 mux、分支/JALR 目标 |
| [ALU.sv](corex/hdl_sv/core/ALU.sv) | 6 位 ALU_Control 的 RV32I 运算/比较单元 |
| [pipeline_reg.sv](corex/hdl_sv/core/pipeline_reg.sv) | 通用流水线寄存器（控制可 flush、数据无 reset） |
| [reg_file.sv](corex/hdl_sv/core/reg_file.sv) | 32×32 寄存器堆：双组合读、单同步写、x0 硬连线为 0 |
| [dmem.sv](corex/hdl_sv/core/dmem.sv) | 数据存储器：异步读、字节使能写、INIT_FILE |
| [ibus_if.sv](corex/hdl_sv/core/ibus_if.sv) | 指令总线 interface（master/slave modport） |
| [dbus_if.sv](corex/hdl_sv/core/dbus_if.sv) | 数据总线 interface（master/slave modport） |

### 3.2 核心模块接口表

**Ifu**（ifu.sv）

| 信号 | 方向 | 宽度 | 说明 |
|------|------|------|------|
| `start` | input | 1 | 脉冲：锁存初始 PC 并开始取指 |
| `stall` | input | 1 | 停顿：冻结 PC/inst_PC，并经 `hold` 冻结 IMem |
| `program_address` | input | 32 | 初始 PC（复位或 start 时锁存） |
| `id_pc_sel` / `ex_pc_sel` | input | 2 | ID/EX 阶段跳转选择（10=JAL；01+branch_taken / 11=JALR） |
| `id_jal_target` / `ex_jalr_target` / `ex_branch_target` | input | 32 | 跳转目标 |
| `instruction` | output | 32 | 取回的指令（`rdata_q`） |
| `inst_PC` | output | 32 | 与 `instruction` 配对的 PC |
| `valid` | output | 1 | 取指有效（= IMem `ack`） |

**execute**（execute.sv）

| 信号 | 方向 | 宽度 | 说明 |
|------|------|------|------|
| `ALU_Operation` | input | 3 | ALU 类别：000 R-type、001 I-type、010 Branch、011 JAL/JALR、100/101/110 走默认 ADD |
| `ALU_ASrc` | input | 2 | A 操作数：00 rs1、01 PC、10 PC+4、11 0（LUI） |
| `ALU_BSrc` | input | 1 | B 操作数：0 rs2、1 立即数 |
| `regRead_1/2` | input | 32 | 源操作数（来自 EX 阶段转发 mux） |
| `branch_op` | input | 1 | 是否分支指令 |
| `ALU_result` | output | 32 | 运算结果 |
| `branch_taken` | output | 1 | 分支成立（= branch_op & cmp_out） |
| `JALR_target` | output | 32 | JALR 目标 = (rs1 + imm) & ~1 |

**Decoder**（decoder.sv）

| 信号 | 方向 | 宽度 | 说明 |
|------|------|------|------|
| `instruction` | input | 32 | 待译码指令 |
| `extend_sel` | input | 3 | 立即数类型：000 I、001 S、010 B、011 U、100 J |
| `reg_write` / `write_reg` / `write_data` | input | 1/5/32 | WB 写回信号（旁路用） |
| `rs1_data` / `rs2_data` | output | 32 | 寄存器读数（含 WB 旁路） |
| `branch_target` / `JAL_target` | output | 32 | 分支/JAL 目标地址（PC + 立即数） |
| `mem_wbe` | output | 4 | 存储字节使能（SB=0001/SH=0011/SW=1111） |

---

## 4. 构建、仿真与验证

### 4.1 环境搭建

```bash
conda activate corex_env          # Python 3.10 + cocotb 2.0.1 + Verilator 5.040
```
前置条件：`riscv64-unknown-elf-gcc` 交叉编译器（C 程序测试用）。

### 4.2 测试命令（以实际可用基线为准）

```bash
# 单元测试（cocotb + Verilator，在 corex/ 下运行）
SIM=verilator python3 -m pytest -v sim/unit/core/test_decoder.py      # 单模块
SIM=verilator python3 -m pytest -v sim/unit/core/test_core_lzq.py     # 核心集成（推荐基线）

# C 程序全流水线集成测试
cd my_c_test
make TEST=adder            # 编译 C → hex
make run TEST=adder        # 编译 + 运行对应 cocotb 测试
make run-all               # 全部 C 测试
```

**验证优先级（重要）**：`test_core_lzq.py`、`test_core_all.py` → C 程序测试（adder/sort/fibonacci/crc32…）。部分早期单元测试（`test_ifu_all.py` 等）因端口名与 RTL 不一致**无法运行**，勿以它们断言功能。

### 4.3 构建源文件依赖顺序

所有 cocotb 测试必须按依赖顺序包含全部 HDL 源文件（参考 `my_c_test/testcases/` 模式）：

```
control_unit.sv → ibus_if.sv → dbus_if.sv → imem.sv → dmem.sv →
reg_file.sv → pipeline_reg.sv → decoder.sv → ALU.sv → execute.sv →
ifu.sv → core.sv
```

### 4.4 波形查看

仿真默认不 dump 波形。如需要，在 cocotb 测试中通过层次路径观察信号（如 `dut.u_ifu.PC_reg`、`dut.u_ifu.next_PC`）；`core.sv` 内置 `DEBUG_CORE` 宏（`always @(posedge clk)` 逐周期打印流水线状态），可在编译时开启查看指令流与 flush 时机。

---

## 5. 已知问题与待办

### 5.1 文档与代码不同步（已解决：2026-08-13）

- **原问题**：CLAUDE.md 写"三级流水线 IF→ID/EX→MEM/WB"、称"无 ID/EX 流水线寄存器"、称"stall 固定为 1'b0（未实现流水线停顿）"——实际为**五级**（IF→ID→EX→MEM→WB）、4 个流水线寄存器实例、**已实现 Load-Use 停顿**。
- **处理**：已按 `core.sv` 实际实现重写 CLAUDE.md 架构章节（五级流水线、stall/flush 机制、EX 转发），与代码对齐。

### 5.2 测试基线问题（预存在）

- `test_ifu_all.py`：端口名与 ifu.sv 不一致（旧名 `JAL_target`/`JALR_target`/`pc_sel_execute` vs 现名 `id_jal_target`/`ex_jalr_target`/`ex_pc_sel`），无法运行。
- `test_core_all.py`：源文件列表引用了不存在的 `core_new.sv`（应为 `core.sv`），编译必失败。
- 这两处不影响功能验证（`test_core_lzq.py` 与 C 测试全绿），但会误导误用它们的开发者。

### 5.3 设计内的已知简化 / 待办

- **指令覆盖**：`ControlUnit` 定义了 `FENCES`/`SYSCALL` 等 opcode 但未实现对应控制；RV32I 其余指令（如 MISC-MEM、SRAI 特判已处理）需逐一确认。
- **异常/中断**：无（教学核）。
- **取指**：无 ICache / 分支预测器，每次跳转至少付出 flush 代价；`IMem` 无复位（BRAM 输出寄存器推断），`rdata_q` 复位后首拍为不确定值。
- **转发覆盖**：EX/MEM 转发显式排除 Load；Load-Use 用 1 拍 stall 处理，未用"转发 load 结果 + 停顿"之外的更优策略。
- `execute.sv` 的 `stall` 输入端口存在但内部未使用（预留）。
- `decoder.sv` 中 `JALR_target` 计算被注释（JALR 目标在 EX 阶段用 `regRead_1 + imm` 计算）。
- `ALU.sv` 的 `zero` 输出被注释，分支比较统一走 `cmp_out = ALU_result[0]`（比较结果均为 32 位 0/1，取 bit0 判定）。

---

## 6. 上手指引

### 6.1 推荐阅读顺序

1. **`core.sv`**：先建立五级流水线与 Hazard/Flush/Stall 的整体认知（本文件 §2 是它的浓缩版）。
2. **`ifu.sv`**：理解取指时序——同步读延迟、`PC_reg` 超前 `inst_PC_reg` 一拍、2 周期 flush 窗口的由来。
3. **`pipeline_reg.sv`**：流水线寄存器"控制可 flush、数据无 reset"的分工。
4. **`decoder.sv` + `control_unit.sv`**：译码与主控制信号。
5. **`execute.sv` + `ALU.sv`**：ALU_Control 编码与执行逻辑。
6. **`imem.sv` / `dmem.sv`**：存储器接口与时序。

### 6.2 第一个练习任务建议

**给 Load-Use 冒险加一个定向测试**：在 `sim/unit/core/test_core_lzq.py` 风格下新增一条 `lw` 紧接使用的指令序列，验证 stall 使 IF/ID 保持、ID/EX 清空、下一拍 Load 结果经 MEM/WB 转发。跑 `SIM=verilator python3 -m pytest -v sim/unit/core/test_core_lzq.py` 验证。此任务会强制你走一遍 §2.3 的 (1)(2)(4) 三条关键机制。

进阶可选：更新 `CLAUDE.md` 架构章节使其与五级流水线、Load-Use stall 的实现对齐（见 §5.1）。
