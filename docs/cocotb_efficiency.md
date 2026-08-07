# cocotb & verilator 效率对比实验---jr

## 0. 实验目的

该实验用于对比cocotb+verilator仿真器和使用纯verilator仿真器在效率上的差异。同时增加coverage变量，对比分析RTL级coverage给仿真性能带来的影响。

## 1. 实验测试样例
 
使用 corex/my_c_test/src/binary_search.c 进行测试，分别使用cocotb+verilator和纯verilator进行测试，以验证其仿真效率，同时分别增加RTL coverage进行实验，以测试其仿真效率。 

- cocotb脚本位于 corex/my_c_test/testcases/test_core_binary_search.py

- 纯verilator的脚本位于 corex/my_c_test/tb_verilator/sim_main.cpp

使用方式和实验结果见下：

## 2. 测试 cocotb + verilator 仿真效率

```bash
cd corex/my_c_test
make clean
make run TEST=binary_search

REAL TIME:外部python解释器启动整个测试框架的总耗时
Test Wall Time:仿真用例执行耗时，只包含测试用例进入执行阶段到测试结束的时间
Pure Sim Dynamic Time:纯仿真时间
```

修改轮次：corex/my_c_test/testcases/test_core_binary_search.py 修改23行 RUNS = int(os.getenv("RUNS", "50"))即可修改总轮次

修改是否使用RTL coverage：corex/my_c_test/cocotb_utils.py 修改21行 COVERAGE = os.getenv("COVERAGE", "1") == "1"


### 2.1 实验结果

```bash
# 没有coverage 运行1次
2840.00ns INFO     cocotb.CoreTop                      [cocotb Profiling Result]  (1 iterations)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Total Sim Cycles     : 282 cycles (avg 282.0/iter)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Dynamic Time: 5.550 ms
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Throughput  : 50815.0 cycles/s (19679.2 ns/cycle)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Test Wall Time       : 7.301 ms
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Wall-Clock Throughput: 38624.6 cycles/s (25890.2 ns/cycle)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Fixed Overhead/iter  : 1.751 ms (amortized over 1 runs)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Passed               : 1/1
  2840.00ns INFO     cocotb.CoreTop                     ==============================================================
  2840.00ns INFO     cocotb.regression                  testcases.test_core_binary_search.t_core_c_binary_search_test passed
  2840.00ns INFO     cocotb.regression                  
    ** TEST                                                           STATUS  SIM TIME (ns)  REAL TIME (s)  RATIO (ns/s) **

    ** testcases.test_core_binary_search.t_core_c_binary_search_test   PASS        2840.00           0.08      36624.61  **

# 没有coverage 运行50次
142490.00ns INFO     cocotb.CoreTop                      [cocotb Profiling Result]  (50 iterations)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Total Sim Cycles     : 14100 cycles (avg 282.0/iter)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Dynamic Time: 266.322 ms
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Throughput  : 52943.5 cycles/s (18888.1 ns/cycle)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Test Wall Time       : 275.150 ms
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Wall-Clock Throughput: 51244.8 cycles/s (19514.2 ns/cycle)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Fixed Overhead/iter  : 0.177 ms (amortized over 50 runs)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Passed               : 50/50
142490.00ns INFO     cocotb.CoreTop                     ==============================================================
142490.00ns INFO     cocotb.regression                  testcases.test_core_binary_search.t_core_c_binary_search_test passed
142490.00ns INFO     cocotb.regression                  
    ** TEST                                                           STATUS  SIM TIME (ns)  REAL TIME (s)  RATIO (ns/s) **
    ** testcases.test_core_binary_search.t_core_c_binary_search_test   PASS      142490.00           0.35     412043.46  **

# 有coverage 运行1次
  2840.00ns INFO     cocotb.CoreTop                      [cocotb Profiling Result]  (1 iterations)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Total Sim Cycles     : 282 cycles (avg 282.0/iter)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Dynamic Time: 7.029 ms
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Throughput  : 40121.5 cycles/s (24924.3 ns/cycle)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Test Wall Time       : 8.882 ms
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Wall-Clock Throughput: 31749.1 cycles/s (31497.0 ns/cycle)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Fixed Overhead/iter  : 1.853 ms (amortized over 1 runs)
  2840.00ns INFO     cocotb.CoreTop                      [cocotb] Passed               : 1/1
  2840.00ns INFO     cocotb.CoreTop                     ==============================================================
  2840.00ns INFO     cocotb.regression                  testcases.test_core_binary_search.t_core_c_binary_search_test passed
  2840.00ns INFO     cocotb.regression                  
    ** TEST                                                           STATUS  SIM TIME (ns)  REAL TIME (s)  RATIO (ns/s) **
    ** testcases.test_core_binary_search.t_core_c_binary_search_test   PASS        2840.00           0.08      36612.67  **

# 有coverage 运行50次
142490.00ns INFO     cocotb.CoreTop                     ==============================================================
142490.00ns INFO     cocotb.CoreTop                      [cocotb Profiling Result]  (50 iterations)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Total Sim Cycles     : 14100 cycles (avg 282.0/iter)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Dynamic Time: 338.422 ms
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Pure Sim Throughput  : 41663.9 cycles/s (24001.6 ns/cycle)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Test Wall Time       : 348.065 ms
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Wall-Clock Throughput: 40509.7 cycles/s (24685.5 ns/cycle)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Fixed Overhead/iter  : 0.193 ms (amortized over 50 runs)
142490.00ns INFO     cocotb.CoreTop                      [cocotb] Passed               : 50/50
142490.00ns INFO     cocotb.CoreTop                     ==============================================================
142490.00ns INFO     cocotb.regression                  testcases.test_core_binary_search.t_core_c_binary_search_test passed
142490.00ns INFO     cocotb.regression                  
    ** TEST                                                           STATUS  SIM TIME (ns)  REAL TIME (s)  RATIO (ns/s) **
    ** testcases.test_core_binary_search.t_core_c_binary_search_test   PASS      142490.00           0.42     339911.52  **
```


