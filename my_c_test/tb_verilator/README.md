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

程序完成约 280 个时钟周期。

| 运行方式 | 仿真耗时 | 吞吐 | 每周期 |
|----------|---------|------|--------|
| cocotb + Verilator（cocotb 报告，含每周期 VPI/Python 开销） | ~0.08 s | ~3.5 K cycles/s | ~285 µs |
| 纯 Verilator，RTL 调试 `$display` 保留 | ~0.85 ms | ~0.34 M cycles/s | ~2.9 µs |
| 纯 Verilator，剥离调试打印（`perf-nodb`） | ~0.09 ms | ~3.4 M cycles/s | ~0.28 µs |

结论：纯 C++ testbench 相对 cocotb 约快 **1–2 个数量级**；速度瓶颈分别是
每周期一次 `$display` 打印（保留调试时）和 Verilator 仿真内核本身（剥离调试后）。
