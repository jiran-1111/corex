# tb_verilator — 纯 Verilator C++ testbench

不用 cocotb / 不用 VPI，用 Verilator `--exe` 直接把 CoreTop 编译成独立可执行文件，
由 C++ 驱动时钟、加载指令、检查 DMem 结果，并报告纯仿真的吞吐率。

## 目录

- [sim_main.cpp](sim_main.cpp) — C++ testbench（hex 加载、复位/启动时序、完成检测、吞吐测量）
- [Makefile](Makefile) — 编译（verilator `--cc --exe --build`）+ 运行

## 用法

```bash
cd my_c_test/tb_verilator

make run   TEST=binary_search   # 功能验证（1 次，带 RTL 调试打印）
make perf  TEST=binary_search   # 吞吐测试（50 次取平均，调试打印保留）
make perf-nodb TEST=...         # 吞吐测试（50 次，剥离 core.sv 的 $display 调试监视器）
make clean
```

`TEST` 为 [../src](../src/) 下任意 C 程序名；`test.hex` 缺失时会自动调用
上层 `my_c_test` Makefile 交叉编译生成。

## testbench 命令行参数（均可选）

| 参数 | 说明 | 默认 |
|------|------|------|
| `--hex <file>` | 加载的 hex 镜像 | `../build/<TEST>/test.hex` |
| `--max-cycles <n>` | 超时周期数 | 2000 |
| `--iters <n>` | 重复复位+运行次数，用于平均吞吐 | 1 |
| `--expect-idx1 <n>` | 期望的 dmem[0x1000] | 5 |
| `--expect-idx2 <n>` | 期望的 dmem[0x1004] | -1 |
| `--verbose` | 打印每次迭代的周期数 | 关 |

退出码：全部通过为 0，任一不通过为 1（可用于脚本/CI）。

## 关键实现点

- **IMem / DMem 访问**：`--public-flat-rw` 把所有信号扁平公开，DMem 数组经
  `top->rootp->CoreTop->u_dmem__DOT__dmem__DOT__mem[addr>>2]` 读写；
  IMem 数组因源文件已有 `/*verilator public*/`，走层次
  `top->rootp->CoreTop->u_ifu->IMem->imem->mem[i]`。
  因此**不需要修改任何 RTL**。
- **`--timing`**：只在保留调试打印的构建需要（core.sv 里的 `$display`/`$time`）；
  纯仿真（`perf-nodb`）构建去掉该标志。
- **`-O3`**：通过 `export OPT_FAST/OPT_SLOW` 传入，实测比默认 `-Os` 快约 1.6×。
- 复位时序与 cocotb 测试一致：2 周期复位 → 1 周期 start 脉冲 → 轮询完成标志。
- 每次迭代前显式清零 `0x2000`（完成标志）等 DMem 结果地址（DMem 不受复位清零）。

## binary_search 效率实测（2026-08，Verilator 5.040，本机）

程序完成约 282 个时钟周期/次。原 cocotb 侧曾支持 `RUNS=N` 连续运行以摊销初始化做吞吐量
profiling；该实验代码已随 2026-08 的通用脚本合并（见下文）而简化，当前通用脚本对每个
程序做单次结果验证。

> cocotb 侧已做过开销优化：热路径缓存句柄 + 复用 `RisingEdge` 触发、覆盖率改为
> `COVERAGE=1` 才插桩、conftest 懒加载 coverage。见 [test_core_program.py](../testcases/test_core_program.py)。

### cocotb 连续运行 vs 纯 Verilator（50 次对比）

| 运行方式 | 总耗时(含初始化) | 纯仿真时间 | 初始化/固定开销 | 有效吞吐 | 纯仿真吞吐 |
|----------|---------|------|--------|---------|-----------|
| cocotb RUNS=1（单次） | ~0.07 s | ~5.5 ms | ~65 ms（≈90%） | ~3.9 K cycles/s | ~51 K cycles/s |
| cocotb RUNS=50 | ~0.34 s | ~263 ms | ~65 ms（≈20%） | ~41 K cycles/s | ~54 K cycles/s |
| 纯 Verilator 50 次（`perf`） | 5.9 ms | 5.1 ms | 0.83 ms | 2.36 M cycles/s | 2.75 M cycles/s |
| 纯 Verilator 1 次 | 2.448 ms | 0.142 ms | 2.271 ms | 2.30 M cycles/s | 2.30 M cycles/s |

> 本机为共享 WSL2，负载波动 ±40%，数值供量级参考；完整数据与一次 pytest 的耗时分解见
> [lab_data.md](lab_data.md)。

结论：

- **cocotb 初始化是固定开销（~65 ms），与运行次数无关**：单次运行时约占 90%，
  是绝对瓶颈；连续跑 50 次后稀释到 ~20%，有效吞吐约提升 **10×**
  （~3.9K → ~41K cycles/s）。此后瓶颈变为每周期一次 Python/VPI 调度
  （纯仿真 ~54K cycles/s，即 ~18.7 µs/cycle，已接近 `RisingEdge` 触发本身的
  ~15 µs 下限），再增加迭代次数也没有提升。
- **纯 C++ testbench 相对优化后的 cocotb 仍快约 50×**（1–2 个数量级）；其初始化仅
  ~0.8ms，吞吐瓶颈是 Verilator 内核本身（~2.6–2.8 M cycles/s，约 300 ns/cycle）。
- 当前 core.sv 的 `DEBUG_CORE` 监视器处于注释状态，`perf` 与 `perf-nodb` 几乎无差别；
  重新打开监视器后，每周期 `$display` 会明显拖慢 `perf`。

### 代表输出 — cocotb RUNS=50

```
142490.00ns INFO     cocotb.CoreTop                      [cocotb Profiling Result]  (50 iterations)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Total Sim Cycles     : 14100 cycles (avg 282.0/iter)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Dynamic Time: 262.537 ms
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Throughput  : 53706.6 cycles/s (18619.7 ns/cycle)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Test Wall Time       : 271.485 ms
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Wall-Clock Throughput: 51936.5 cycles/s (19254.3 ns/cycle)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Fixed Overhead/iter  : 0.179 ms (amortized over 50 runs)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Passed               : 50/50
142490.00ns INFO     cocotb.CoreTop                     ==============================================================
```

### 代表输出 — 纯 Verilator perf-nodb（--iters 50）

```
 [tb] RESULT             : PASS
 [tb] Setup/Init Overhead: 0.001866 s
 [tb] Total Process Wall Time: 0.005961 s
 [tb] Pure Sim Throughput: 3420299.3 cycles/s (292.372 ns/cycle)
 [tb] Wall-Clock Throughput: 2348512.9 cycles/s (425.801 ns/cycle)
```