注：在 Cocotb 端到端耗时（Test Wall Time）的统计中，统一采用 Cocotb 性能分析器在用例内部精准测量的墙上时间，排除了外层 Python 解释器冷启动及 Makefile 进程唤醒开销（约 70ms），以准确测量 Cocotb GPI 接口与 Python 测试逻辑在实际运行期的吞吐效率。

## 3. 纯verilator仿真效率

```bash
cd corex/my_c_test/tb_verilator
make clean-all
```

### 3.1 参数细节：
- Total process Wall TIME：端到端总运行时间
- Setup/Init Overhead：初始化/环境开销
- Pure Sim Time：纯RTL仿真耗时可通过计算得出：Total process Wall TIME - Setup/Init Overhead

- Pure Sim Throughput：纯仿真吞吐率，指扣除初始化开销后，纯粹衡量 RTL 逻辑运算的速度。
- Wall-Clock Throughput：端到端综合吞吐率，指把初始化开销也算上后，整体程序摊分到每个 Cycle 的平均速度。

### 3.2 实验结果
```bash
# 没有coverage 运行1次
make perf-single TEST=binary_search

==============================================================
 [tb] Pure-Verilator C++ testbench
 [tb] hex        : /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
==============================================================
 [tb] loaded 396 bytes (99 words) from /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
 [tb] iter  0: cycles=280  idx1=5 (exp 5)  idx2=-1 (exp -1)  PASS
--------------------------------------------------------------
 [tb] RESULT             : PASS
 [tb] Setup/Init Overhead: 0.001116 s
 [tb] Total Process Wall Time: 0.001233 s
 [tb] Pure Sim Throughput: 2855598.5 cycles/s (350.189 ns/cycle)
 [tb] Wall-Clock Throughput: 227051.0 cycles/s (4404.296 ns/cycle)
--------------------------------------------------------------

# 没有coverage 运行50次
make perf TEST=binary_search

/test.hex --iters 50 --expect-idx1 5 --expect-idx2 -1
==============================================================
 [tb] Pure-Verilator C++ testbench
 [tb] hex        : /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
==============================================================
 [tb] loaded 396 bytes (99 words) from /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
--------------------------------------------------------------
 [tb] RESULT             : PASS
 [tb] Setup/Init Overhead: 0.000737 s
 [tb] Total Process Wall Time: 0.004780 s
 [tb] Pure Sim Throughput: 3464639.0 cycles/s (288.630 ns/cycle)
 [tb] Wall-Clock Throughput: 2928793.7 cycles/s (341.438 ns/cycle)
--------------------------------------------------------------

# 有coverage 运行1次
make run-cov TEST=binary_search

/test.hex --iters 1 --expect-idx1 5 --expect-idx2 -1
==============================================================
 [tb] Pure-Verilator C++ testbench
 [tb] hex        : /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
==============================================================
 [tb] loaded 396 bytes (99 words) from /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
 [tb] iter  0: cycles=280  idx1=5 (exp 5)  idx2=-1 (exp -1)  PASS
--------------------------------------------------------------
 [tb] RESULT             : PASS
 [tb] Setup/Init Overhead: 0.023333 s
 [tb] Total Process Wall Time: 0.024739 s
 [tb] Pure Sim Throughput: 202460.2 cycles/s (4939.243 ns/cycle)
 [tb] Wall-Clock Throughput: 11318.2 cycles/s (88353.279 ns/cycle)
--------------------------------------------------------------
 [tb] Coverage data written to: coverage.dat
make[1]: Leaving directory '/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator'

# 有coverage 运行50次
make run-cov-50 TEST=binary_search

==============================================================
 [tb] Pure-Verilator C++ testbench
 [tb] hex        : /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
==============================================================
 [tb] loaded 396 bytes (99 words) from /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
--------------------------------------------------------------
 [tb] RESULT             : PASS
 [tb] Setup/Init Overhead: 0.024625 s
 [tb] Total Process Wall Time: 0.090974 s
 [tb] Pure Sim Throughput: 211015.3 cycles/s (4738.994 ns/cycle)
 [tb] Wall-Clock Throughput: 153890.2 cycles/s (6498.140 ns/cycle)
--------------------------------------------------------------
 [tb] Coverage data written to: coverage.dat
make[1]: Leaving directory '/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator'

```


