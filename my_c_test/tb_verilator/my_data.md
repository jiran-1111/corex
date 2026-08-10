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




t__DepSet_h8f2c8a57__0__Slow.cpp VCoreTop_CoreTop__Slow.cpp VCoreTop_CoreTop__DepSet_heb703bfa__0__Slow.cpp VCoreTop_CoreTop__DepSet_h050a4cf7__0__Slow.cpp VCoreTop_Ifu__Slow.cpp VCoreTop_Ifu__DepSet_h544326f2__0__Slow.cpp VCoreTop_Ifu__DepSet_ha92ac939__0__Slow.cpp VCoreTop_IMemTop__Slow.cpp VCoreTop_IMemTop__DepSet_hff6dbdc5__0__Slow.cpp VCoreTop_IMemTop__DepSet_h0db7f785__0__Slow.cpp VCoreTop_DBusIf__Slow.cpp VCoreTop_DBusIf__DepSet_h2245d04d__0__Slow.cpp VCoreTop_DBusIf__DepSet_h53d120af__0__Slow.cpp VCoreTop_IMem__Slow.cpp VCoreTop_IMem__DepSet_h9a7dac6f__0__Slow.cpp VCoreTop_IMem__DepSet_h07e45c05__0__Slow.cpp VCoreTop_IBusIf__Slow.cpp VCoreTop_IBusIf__DepSet_hb077b533__0__Slow.cpp VCoreTop_IBusIf__DepSet_h91ed16a8__0__Slow.cpp VCoreTop__Syms.cpp > VCoreTop__ALL.cpp
ccache g++ -Os  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVERILATOR=1 -DVM_COVERAGE=1 -DVM_SC=0 -DVM_TIMING=0 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -DVM_TRACE_SAIF=0 -faligned-new -fcf-protection=none -Wno-bool-operation -Wno-int-in-bool-context -Wno-shadow -Wno-sign-compare -Wno-subobject-linkage -Wno-tautological-compare -Wno-uninitialized -Wno-unused-but-set-parameter -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable    -O3 -flto -fno-stack-protector   -c -o VCoreTop__ALL.o VCoreTop__ALL.cpp
echo "" > VCoreTop__ALL.verilator_deplist.tmp
g++    sim_main.o verilated.o verilated_dpi.o verilated_cov.o verilated_threads.o VCoreTop__ALL.a   -O3 -flto  -pthread -lpthread -latomic   -o VCoreTop
lto-wrapper: warning: using serial compilation of 5 LTRANS jobs
rm VCoreTop__ALL.verilator_deplist.tmp
make[2]: Leaving directory '/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator/build/binary_search/obj_dir'
- V e r i l a t i o n   R e p o r t: Verilator 5.040 2025-08-30 rev v5.040
- Verilator: Built from 0.382 MB sources in 15 modules, into 0.678 MB in 35 C++ files needing 0.000 MB
- Verilator: Walltime 12.274 s (elab=0.004, cvt=0.047, bld=12.202); cpu 0.072 s on 1 threads; alloced 24.449 MB
/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator/build/binary_search/obj_dir/VCoreTop --hex /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex --iters 1 --expect-idx1 5 --expect-idx2 -1
==============================================================
 [tb] Pure-Verilator C++ testbench
 [tb] hex        : /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
==============================================================
 [tb] loaded 396 bytes (99 words) from /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
 [tb] iter  0: cycles=280  idx1=5 (exp 5)  idx2=-1 (exp -1)  PASS
--------------------------------------------------------------
 [tb] RESULT             : PASS
 [tb] Setup/Init Overhead: 0.020496 s
 [tb] Total Process Wall Time: 0.021903 s
 [tb] Pure Sim Throughput: 202175.7 cycles/s (4946.193 ns/cycle)
 [tb] Wall-Clock Throughput: 12783.6 cycles/s (78225.489 ns/cycle)
--------------------------------------------------------------
 [tb] Coverage data written to: coverage.dat
