# 开发对话日志（DIALOGUE LOG）

> 本文件由 `dialogue-log` skill 自动整理 Claude Code 对话生成，按日期分章、可累加。
> 分类：🧭 架构设计决策 / 🐞 排错过程 / 💡 经验教训 / ❓ 疑问解答 / 💬 复杂讨论。
> 内容由 Claude 提炼，真实来自对话；不要手动删除已记录的章节。

---

## 2026-08-14

### 💬 复杂讨论
- **stall vs flush**：两者都会在流水线里插入"气泡"，但语义相反——**flush 是取消**（作废一条已进入流水线的指令、PC 已转向），**stall 是延迟**（冻结一条指令等数据、PC 不动）。被 stall 的指令之后真实执行；被 flush 的指令永远不执行。stall 需要 IMem `hold` 组合冻结 `rdata_q`，因为 `PC_reg` 超前 `inst_PC_reg` 一拍。
- **PipelineReg 控制 vs 数据通路**：ctrl 是"指令的身份证 + 处理指令"（valid、reg_write、alu_op…），data 是"指令操作的对象"（PC、rs1_data、rd…）。同一个 `en` 同步门控两者；flush 只清控制、数据保持——数据的合法性完全由 ctrl 的 valid 位授予。
- **EX 数据前推**：在 EX 阶段从最近的流水线寄存器截取最新值，解决"指令还没写回、后面指令就要读"的 RAW。源1 = EX/MEM 的 ALU 结果（**排除 Load**，因为 Load 在 MEM 阶段只有地址没有数据）；源2 = MEM/WB 的写回数据；优先级 源1 > 源2 > 寄存器文件默认值。Load 的"空窗期"由 Load-Use stall 补上，数据就绪后再从源2 转发。

### 🧭 架构设计决策
- **ID/EX 的 ctrl 里"名义必要"只有 valid 和 pc_sel**：`pc_sel` 直接参与 `ex_flush` 自判定（不清零会造成组合自激、流水线死锁），必须随 flush 归零；其余控制位挪到 data + 消费点 valid 门控也功能等价，但统一放 ctrl 是"约定优于配置"——语义内聚、防御散落的门控漏洞。
- **创建 dialogue-log skill**：driver 负责机械部分（定位 transcript、解析、按日期章节合并追加），Claude 负责精炼排版；日志以 `## YYYY-MM-DD` 分章、按 `### 分类` 合并，实现"可累加"。

### ❓ 疑问解答
- **"停顿不也是 NOP 吗？"** → 气泡相同、语义不同：flush 的 NOP 代替"被取消的指令"，stall 的 NOP 代替"等待的空拍"；被 stall 的指令之后真实执行，flush 的指令永远不会。
- **"控制信号和数据信号有关系吗？"** → 有：同一个 `en` 同步推进、ctrl 的 valid 位决定数据是否被下游采信、flush 只清控制不清数据（"打无效标签"而非"擦除"）。
- **"ID/EX 的 ctrl_in 只有 valid 必要，其他也能放 data？"** → 功能上成立（EX/MEM 输入处已有 `valid ? x : 0` 门控兜底），但 `pc_sel` 必须留在 ctrl（参与 flush 自判定）。

### 💡 经验教训
- 判断信号放 ctrl 还是 data，问两个问题：① flush 后它必须是已知的无效值吗？（valid、pc_sel 是）② 它保持旧值会污染下游且没有门控兜底吗？任一为"是"→ 放 ctrl。
- 合并/边界查找要显式处理分隔符：当日章节的结束边界是下一个 `## ` **或** `---` 分隔线，否则追加会越界到下一章节（本日在 dialogue.py 开发中踩到并修复）。


---

## 2026-08-13

