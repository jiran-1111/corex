# 开发对话日志（DIALOGUE LOG）

> 本文件由 `dialogue-log` skill 自动整理 Claude Code 对话生成，按日期分章、按问题分节、可累加。
> 每个 `## 日期` 章节下，以 `### 问题` 为小节，记录当天提出的问题：问题描述 / 我的 Prompt / Agent 回答。
> 内容由 Claude 提炼，真实来自对话；不要手动删除已记录的章节。

---

## 2026-08-13

### 问题：ifu.sv 的 fetch 为什么不是组合逻辑赋值？

- **问题**：用户在审视 ifu.sv 时注意到 `fetch` 用 `always_ff` 时序逻辑实现，疑问为什么不写成简单的组合赋值。
- **我的 Prompt**：
  > 我想知道为什么ifu.sv中的fetch为什么不是组合逻辑赋值
- **Agent 回答**：`fetch` 是**握手型请求状态**（req→ack），用 `always_ff` 是为了让取指请求与 `PC_reg` 的更新**在同一时钟沿对齐**：复位撤销后的第一个沿 `fetch` 置 1，但此时 `PC_reg` 读到的还是 `fetch` 旧值 0，于是 PC 先稳定在 `program_address` 一拍、下一拍才开始 +4 取指。若改组合赋值 `fetch=~rst`，复位撤销瞬间请求立即拉高、与地址不同步，且第一拍就 PC+4。另外发现 `start || stall` 分支与 `else` 结果相同，属冗余（等价于 `if(rst) fetch<=0; else fetch<=1;`）。

### 问题：ifu.sv 写法与 IMem hold 设计冗余吗？能否去掉？（排错：HAS_HOLD 破坏 load-use stall）

- **问题**：用户认为 `fetch` 分支冗余、IMem 的 `hold` 与 `req` 重复，询问是否需要修改。Agent 初判 hold 冗余、尝试去掉后暴露了核心时序 bug。
- **我的 Prompt**：
  > 感觉现在的写法有点冗余，包括imem的hold设计，感觉和req有点重复，请看看是否需要修改
- **Agent 回答**：按"语义重构"路径（`HAS_HOLD(0)` + stall 时拉低 `fetch`）修改后，`t_core_load_store` 失败——`lw x5` 读回 0 而非 0x13。**根因**：`PC_reg` 超前 `inst_PC_reg` 一拍（同步读延迟），stall 时两者冻结在不同地址（`PC_reg=X+4`、`inst_PC=X`）；去掉 hold 后 `rdata_q` 每拍锁存 `mem[X+4]` 与 `inst_PC=X` 错位，stall 结束 IF/ID `en=1` 采入错位数据，覆盖保持中的指令。"stall 拉低 fetch"也不可行——fetch 是时序信号晚一拍生效，load-use 只持续 1 拍，抑制来不及发生。**结论**：真正冗余只有 fetch 的 `start||stall` 分支，hold 必须保留（由组合信号驱动、与 stall 同拍冻结）。恢复 `HAS_HOLD(1)`、fetch 简化为 `if(rst) fetch<=0; else fetch<=1;`，行为零变化，核心测试 5/5 通过。顺带发现两个**预存在问题**（与本次无关）：`test_ifu_all.py` 引用旧端口名（JAL_target/pc_sel_execute）无法运行；`test_core_all.py` 引用了不存在的 `core_new.sv`。**经验**：重构前先看测试覆盖——核心测试只断言最终寄存器值（有重构空间），IFU 单元测试精确断言 stall 行为（最易被破坏）。

### 问题：为什么 IF/ID 需要 2 周期 flush 窗口？

- **问题**：想理解 IF/ID 的 `if_id_flush = flush_any || flush_d` 为什么需要把丢弃窗口延长一拍。
- **我的 Prompt**：
  > 不用修改代码，请给我讲解一下为什么id_if阶段需要2周期flush窗口
- **Agent 回答**：根因是 **IMem 同步读**：`rdata` 滞后 `addr` 一拍，`PC_reg` 超前 `inst_PC_reg` 一拍，IF 内部是 2 拍深的小流水（`PC_reg→rdata_q→IF/ID`），IF 输出端总有一条"在途"指令。EX 跳转解析沿（N+4）流水里残留**两条**陈旧指令且错开一拍到达 IF/ID 锁存点：`I_{A+8}` 在解析沿（`flush_any` 清掉）、`I_{A+12}` 下一拍才到（需 `flush_d` 清掉）——所以 IF/ID 必须覆盖两个沿。ID/EX 只需 1 拍：其锁存的陈旧指令与跳转解析**同拍**到达，且下一拍因 `id_valid=0` 自然变气泡。若 IMem 改组合读，在途指令消失，IF/ID 也只需 1 拍。