make[1]: Leaving directory '/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator'
(corex_env) ranrr@ranran:~/pku_workspace/corex/my_c_test/tb_verilator$ make clean-all
rm -rf /home/ranrr/pku_workspace/corex/my_c_test/tb_verilator/build *.dat
rm -rf /home/ranrr/pku_workspace/corex/my_c_test/build
(corex_env) ranrr@ranran:~/pku_workspace/corex/my_c_test/tb_verilator$ make run-cov-50 TEST=binary_search
make COVERAGE=1 perf
make[1]: Entering directory '/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator'
make -C /home/ranrr/pku_workspace/corex/my_c_test TEST=binary_search all
make[2]: Entering directory '/home/ranrr/pku_workspace/corex/my_c_test'
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -O0 -nostdlib -T bsp/link.ld -I bsp bsp/crt0.s src/binary_search.c -o build/binary_search/test.elf
bsp/crt0.s: Assembler messages:
bsp/crt0.s: Warning: end of file in comment; newline inserted
riscv64-unknown-elf-objcopy -O verilog build/binary_search/test.elf build/binary_search/test.hex
riscv64-unknown-elf-objdump -D build/binary_search/test.elf > build/binary_search/test.dump
make[2]: Leaving directory '/home/ranrr/pku_workspace/corex/my_c_test'
make[1]: Circular /home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv <- /home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv dependency dropped.
verilator --cc --exe --build --top-module CoreTop --public-flat-rw -Wno-fatal -Wno-lint -Wno-WIDTH -Wno-UNUSEDSIGNAL -Wno-UNUSEDPARAM -Wno-VARHIDDEN -Wno-CASEINCOMPLETE --Mdir /home/ranrr/pku_workspace/corex/my_c_test/tb_verilator/build/binary_search/obj_dir --coverage -CFLAGS "-O3 -flto -fno-stack-protector" -LDFLAGS "-O3 -flto" --timing \
    /home/ranrr/pku_workspace/corex/my_c_test/tb_verilator/sim_main.cpp \
    /home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/ibus_if.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv /home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv
