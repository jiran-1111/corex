| 方案 | 仿真周期数 | REAL_TIME | pure_sim_time | sim_time_per_cyc |
|------|------|------|------|------|
|cocotb_run_1 | 282cycles | 80ms | 5.538ms | 0.019ms/cycles |
|cocotb_run_50 | 14100cycles | 340ms |264.125ms | 0.0187ms/cycles |
|verilator_run_1 | 282cycles | 2.448ms | 0.142ms | 0.000503ms/cycles |
|verilator_run_50 | 14100cycles | 6.91ms | 5.601ms | 0.000397ms/cycles |


倍数关系：

80/2.448=32

340/6.91=49

0.19/0.000503=38

0.187/0.000396=47