## 4. 总体实验数据对比
| **测试方案 (Scheme)**           | **Coverage** | **运行轮次** | **仿真周期数 (Cycles)** | **环境初始化开销 (Setup Overhead)** | **纯仿真耗时 (Pure Sim Time)** | **端到端总用时 (Test Wall Time)** | **纯仿真单周期耗时 (ns/cycle)** | **纯仿真吞吐率 (Pure Throughput)** | **综合端到端吞吐率 (Wall-Clock Throughput)** |
| ------------------------------- | ------------ | ------------ | ----------------------- | ----------------------------------- | ------------------------------ | --------------------------------- | ------------------------------- | ---------------------------------- | -------------------------------------------- |
| **`cocotb_run_1`**              | ✕            | 1            | 282                     | 1.751 ms                            | 5.550 ms                       | 7.301 ms                          | 19,679.2 ns                     | **50.82 Kcycles/s**                | **38.62 Kcycles/s**                          |
| **`cocotb_run_50`**             | ✕            | 50           | 14,100                  | 8.828 ms                            | 266.322 ms                     | 275.150 ms                        | 18,888.1 ns                     | **52.94 Kcycles/s**                | **51.24 Kcycles/s**                          |
| **`cocotb_run_1_coverage`**     | 𝘝            | 1            | 282                     | 1.853 ms                            | 7.029 ms                       | 8.882 ms                          | 24,924.3 ns                     | **40.12 Kcycles/s**                | **31.75 Kcycles/s**                          |
| **`cocotb_run_50_coverage`**    | 𝘝            | 50           | 14,100                  | 9.643 ms                            | 338.422 ms                     | 348.065 ms                        | 24,001.6 ns                     | **41.66 Kcycles/s**                | **40.51 Kcycles/s**                          |
| **`verilator_run_1`**           | ✕            | 1            | 280                     | 1.116 ms                            | 0.098 ms                       | 1.233 ms                          | 350.2 ns                        | **2,855.60 Kcycles/s** (2.86 M)    | **227.05 Kcycles/s**                         |
| **`verilator_run_50`**          | ✕            | 50           | 14,000                  | 0.737 ms                            | 4.043 ms                       | 4.780 ms                          | 288.6 ns                        | **3,464.64 Kcycles/s** (3.46 M)    | **2,928.79 Kcycles/s** (2.93 M)              |
| **`verilator_run_1_coverage`**  | 𝘝            | 1            | 280                     | 23.333 ms                           | 1.406 ms                       | 24.739 ms                         | 4,939.2 ns                      | **202.46 Kcycles/s**               | **11.32 Kcycles/s**                          |
| **`verilator_run_50_coverage`** | 𝘝            | 50           | 14,000                  | 24.625 ms                           | 66.349 ms                      | 90.974 ms                         | 4,739.0 ns                      | **211.02 Kcycles/s**               | **153.89 Kcycles/s**                         |