make[2]: Entering directory '/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator/build/binary_search/obj_dir'
ccache g++  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVERILATOR=1 -DVM_COVERAGE=1 -DVM_SC=0 -DVM_TIMING=0 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -DVM_TRACE_SAIF=0 -faligned-new -fcf-protection=none -Wno-bool-operation -Wno-int-in-bool-context -Wno-shadow -Wno-sign-compare -Wno-subobject-linkage -Wno-tautological-compare -Wno-uninitialized -Wno-unused-but-set-parameter -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable    -O3 -flto -fno-stack-protector   -Os  -c -o sim_main.o /home/ranrr/pku_workspace/corex/my_c_test/tb_verilator/sim_main.cpp
ccache g++ -Os  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVERILATOR=1 -DVM_COVERAGE=1 -DVM_SC=0 -DVM_TIMING=0 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -DVM_TRACE_SAIF=0 -faligned-new -fcf-protection=none -Wno-bool-operation -Wno-int-in-bool-context -Wno-shadow -Wno-sign-compare -Wno-subobject-linkage -Wno-tautological-compare -Wno-uninitialized -Wno-unused-but-set-parameter -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable    -O3 -flto -fno-stack-protector   -c -o verilated.o /usr/local/share/verilator/include/verilated.cpp
ccache g++ -Os  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVERILATOR=1 -DVM_COVERAGE=1 -DVM_SC=0 -DVM_TIMING=0 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -DVM_TRACE_SAIF=0 -faligned-new -fcf-protection=none -Wno-bool-operation -Wno-int-in-bool-context -Wno-shadow -Wno-sign-compare -Wno-subobject-linkage -Wno-tautological-compare -Wno-uninitialized -Wno-unused-but-set-parameter -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable    -O3 -flto -fno-stack-protector   -c -o verilated_dpi.o /usr/local/share/verilator/include/verilated_dpi.cpp
ccache g++ -Os  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVERILATOR=1 -DVM_COVERAGE=1 -DVM_SC=0 -DVM_TIMING=0 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -DVM_TRACE_SAIF=0 -faligned-new -fcf-protection=none -Wno-bool-operation -Wno-int-in-bool-context -Wno-shadow -Wno-sign-compare -Wno-subobject-linkage -Wno-tautological-compare -Wno-uninitialized -Wno-unused-but-set-parameter -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable    -O3 -flto -fno-stack-protector   -c -o verilated_cov.o /usr/local/share/verilator/include/verilated_cov.cpp
ccache g++ -Os  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVERILATOR=1 -DVM_COVERAGE=1 -DVM_SC=0 -DVM_TIMING=0 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -DVM_TRACE_SAIF=0 -faligned-new -fcf-protection=none -Wno-bool-operation -Wno-int-in-bool-context -Wno-shadow -Wno-sign-compare -Wno-subobject-linkage -Wno-tautological-compare -Wno-uninitialized -Wno-unused-but-set-parameter -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable    -O3 -flto -fno-stack-protector   -c -o verilated_threads.o /usr/local/share/verilator/include/verilated_threads.cpp
python3 /usr/local/share/verilator/bin/verilator_includer -DVL_INCLUDE_OPT=include VCoreTop.cpp VCoreTop___024root__DepSet_h7f65a1f5__0.cpp VCoreTop___024root__DepSet_h8f2c8a57__0.cpp VCoreTop_CoreTop__DepSet_heb703bfa__0.cpp VCoreTop_CoreTop__DepSet_h050a4cf7__0.cpp VCoreTop_Ifu__DepSet_ha92ac939__0.cpp VCoreTop_IMemTop__DepSet_h0db7f785__0.cpp VCoreTop_DBusIf__DepSet_h2245d04d__0.cpp VCoreTop_DBusIf__DepSet_h53d120af__0.cpp VCoreTop_IMem__DepSet_h07e45c05__0.cpp VCoreTop_IBusIf__DepSet_hb077b533__0.cpp VCoreTop_IBusIf__DepSet_h91ed16a8__0.cpp VCoreTop__Dpi.cpp VCoreTop___024root__Slow.cpp VCoreTop___024root__DepSet_h7f65a1f5__0__Slow.cpp VCoreTop___024root__DepSet_h8f2c8a57__0__Slow.cpp VCoreTop_CoreTop__Slow.cpp VCoreTop_CoreTop__DepSet_heb703bfa__0__Slow.cpp VCoreTop_CoreTop__DepSet_h050a4cf7__0__Slow.cpp VCoreTop_Ifu__Slow.cpp VCoreTop_Ifu__DepSet_h544326f2__0__Slow.cpp VCoreTop_Ifu__DepSet_ha92ac939__0__Slow.cpp VCoreTop_IMemTop__Slow.cpp VCoreTop_IMemTop__DepSet_hff6dbdc5__0__Slow.cpp VCoreTop_IMemTop__DepSet_h0db7f785__0__Slow.cpp VCoreTop_DBusIf__Slow.cpp VCoreTop_DBusIf__DepSet_h2245d04d__0__Slow.cpp VCoreTop_DBusIf__DepSet_h53d120af__0__Slow.cpp VCoreTop_IMem__Slow.cpp VCoreTop_IMem__DepSet_h9a7dac6f__0__Slow.cpp VCoreTop_IMem__DepSet_h07e45c05__0__Slow.cpp VCoreTop_IBusIf__Slow.cpp VCoreTop_IBusIf__DepSet_hb077b533__0__Slow.cpp VCoreTop_IBusIf__DepSet_h91ed16a8__0__Slow.cpp VCoreTop__Syms.cpp > VCoreTop__ALL.cpp
ccache g++ -Os  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVERILATOR=1 -DVM_COVERAGE=1 -DVM_SC=0 -DVM_TIMING=0 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -DVM_TRACE_SAIF=0 -faligned-new -fcf-protection=none -Wno-bool-operation -Wno-int-in-bool-context -Wno-shadow -Wno-sign-compare -Wno-subobject-linkage -Wno-tautological-compare -Wno-uninitialized -Wno-unused-but-set-parameter -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable    -O3 -flto -fno-stack-protector   -c -o VCoreTop__ALL.o VCoreTop__ALL.cpp
echo "" > VCoreTop__ALL.verilator_deplist.tmp
g++    sim_main.o verilated.o verilated_dpi.o verilated_cov.o verilated_threads.o VCoreTop__ALL.a   -O3 -flto  -pthread -lpthread -latomic   -o VCoreTop
lto-wrapper: warning: using serial compilation of 5 LTRANS jobs
rm VCoreTop__ALL.verilator_deplist.tmp
make[2]: Leaving directory '/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator/build/binary_search/obj_dir'
- V e r i l a t i o n   R e p o r t: Verilator 5.040 2025-08-30 rev v5.040
- Verilator: Built from 0.382 MB sources in 15 modules, into 0.678 MB in 35 C++ files needing 0.000 MB
- Verilator: Walltime 4.505 s (elab=0.004, cvt=0.046, bld=4.435); cpu 0.071 s on 1 threads; alloced 24.453 MB
/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator/build/binary_search/obj_dir/VCoreTop --hex /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex --iters 50 --expect-idx1 5 --expect-idx2 -1
==============================================================
 [tb] Pure-Verilator C++ testbench
 [tb] hex        : /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
==============================================================
 [tb] loaded 396 bytes (99 words) from /home/ranrr/pku_workspace/corex/my_c_test/build/binary_search/test.hex
--------------------------------------------------------------
 [tb] RESULT             : PASS
 [tb] Setup/Init Overhead: 0.020117 s
 [tb] Total Process Wall Time: 0.081578 s
 [tb] Pure Sim Throughput: 227798.7 cycles/s (4389.841 ns/cycle)
 [tb] Wall-Clock Throughput: 171615.4 cycles/s (5826.982 ns/cycle)
--------------------------------------------------------------
 [tb] Coverage data written to: coverage.dat
make[1]: Leaving directory '/home/ranrr/pku_workspace/corex/my_c_test/tb_verilator'