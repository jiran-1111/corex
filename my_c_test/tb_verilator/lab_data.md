# tb_verilator 实验数据（2026-08）

被测程序：`binary_search`，交叉编译后运行约 **282 个时钟周期/次**。
所有测量在本机（WSL2，Verilator 5.040）同一时间段内完成；共享机器负载会带来
约 ±40% 的波动，数值供**量级参考**。

## 指标说明

- **纯仿真时间**：只在「轮询完成标志」的循环内计时（cocotb 中该时间以 Python/cocotb
  每周期调度开销为主）；不含复位、装载、初始化。
- **总耗时（含初始化）**：cocotb 用其回归管理器报告的 REAL TIME（仿真进程启动 +
  cocotb 初始化 + 测试体 + teardown）；纯 Verilator 用进程的 Total Wall Time。
- **有效吞吐**：`总周期数 / 总耗时（含初始化）`，代表实际跑完一轮真实能拿到的吞吐。
- **纯仿真吞吐**：`总周期数 / 纯仿真时间`，不含任何初始化/复位/调度开销。

## 1. cocotb 连续运行（RUNS=50）vs 纯 Verilator（--iters 50）

cocotb 测试已做开销优化：热路径缓存句柄 + 复用 `RisingEdge` 触发（每周期
~23.4µs → ~18.7µs）、覆盖率改为 `COVERAGE=1` 才插桩、conftest 懒加载 coverage。

| 运行方式 | 总耗时(含初始化) | 纯仿真时间 | 初始化/固定开销 | 有效吞吐 | 纯仿真吞吐 |
|----------|---------|------|--------|---------|-----------|
| cocotb RUNS=1（单次） | ~0.07 s | ~5.5 ms | ~65 ms（≈90%） | ~3.9 K cycles/s | ~51 K cycles/s |
| cocotb RUNS=50 | ~0.34 s | ~263 ms | ~65 ms（≈20%） | ~41 K cycles/s | ~54 K cycles/s |
| 纯 Verilator 50 次（perf，保留监视器源码） | 5.9 ms | 5.1 ms | 0.83 ms | 2.36 M cycles/s | 2.75 M cycles/s |
| 纯 Verilator 50 次（perf-nodb，剥离监视器） | 6.2 ms | 5.3 ms | 0.82 ms | 2.28 M cycles/s | 2.63 M cycles/s |

> 注：core.sv 中 `DEBUG_CORE` 监视器当前处于注释状态（不打印），因此
> perf 与 perf-nodb 基本一致；若重新打开 `DEBUG_CORE`，perf 会因每周期 `$display`
> 明显变慢。

## 2. 一次 `RUNS=50` pytest 的总耗时分解（~0.74s）

| 阶段 | 耗时 | 说明 |
|------|------|------|
| pytest 启动 + 模块导入 | ~290 ms | Python 解释器 + `import cocotb`（~150ms）+ pytest/插件 + conftest |
| runner.build 检查 | ~60 ms | `ALWAYS_BUILD=True` 每次重跑 verilator（增量缓存，仅 ~60ms） |
| cocotb 仿真进程（REAL TIME） | ~340 ms | 其中 初始化+teardown ~65ms，测试体 50 次 ~272ms |
| pytest 收尾 / 结果写入 | ~50 ms | 结果 XML、覆盖报告（若启用） |

> cocotb 每周期开销的下限约 **15 µs/cycle**（仅 `RisingEdge` 触发）；
> 本测试优化后 ~18.7 µs/cycle，已接近该下限。这部分是 cocotb 架构固有成本，
> 无法靠脚本再压缩；若要进一步提速只能换纯 C++ testbench（本目录）。

## 3. 关键结论

1. **cocotb 初始化是固定开销（~65 ms），与运行次数无关。**
   单次运行时它占总耗时约 90%，是绝对瓶颈。
2. **连续跑 50 次把初始化稀释到 ~20%，有效吞吐从 ~3.9K 提到 ~41K cycles/s
   （约 10×）。** 此后瓶颈是每周期一次 Python/VPI 调度（纯仿真 ~54K cycles/s，
   即 ~18.7 µs/cycle），这一项无法靠增加迭代次数改善。
3. **纯 Verilator C++ testbench 相对优化后的 cocotb 仍快约 50×**（1–2 个数量级）：
   50 次总耗时 5.9ms；其初始化仅 ~0.8ms，吞吐瓶颈是 Verilator 仿真内核本身
   （~2.6–2.8 M cycles/s，约 280–300 ns/cycle）。

## 4. 长程序参考（14000 个周期量级，历史数据）

| 运行方式 | 总仿真耗时 | 纯仿真时间 | 初始化时间 |
|----------|---------|------|--------|
| cocotb + Verilator | 429.55 ms | 349.55 ms | 60~80 ms |
| 纯 Verilator | 2.448 ms | 0.142 ms | 2.271 ms |

> 长程序时纯仿真时间占比更高，cocotb 初始化被进一步稀释；但 cocotb 的
> 每周期调度开销依旧存在，吞吐上限不变。
