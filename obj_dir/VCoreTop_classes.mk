# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See VCoreTop.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 1
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace-fst/--trace-saif/--trace-vcd)
VM_TRACE = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
  VCoreTop \
  VCoreTop___024root__DepSet_h7f65a1f5__0 \
  VCoreTop___024root__DepSet_h8f2c8a57__0 \
  VCoreTop_CoreTop__DepSet_heb703bfa__0 \
  VCoreTop_CoreTop__DepSet_h050a4cf7__0 \
  VCoreTop_Ifu__DepSet_h544326f2__0 \
  VCoreTop_Ifu__DepSet_ha92ac939__0 \
  VCoreTop_IMemTop__DepSet_h0db7f785__0 \
  VCoreTop_DBusIf__DepSet_h2245d04d__0 \
  VCoreTop_DBusIf__DepSet_h53d120af__0 \
  VCoreTop_IMem__DepSet_h07e45c05__0 \
  VCoreTop_IBusIf__DepSet_hb077b533__0 \
  VCoreTop_IBusIf__DepSet_h91ed16a8__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
  VCoreTop___024root__Slow \
  VCoreTop___024root__DepSet_h7f65a1f5__0__Slow \
  VCoreTop___024root__DepSet_h8f2c8a57__0__Slow \
  VCoreTop_CoreTop__Slow \
  VCoreTop_CoreTop__DepSet_heb703bfa__0__Slow \
  VCoreTop_CoreTop__DepSet_h050a4cf7__0__Slow \
  VCoreTop_Ifu__Slow \
  VCoreTop_Ifu__DepSet_h544326f2__0__Slow \
  VCoreTop_Ifu__DepSet_ha92ac939__0__Slow \
  VCoreTop_IMemTop__Slow \
  VCoreTop_IMemTop__DepSet_hff6dbdc5__0__Slow \
  VCoreTop_DBusIf__Slow \
  VCoreTop_DBusIf__DepSet_h2245d04d__0__Slow \
  VCoreTop_IMem__Slow \
  VCoreTop_IMem__DepSet_h9a7dac6f__0__Slow \
  VCoreTop_IMem__DepSet_h07e45c05__0__Slow \
  VCoreTop_IBusIf__Slow \
  VCoreTop_IBusIf__DepSet_hb077b533__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
  VCoreTop__Dpi \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
  VCoreTop__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
  verilated \
  verilated_dpi \
  verilated_cov \
  verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \

# Verilated -*- Makefile -*-