### 问题："IF 阶段有两个时钟周期"的说法准确吗？IMem 没连 flush 为什么 flush 还能生效？

- **问题**：用户提出自己的理解"IF 占两个时钟周期，且 IMem 不与 flush 相连，必须等 I_A+12 到 IF/ID 才能 flush"，需要精确化。
- **我的 Prompt**：
  > 我是否可以理解为IF阶段有两个时钟周期，但是imem并没有和flush相连，所以必须等I_A+12这个数据到IF_ID这个寄存器才可以flush
- **Agent 回答**：① 准确说法是 **IF 内部取指数据通路是一条 2 拍流水**（同一时刻 2 条指令在飞行），不是"IF 被卡 2 拍"；② **IMem 无感知**——只响应 `req/gnt/hold`，只要 req 有效就把 `mem[PC_reg]` 锁进 `rdata_q`，根本不知道跳转发生；flush 无法在源头阻止在途数据，只能等它到达 IF/ID 锁存点再拒绝锁存；③ 但 flush 不是"被动等待"——`flush_d <= flush_any` 在跳转解析沿**提前一拍**布好窗口，在途指令到达的那一拍 `if_id_flush` 早已为 1，在锁存点把它挡掉。

### 问题：在 N+4 沿时 I_TARGET 就进入 IF 的第一拍了吗？

- **问题**：验证"进入 IF 的第一拍"的准确时刻，并确认与 flush 窗口长度自洽。
- **我的 Prompt**：
  > 所以我可以理解为在N+4沿的时候I_TARGET就进入了if的第一拍
- **Agent 回答**：对。"进入 IF 第一拍" = **`PC_reg` 更新**（地址请求发出）。取指走"三拍"：沿 K 送地址 → K+1 同步读出数据 → K+2 锁入 IF/ID。沿 N+4 `PC_reg` 切到 TARGET，就是 I_TARGET 的第一拍开始（N+6 锁存）。三条指令在 IF 里首尾相接排队（I_{A+8}、I_{A+12} 被 flush，I_TARGET 正常锁存），"2 拍窗口"恰好等于**跳转解析时 IF 里已有的在途指令条数**——不多不少。

### 问题：/generate_handover 命令为什么输入后没有提示？

- **问题**：用户输入 `/generate_handover` 无任何命令提示，skill 文件看起来没问题。
- **我的 Prompt**：
  > 为什么我在终端输入/generate_handover没有看到提示呢
- **Agent 回答**：skill 列表在**会话启动时**扫描 `.claude/skills/` 加载、不热更新；`generate_handover.md` 是会话启动后才创建/改名的，当前会话根本不知道它存在。解决：**重启 Claude Code 会话**重新扫描。若仍不生效，检查：① 启动目录须含 `.claude/skills/`（在 `corex/` 子目录启动会去 `corex/.claude/skills/` 找，那里为空）；② 触发名严格取 frontmatter 的 `name`。

### 问题：如何创建一个叫 handover 的 skill？skill 目录形式是什么？（创建 handover + 生成交接文档）

- **问题**：需要创建一个分析当前项目并生成交接文档的 skill。
- **我的 Prompt**：
  > 帮我创建一个叫 handover 的 skill，用于分析当前项目并生成交接文档 HANDOVER.md
- **Agent 回答**：用 skill-generator 创建 `skills/handover/SKILL.md` + `collect.py`（driver：扫描 `hdl_sv/core/*.sv` 提取模块/端口、列出测试与构建命令，作为文档事实基础防止编造）。创建后 `handover` 立即出现在可用 skill 列表，也**解开了先前谜团**：该环境**只识别目录形式 skill**（`skills/<name>/SKILL.md`），扁平的 `skills/xxx.md` 不被加载——旧 `generate_handover.md` 从未被识别过。之后 `/handover` 按流程（快照→精读源码→六章节）生成 `corex/docs/HANDOVER.md`。

### 问题：CLAUDE.md 与实际代码脱节（三级 vs 五级流水线），如何按自我维护规则同步？

- **问题**：用户已在 CLAUDE.md 末尾添加"配置文件自我维护规则"，要求核心架构变动后主动更新 CLAUDE.md。
- **我的 Prompt**：
  > 请更新CLAUDE.md，并注意我添加了claude.md的自我维护规则
