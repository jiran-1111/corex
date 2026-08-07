## 实验汇报：cocotb 与纯 Verilator C++ 性能对比

### 一、 数据汇总

| **方案**               | **仿真周期数** | **端到端用时 (REAL_TIME)** | **纯仿真耗时 (pure_sim_time)** | **纯仿真单周期耗时**       | **纯仿真吞吐率**             |
| ---------------------- | -------------- | -------------------------- | ------------------------------ | -------------------------- | ---------------------------- |
| **`verilator_run_1`**  | $282$          | $2.45\text{ ms}$           | $0.14\text{ ms}$               | $0.50\ \mu\text{s/cycle}$  | $\sim 2.30\text{ Mcycles/s}$ |
| **`verilator_run_50`** | $14,100$       | $6.91\text{ ms}$           | $5.60\text{ ms}$               | $0.40\ \mu\text{s/cycle}$  | $\sim 2.75\text{ Mcycles/s}$ |
| **`verilator_run_1_coverage`**  | $282$          | $25.420\text{ ms}$           | $1.42\text{ ms}$               | $5.00\ \mu\text{s/cycle}$  | $\sim 200\text{ Kcycles/s}$ |
| **`verilator_run_50_coverage`**  | $14100$          | $92.28\text{ ms}$           | $65.98\text{ ms}$               | $4.710\ \mu\text{s/cycle}$  | $\sim 212\text{ Kcycles/s}$ |
| **`cocotb_run_1`**     | $282$          | $80.00\text{ ms}$          | $5.70\text{ ms}$               | $20.00\ \mu\text{s/cycle}$ | $\sim 549.3\text{ Kcycles/s}$ |
| **`cocotb_run_50`**    | $14,100$       | $340.00\text{ ms}$         | $264.13\text{ ms}$             | $18.73\ \mu\text{s/cycle}$ | $\sim 53.4\text{ Kcycles/s}$ |
| **`cocotb_run_1_coverage`**     | $282$          | $80.00\text{ ms}$          | $7.50\text{ ms}$               | $26.6\ \mu\text{s/cycle}$ | $\sim 37.56\text{ Kcycles/s}$ |
| **`cocotb_run_50_coverage`**    | $14,100$       | $450.00\text{ ms}$         | $361.256\text{ ms}$             | $25.621\ \mu\text{s/cycle}$ | $\sim 39.03\text{ Kcycles/s}$ |

#### 性能差距（cocotb / Verilator）

- **端到端用时差距**：单次 $32.7\times$（$80 / 2.448$）$\to$ 50次 $49.2\times$（$340 / 6.91$）
- **纯仿真单周期耗时差距**：单次 $37.8\times$（$0.019 / 0.000503$）$\to$ 50次 $47.2\times$（$0.187 / 0.000396$）

### 二、 实验分析

#### 1. 固定开销稀释

- **cocotb**：含有约 $65\text{ ms}$ 的固定启动开销。单次运行时固定开销占比 $>90\%$；通过批量运行 50 次，固定开销被稀释至约 $20\%$，有效吞吐率大幅提升。
- **Verilator C++**：几乎无初始化开销（单次仅 $2.27\text{ ms}$，50次平摊后仅 $0.83\text{ ms}$），在微测试下依然高效。

#### 2. 纯仿真性能瓶颈

- 即使排除固定开销，纯 C++ 方案仍比 cocotb **快 $38\times \sim 47\times$**。
- **cocotb 瓶颈**：受到 VPI 跨语言交互与协程调度开销限制（单周期需约 $18.7\ \mu\text{s}$），纯仿真吞吐被锁死在 $\sim 5.4\text{ 万 cycles/s}$ 的物理天花板。
- **Verilator C++ 瓶颈**：由本地 C++ 引擎与 `-O3` 编译直接驱动，单周期仅需 $\sim 0.4\ \mu\text{s}$，吞吐率可达 $\sim 2.75\text{ Mcycles/s}$。