### 🧭 架构设计决策
- **ifu.sv 的 fetch 用时序逻辑**：目的是让取指请求与 `PC_reg` 更新对齐在同一时钟沿，复位撤销后 PC 先稳定一拍再真正取指。实际等价于 `fetch <= ~rst`，三冗余分支简化为 `if (rst) fetch<=0; else fetch<=1`（行为不变）。
- **IMem hold 必须保留**：`hold=stall` 由组合逻辑驱动，停顿时同步冻结 `rdata_q`。因为 `PC_reg` 超前 `inst_PC_reg` 一拍，停顿时 PC_reg 冻结在 X+4、inst_PC_reg 在 X，若 `rdata_q` 继续随 req 锁存会锁存 mem[X+4] 与 inst_PC=X 错位。**不能**用"stall 拉低 fetch"替代——fetch 是时序信号晚一拍生效，无法在一拍 stall 内抑制锁存。
- **Claude Code skill 目录约定**：只识别目录形式 `skills/<name>/SKILL.md`；扁平 `skills/<name>.md` 不被加载；skill 列表在会话启动时加载、不热更新。

### 🐞 排错过程
- **HAS_HOLD(0) 破坏 load-use stall**：曾尝试去掉 hold 以简化设计。现象：`test_core_load_store` 失败，x5 读回 0。根因：去掉 hold 后 stall 期间 `rdata_q` 锁存下一条指令 mem[X+4]，与 inst_PC=X 错位，stall 结束 IF/ID en=1 采入错位数据覆盖保持中的指令。修复：恢复 HAS_HOLD(1)，仅保留 fetch 冗余分支简化。
- **/generate_handover 不生效**：文件在项目级 skill 目录、frontmatter 有效，但命令不出现。根因：skill 列表会话启动时加载 + 扁平 .md 格式不被识别。解决：改用目录形式 skill 并通过 skill-generator 重建为 `handover`。
- **test_ifu_all.py 全部失败**（`Ifu contains no child object named JAL_target`）：预存在问题——测试引用旧端口名（JAL_target/JALR_target/pc_sel_execute），与当前 ifu.sv 端口（id_jal_target/ex_pc_sel 等）不匹配，与本次修改无关。`test_core_all.py` 编译失败则是因为引用了不存在的 `core_new.sv`。

### 💡 经验教训
- **重构前先看测试覆盖**：core 测试（test_core_lzq.py）只断言最终寄存器值、不断言精确周期数，给出重构空间；但 IFU 单元测试精确断言 stall 行为，是重构最可能破坏的点。
- **测试基线**：优先 test_core_lzq.py / test_core_all.py / C 程序测试；早期单元测试（test_ifu_all.py 等）因端口名不一致可能无法运行，勿以它们断言功能。
- **CLAUDE.md 自我维护**：核心架构变动后主动更新 CLAUDE.md 使其与代码一致——本日把"三级流水线"、"stall 未实现"等过时描述更新为五级流水线 + 已实现 Load-Use stall。

### ❓ 疑问解答
- **fetch 为什么不是组合逻辑** → 与 PC_reg 对齐 + 复位撤销后先稳定一拍再取指；`fetch <= ~rst` 即全部语义。
- **为什么 IF/ID 需要 2 周期 flush 窗口** → IMem 同步读（rdata 滞后 addr 一拍），`PC_reg` 超前 `inst_PC_reg` 一拍，跳转时两条在途指令 I_{A+8}、I_{A+12} 分两拍到达 IF/ID 锁存点，需 `flush_any || flush_d` 覆盖两个沿。
- **I_TARGET 在 N+4 沿进入 IF 第一拍？** → 对。"进入 IF 第一拍" = PC_reg 更新（地址请求发出）。沿 N+4 PC_reg 切到 TARGET，即 I_TARGET 的第一拍开始。

### 💬 复杂讨论
- **"IF 阶段有两个时钟周期"的准确表述**：IF 吞吐率仍是每拍一条指令，准确说法是 **IF 内部取指数据通路是一条 2 拍流水**（PC_reg → rdata_q → IF/ID），同一时刻 2 条指令在飞行；不是 IF 被卡 2 拍。
- **IMem 没有和 flush 相连，为什么还能正确 flush？** → flush 作用于 IF/ID 寄存器，覆盖同步读延迟产生的"在途指令"到达 IF/ID 锁存点的时刻；IMem 本身无感知，靠 2 周期窗口补足。