- **Agent 回答**：核对 core.sv 后逐段修正：项目概述"三级流水线"→"**五级流水线**"；流水线寄存器"两个实例"→"**四个实例**"（IF/ID、ID/EX 可 flush；EX/MEM、MEM/WB 无 flush）；`stall` 由"固定 0"改为"**已实现 Load-Use stall**"（判定条件、IF/ID 保持 + ID/EX flush + IMem hold 门控），区分 `id_flush`(JAL)/`ex_flush`(Branch/JALR)、明确 IF/ID 2 周期与 ID/EX 1 周期窗口成因；补 EX 阶段两级转发（EX/MEM 排除 Load > MEM/WB > 默认值）。并同步 HANDOVER.md §5.1 的"CLAUDE.md 与代码不同步"待办为**已解决**。**经验**：核心架构变动后主动同步 CLAUDE.md，避免文档与代码漂移。

---

## 2026-08-14

### 问题：stall 和 flush 的区别是什么？停顿不也是 NOP 吗？

- **问题**：用户对 stall 与 flush 都"插入气泡"感到困惑，认为停顿似乎也是 NOP。
- **我的 Prompt**：
  > 请告诉我stall和flush的区别是什么，停顿不是也是NOP吗？
- **Agent 回答**：两者都插入气泡但**语义相反**——**flush 作废指令**（PC 已转向，被取消的指令永远不执行），**stall 延迟指令**（PC 不动，指令保留、之后真实执行）。代码对照（core.sv）：`stall=load_use_hazard` 做三件事（IF/ID `en=0` 保持、ID/EX 被 `id_ex_flush` 清空、IMem `hold` 冻结 rdata）；flush 是 `id_flush`(JAL)/`ex_flush`(Branch/JALR) 把控制通路 valid 位清零。两者最终都靠 `id_valid ? id_instruction : NOP` 注入气泡，但 **NOP 代替的东西不同**：flush 的 NOP 代替"被取消的指令"（永不执行），stall 的 NOP 代替"等待的空拍"（指令还活着，停顿解除后带着真实执行语义继续走完流水线）。

### 问题：PipelineReg 的控制信号和数据信号有什么区别？两者有关系吗？

- **问题**：想理解 pipeline_reg.sv 中 ctrl 与 data 两类寄存器各自装什么、如何配合。
- **我的 Prompt**：
  > 请给我讲解一下这个pipeline_reg.sv中的控制信号和数据信号有什么区别，两者之间有关系吗？
- **Agent 回答**：**ctrl 是指令的"身份证 + 处理指令"**（valid 位 + 每阶段做什么：reg_write/mem_read/alu_op/pc_sel…），**data 是指令"实际携带和操作的数据"**（PC、rs1_data、rs2_data、rd、branch_target…）。两者关系：① 同一个 `en` 同步门控——stall 时 `en=0` 两条通路都不更新，整条指令整体冻结；② **flush 只清控制、不清数据**——data_q 残留旧值但被 valid=0"打上无效标签"，下游见到 valid=0 注入 NOP，脏数据不被采信，数据合法性完全由 valid 位授予；③ 优先级 `reset > flush > enable` 只在控制通路存在——数据通路无复位端口是 PPA 优化（省一半复位扇出），代价是复位后数据未知，但 valid=0 保证下游不采信。类比：data 是行李（没有判断力）、ctrl 是行李牌（valid=有效航班），flush 是撕行李牌、en=0 是暂停传送带。

### 问题：ID/EX 的 ctrl 里只有 valid 是必要的，其他也能放 data 吗？

- **问题**：用户推测 ID/EX 的 ctrl 里名义上只有 `valid` 必要，其余控制位放 data 也功能等价。
- **我的 Prompt**：
  > 所以我可以理解为，ID_EX_reg其实在ctrl_in的数据上，只有if_valid是必要的，其他数据也可以放在data_in是吗
- **Agent 回答**：**功能上成立**——消费点（core.sv:368-373）已用 `valid ? x : 0` 门控兜底，把这些位挪到 data、flush 后保持旧值也无害。**但有一个例外必须留 ctrl：`pc_sel`**——它参与 `ex_flush` 自判定（`ex_flush=(pc_sel==01 && branch_taken) || pc_sel==11`，结果又驱动 ID/EX flush），若放在 data 不清零，上一条 JALR 的 `pc_sel=11` 残留会让 `ex_flush` 恒 1、流水线死锁。**判断标准**：① flush 后必须是已知无效值？② 保持旧值会污染下游且无门控兜底？任一为"是"→ 放 ctrl。设计者统一放 ctrl 是"约定优于配置"——语义内聚（ctrl 与 valid 同生共死）、防御散落的门控漏洞；那几行门控是双保险而非依赖。**经验**：判断信号放 ctrl 还是 data，就看"flush 后它是否必须是无效值 / 是否会被直接读做判定"。

### 问题：EX 阶段这段数据前推（Forwarding）是什么意思？

- **问题**：用户选中 core.sv 的 EX 前推代码段（324-344 行），询问其机制。
- **我的 Prompt**：
  > 请给我讲解一下这段数据前推是什么意思
- **Agent 回答**：前推解决 **RAW 冒险**——不等 WB 写回，在 EX 阶段从流水线里截最新值。两个转发源：**源1 = EX/MEM 寄存器的 ALU 结果**（但**排除 Load**，因为 Load 在 EX 算的是地址、数据要 MEM 才读回，转发了就把地址当数据）；**源2 = MEM/WB 的写回数据**（已是写回 mux 选好的最终值，Load 数据此时也拿到了）。优先级 **源1 > 源2 > 寄存器文件默认值**（最新写者才有效）；`rd != x0` 过滤（x0 硬连线为 0）。Load 的"空窗期"由 Load-Use stall 补上——数据就绪后进 WB，再从源2 转发。源1 的 `!mem_read` 排除是双保险，防止任何路径把地址错当数据。

### 问题：如何把对话整理成按日期分章、可累加的日志 skill？（创建 dialogue-log）

- **问题**：需要把对话中的复杂讨论、排错、经验、设计决策、疑问自动整理成排版整洁、以日期分章且可累加的 Markdown 文档。
- **我的 Prompt**：
  > 我希望生成一个把我们的对话中复杂的讨论、排错过程、得到的经验、架构设计决策、我有疑问的问题等等内容，自动整理并导出成一份排版整洁的.md文档，且该文档以日期为章节可以进行累加。
- **Agent 回答**：创建 `dialogue-log` skill——`SKILL.md`（流程说明）+ `dialogue.py`（driver 干机械活：`list/latest` 找 transcript、`digest` 解析素材、`append` 按 `## 日期` 分章并按 `### 小节` 合并实现可累加、`init` 初始化头），Claude 干精炼排版。开发中踩到并修复三个 bug：`find_corex` 只向上查找（corex 是子目录，改为向上 + 直接子目录双向）、digest 的 `files` 是 set 不能切片、append 合并时块尾查找越过 `---` 分隔线把内容插到分隔线之后。**经验**：合并/边界查找要显式处理分隔符——当日章节的结束边界是下一个 `## ` **或** `---` 分隔线，否则追加会越界到下一章节。

---

## 2026-08-15

### 问题：EX/MEM 输入为什么用 valid 门控"副作用使能位"，而不是直接把 id_ex_ctrl_out 送给 ex_mem_reg 的 flush？
- **问题**：用户看到 core.sv 368-372 行用 `valid ? 位 : 0` 门控 reg_write/mem_write 等，疑惑为何不像 IF/ID、ID/EX 那样用 flush 信号作废。
- **我的 Prompt**：
  > ex_mem的data_in要判断id_ex_ctrl_out_valid是否为0，是因为如果出现flush该条指令就作废所以这里要为0吗？但我觉得这里很奇怪，为什么不直接把id_ex_ctrl_out端口送给ex_mem_reg的flush
- **Agent 回答**：这 4 行门控不是"响应 flush 作废"，而是**净化进入 MEM 的副作用位**；EX/MEM 故意不连 flush（`.flush(1'b0)`），因为作废只发生在 ID/EX，EX 之后只有"有效指令或气泡"。三个理由：①**语义错位**——JALR 自己触发 `ex_flush` 却必须正常进 MEM/WB 写返回地址，若把 `id_ex_ctrl_out` 连去 EX/MEM 的 flush 等于每周期作废当前指令自己；②**时域不同**——flush 是沿级清下一条，门控是组合净化当前将锁存的这条；③**设计分工**——只有 IF/ID（打掉在途误取）、ID/EX（打掉 stalled 半条）需要 flush，EX/MEM、MEM/WB 后的流水线只会有"有效指令或气泡"，气泡由 valid 位自然忽略，不需要主动作废能力。

### 问题：如果 EX/MEM 输入没有 valid 三目门控、只是单纯赋值，会有什么问题？
- **问题**：用户追问 369-372 行的三目门控去掉后（单纯赋值）的后果。
- **我的 Prompt**：
  > 如果这段代码没有这样的三目运算符，只是单纯赋值，会有什么问题？
- **Agent 回答**：在当前完整代码下去掉**功能等价**——上游三层保证（ID/EX flush 整体清零、ID 输入门控 + NOP 注入、MEM/WB 输入门控）已使 `valid=0 ⟹ reg_write=0`，跑不出任何错误。但它是**防御性编程**，钉死"无效指令绝不触碰副作用部件"不变式。关键是它**结构性支撑了 `mem_wbe` 故意不门控**（373 行）：设计者只门控 4 个"使能开关"、不门控数据字段（数据残留无害，因为下游只在开关为 1 时才使用）；而 DMem 直接消费开关位（无 valid 门控），若去掉门控，`mem_write` 残留 1 会真的写内存。思想实验：未来若有人把 ID 输入门控也改成单纯赋值，NOP（addi 的 regWrite=1）会产生 `valid=0,reg_write=1` 不一致流到 MEM，这层门控正好兜底。三层防御（ID → EX/MEM → MEM/WB）每层当前都冗余，但删任一层其余仍兜底，让不变式不依赖读者追踪完整链条。

### 问题：为设计简洁能否只保留一个 ID/EX 的 flush？flush_d 是什么意思？
- **问题**：用户认为 flush 体系复杂，问能否只留 ID/EX flush 并删掉其他门控；同时不解 flush_d 的作用。
- **我的 Prompt**：
  > 所以如果为了设计的简洁性考虑，是不是只保留一个ID/EX的flush就可以了，其他门控可以删掉？还有我还是没有理解这一段flush的设计什么意思，flush_d是什么意思？
- **Agent 回答**：**不能**。跳转解析时有三条顺序误取的指令分布在三个水位、到达各自作废点的时刻错开：`I_{A+4}`（ID 阶段，`id_ex_flush` 作废）、`I_{A+8}`（IF/ID 门前，`if_id_flush` 的 `flush_any` 作废）、`I_{A+12}`（同步读中，`if_id_flush` 的 `flush_d` 下一拍作废）。**`flush_d` 是 `flush_any` 延迟一拍复制的信号**——IMem 同步读使最后一条在途指令晚一拍才到 IF/ID 锁存点，而那一拍 `flush_any` 已归零，需 `flush_d` 把窗口扩到 2 周期专补它。三个 flush 各管一条、缺一不可：删 ID/EX flush，`I_{A+4}` 会进 EX 执行；删 flush_d，`I_{A+12}` 漏杀。JAL 在 ID 解析时看起来只需 IF/ID 两拍——因为 JAL 自身还要前进写 `ra` 不能作废，`I_{A+4}` 被 `flush_any` 作废后 ID 阶段变气泡、ID/EX 自然清空。

### 问题：为什么 id_ex_flush 和 stall 有关系？
- **问题**：用户实验性地把 `id_ex_flush = ex_flush || stall` 改成 `id_ex_flush = ex_flush`，不解 stall 为何参与 ID/EX 的 flush。
- **我的 Prompt**：
  > 我不理解，为什么id_ex_flush和stall有什么关系
- **Agent 回答**：**stall 不是单个动作，而是"冻结 + 作废 + 冻结"三动作的组合**：IF/ID `en=0`（冻结等待指令）、ID/EX flush（**插入气泡**）、IMem `hold`（冻结 rdata_q）。ID/EX 的 flush 正是"插入气泡"那个动作——Load-Use 时让 Load 继续前进访存、等待指令停在 ID、中间空出的 EX 位置靠 flush 清空 ID/EX 实现。删掉 stall 的后果（用户当前试验）：cycle 3 检测 hazard 后 IF/ID 冻结 I_D，但 ID/EX `en=1` 照常锁存 I_D（`valid=1`、rs1 是寄存器文件旧值）→ cycle 4 **同一指令在 ID 和 EX 各出现一份**，EX 那份用旧 x1 计算——功能直接破坏（不同于之前防御性门控"删了也能跑"）。`ex_flush || stall` 是"**不同原因、相同动作**"：一个作废错误指令、一个延迟合法指令，但都要 ID/EX 输出气泡，所以 OR 合并。**经验**：Load-Use 必须 stall 的原因——转发救不了"数据还没就绪"的场景（Load 数据在 MEM 才产生，EX/MEM 里只有地址，所以 EX/MEM 转发显式排除 Load），只能停一拍让数据进 MEM/WB 后从源2 转发。

### 问题：dialogue-log skill 的文档组织格式如何改进？（分类式 → 问题式）
- **问题**：用户认为 dialogue-log skill 原文档（按 🧭/🐞/💡/❓/💬 分类组织）不好，希望改为按天分章、以"我提出或 Agent 解决的问题"为小节，记录每个问题的 prompt 与回答。
- **我的 Prompt**：
  > 请给我修改一下dialogue-log这个skill，我觉得这个skill写得文档不是很好，我希望文档是按照天为章节，以我提出或agent解决的问题为小节，然后把agent的对话进行整理的文档，比如20260815这天，提出了什么问题1、问题2、解决了什么问题，我的prompt是什么，agent的回答是什么，进行整理
- **Agent 回答**：三个文件改动：①重写 [SKILL.md](.claude/skills/dialogue-log/SKILL.md) 为 `## 日期` 分章 → `### 问题` 分节，每节字段式记录**问题描述 / 我的 Prompt / Agent 回答**，并明确 Prompt 真实性要求（引用用户原话，IDE 触发轮写客观触发上下文，不虚构）；②[dialogue.py](.claude/skills/dialogue-log/dialogue.py) 配套更新（DOC_HEADER、注释、append 提示语从"分类"改"问题小节"，digest 新增 `--full` 保留完整原文）；③迁移已有 [DIALOGUE.md](corex/docs/DIALOGUE.md) 的 08-13（8 问）、08-14（5 问）两章为问题格式，并从历史 transcript 逐问提取**真实原始 prompt**（fetch、hold 冗余、2 周期 flush、stall vs flush、PipelineReg、EX 前推等），保证迁移不编造。验证：append 合并逻辑与新格式兼容——新问题追加到指定日期末尾、同名问题并入已有小节、往中间章节追加不越界。**经验**：文档按"问题 + 用户原话 prompt + 回答"组织，比按抽象分类更能还原对话脉络；迁移历史日志时，transcript 里 IDE 触发的轮次以客观触发上下文描述，绝不用旧日志内容以外的东西编造 prompt。


---

## 2026-08-24

### 问题：core_lzq/test.py 是什么？用了它是不是就不用为每个 C 程序写 cocotb 脚本了？
- **问题**：用户看到 core_lzq/test.py 这个看似通用的测试文件，想知道它是否意味着自己的 C 程序测试不再需要逐程序写 cocotb 脚本（自己的脚本在 corex/my_c_test/testcases/test_core_adder.py）。
- **我的 Prompt**：
  > 请给我讲解一下test.py这个代码文件，如果用了这个代码是不是就可以不用给我的c程序测试写cocotb的脚本了啊，我的c程序的cocotb脚本在corex/my_c_test/testcases/test_core_adder.py
- **Agent 回答**：test.py 是**通用 C 程序测试框架**——只有一个测试函数 `t_core`，靠环境变量参数化（`MEM_PATH` hex 路径、`EXPECTED_BUFFER` 期望输出、`CORETEST_MAX_CYCLES` 超时）：编译 RTL 后用 `$readmemh` 直接加载 hex，跑时钟循环等程序往 `TOHOST_ADDR(0x2000)` 写 `0x77`（tohost 握手），再比对 buffer 内容。**思路正确**：这类模式确实免去逐程序写脚本。但 test.py 本身不能直接用：①它测的是另一套 RTL（`riscv_pkg/idu/exu/alu`，不是 corex 的 control_unit/decoder/execute/ALU 五级流水线，`CoreTop` 都不一样）；②依赖缺失（`from ..cocotb_utils import ...` 在 pku_workspace 根不存在、默认 `MEM_PATH` 指向的 `core_testframe` 也不存在）；③运行约定不同（test.py 要求写 tohost=0x77 + 结果 buffer，而 corex 程序是写 `0x100` 结果、无握手）。要在 corex 达到同样效果两条路：方案 A 把样板抽到 [cocotb_utils.py](corex/my_c_test/cocotb_utils.py) 公共辅助、逐程序脚本缩到十几行；方案 B 加 tohost 约定（crt0 写 `0x2000` + 结果写固定 buffer）后用 `$readmemh` + 单个通用 `t_core`，新 C 程序一行 cocotb 都不用写。

### 问题：如何仿照 test.py 让 C 程序测试不再逐程序写脚本？（10 脚本 → 1 通用脚本）
- **问题**：用户采纳了通用框架思路，要求仿照 test.py 针对自己的 RTL 改造，不再每个 C 程序写新 cocotb 脚本。
- **我的 Prompt**：
  > 我希望可以仿照test.py，不要每次都写一个新的cocotb测试脚本，对test.py针对我的RTL进行一些修改，我的c程序代码都在corex/my_c_test/src，我的RTL设计都在corex/hdl_sv/core，请修改
- **Agent 回答**：进计划模式，两个探索 agent 分别摸清 RTL 顶层与 C 测试基础设施。关键发现：**10 个 C 程序里 9 个已遵循统一约定**——结果写 `0x1000` 起始 DMem、结束前写 `0x2000=1` 作 done 标志（只有 adder 是特例：写 `0x100`、无 done），与 test.py 的 tohost 握手本质相同；10 个脚本的差异收敛到「hex 路径 + max_cycles + 检查项」三个参数。实施：新建 [test_core_program.py](corex/my_c_test/testcases/test_core_program.py)——内置 `PROGRAMS` 注册表（程序名 → `(max_cycles, {字节地址: 期望值})`，int=单字、list=连续多字），单个 `t_core_program` 从环境变量 `CORETEST_PROGRAM` 取程序名定位 hex → 填充 IMem → 轮询 `0x2000==1` → 比对；`@pytest.mark.parametrize` 一个用例跑全部程序、RTL 只编译一次。改 adder.c 统一约定；Makefile `run`/`run-all` 改走新脚本；删 10 个旧脚本；同步 CLAUDE.md/README.md。踩坑：`soft_mul_bit` 注册表里从旧脚本注释抄的 golden 值（`0x006AEBBC`/`0x3D17CDBC`）本身是错的，正确 product=`0x6AE9BC`、checksum=`0x3DFDBFBC`，改为 `soft_mul_expected()` 动态计算。验证：`make run TEST=sum`/`adder` 通过、`make run-all` **10 passed**。**经验**：这类期望值不该手抄进注册表，能动态算就动态算。

### 问题：c_test 三人的 12 个程序如何全部跑通并集成到 my_c_test？
- **问题**：c_test 文件夹下有三个人（zsq/ljt/dim）提供的 C 程序测试，用户希望全部跑通、有问题的针对性修改、集成进 my_c_test。
- **我的 Prompt**：
  > c_test文件夹下有三个人提供的c程序测试，我想你把所有的程序测试都跑通，如果有有问题的程序可以针对性进行修改，然后把测试程序加入我的my_c_test文件夹
- **Agent 回答**：逐个读完 12 个程序后先编译运行：zsq 5 个、ljt_factorial、dim_transform 共 7 个直接通过，ljt 其余 5 个失败，逐一溯源（此阶段是**改写源码适配 corex 裸机约定**，RTL 未动）：①**字面量池**（ljt_matrix/sort/binary_search/crc32）：`int data[4]={...}` 初始化列表在 -O0 下编译成从代码区池子 `lw` 加载，而 corex 数据访问全走 DMem（全零）→ 改逐个赋值（编译成立即数 `li`）；②**字节访存不可靠**（ljt_reverse 输出全 'C'、crc32 值错）：改 int 数组存字符 ASCII + word 访问绕过 LB/SB；③**RV32I 无 M 扩展**（matrix/factorial）：乘法改软件 multiply()（参照已有 factorial.c）；④**done 地址越界**（zsq 写 `0x8000`，超出 16KB DMem）：统一改 `0x2000`；⑤**-nostdlib 无 printf**：ljt 全部改为写 `0x1000` + `0x2000=1`。验证 `make run-all` **22 passed**。**经验**：corex 的 IMem/DMem 地址空间分离 + DMem 不预加载 .rodata/.data，导致初始化列表读全零——这是后续要根治的核心矛盾。

### 问题：为什么 ljt 的测试都有问题？是访存指令不同 / RTL 没实现 LB/SB / stdio.h 的问题吗？
- **问题**：用户没理解 ljt 测试为何都失败，怀疑三件事：用了不同访存指令、RTL 没实现 LB/SB、或 `#include <stdio.h>` 的问题，要求整理 RTL 实际实现的指令。
- **我的 Prompt**：
  > 我没理解为什么ljt的测试都有问题，是因为他使用的是不同的访存指令吗，我的rtl好像没有实现LB/SB,请给我整理一下我的RTL实现的指令有什么，还是#include<studio.h>的问题
- **Agent 回答**：ljt 失败**不是单一原因，而是三个独立问题叠加**：①字面量池（matrix/sort/binary_search）；②RTL 字节访存 LB/SB 实现有缺陷（reverse/crc32）；③stdio.h/printf 环境缺失（裸机工具链无 newlib，原程序连编译都过不去）。整理 RTL 实际指令：R/I/U/B/J 型算术逻辑跳转全正确；Load 仅 **LW** 正确、Store 仅 **SW** 正确；**LB/LBU/LH/LHU/SB/SH 触发但实现错误**——Load 端 [dmem.sv](corex/hdl_sv/core/dmem.sv) `assign rdata = mem[mem_addr]` 恒返回整 word，无 funct3 选字节/半字、无符号扩展；Store 端 [decoder.sv](corex/hdl_sv/core/decoder.sv) wbe 固定 SB=0001/SH=0011、不看地址低位。汇编铁证：reverse.c 用 `lbu/sb/sh`（LBU 每次返回同一 word，低字节都是 'C' → 输出全 'C'）；binary_search.c 用 `lw` 从 `.LC0` 字面量池加载（池子在代码区/IMem，程序从 DMem 读全 0 → 数据全零 → 返回 -1）。stdio.h 是第三件事：环境里没有、`-nostdlib` 下也无法链接 printf。适配按根因分别处理（初始化列表→逐个赋值、字节→int+word、printf→写 DMem）。**经验**：诊断这类"程序跑不通"要先分清工具链环境问题 vs RTL 功能缺口 vs 内存布局差异，不要归因到单一原因。

### 问题：如何补全 RTL 指令集并跑通 ljt 原始测试（含 stdio.h 环境）？
- **问题**：用户要求从根上修改 RTL 补全完整指令集，完整跑通 ljt 测试——不再手动改源码，包括 stdio.h 环境。
- **我的 Prompt**：
  > 现在请修改我的RTL，补充为完整的指令集，并且可以完整的跑通ljt的测试，而不是手动修改原发，包括stdio.h的环境
- **Agent 回答**：进计划模式，用户确认范围 **RV32I 补全 + 软件乘法**（不实现硬件 M 扩展）。四层改动：①**RTL 字节/半字访存**：[core.sv](corex/hdl_sv/core/core.sv) 的 `ex_mem_data_t` 移除固定 `mem_wbe`、新增 `funct3` 随流水传到 MEM；MEM 段新增组合逻辑——Load 按 funct3+地址低位选字节/半字并符号/零扩展（LB/LBU/LH/LHU/LW），Store 按 `addr[1:0]` 计算 `wbe` 与写数据字节偏移（SB/SH/SW）；[decoder.sv](corex/hdl_sv/core/decoder.sv) 移除 ID 段固定 wbe 生成。②**stdio.h 环境**：新增 [bsp/libc/](corex/my_c_test/bsp/libc/)（stdio.h + 极简 printf 支持 `%d %u %x %X %c %s %%`，输出写 DMem `0x2800` 控制台缓冲）；链接 `-nostdlib -lgcc` 从 rv32i multilib 的 libgcc 拉软件乘法 `__mulsi3`（matrix/factorial 的 `*` 直接可用）。③**字面量池修复**：[test_core_program.py](corex/my_c_test/testcases/test_core_program.py) 的 `load_hex_file` 解析 `@address` 段标记，把同一份平面镜像**同时灌入 IMem 与 DMem**（IMem 取指令、DMem 提供 .rodata/.data），初始化列表不再读全零；注册表新增 `console` 检查类型（读 `0x2800` 缓冲重建字符串比对）。④**恢复原始源码**：src/ljt_*.c 用 c_test/ljt 原样覆盖，`#include <stdio.h>`、char 数组、初始化列表、`*` 乘法全部原生可用。验证：`make run-all` **22 passed**（含 6 个 ljt 原始源码，输出 matrix `19 22 43 50`、reverse `XEROC`、sort `1 2 5 7`、binary_search `3 -1`、factorial `720 6`、crc32 `cbf43926` 全对）；核心集成测试 test_core_lzq/core_all/dmem 16 passed 无回归。发现**预先存在的单元测试缺陷**（与改动无关）：test_decoder 的 t_decode_LUI/AUIPC 驱动 `extend_sel=1`（S 型编码）却断言 U 型立即数、test_control_unit 的 t_ctrl_LUI/AUIPC 断言 extend_sel==1 而 RTL 输出 `3'b011`——都是测试对 extend_sel 编码的错误假设。**经验**：工具链环境事实（裸机无 newlib、rv32i multilib 的 libgcc 含 __mulsi3、IMem/DMem 地址空间独立）决定了 C 测试能否原生编译运行，补 RTL 功能缺口时顺带把测试脚本的双内存加载一并修掉才完整。

