# COREX: Pure-Verilator C++ testbench for C-program tests
#
# No cocotb / no VPI: builds the CoreTop with verilator --exe and runs a
# standalone C++ driver.
#
#   make run  TEST=binary_search   # functional check
#   make perf TEST=binary_search   # throughput, RTL debug $display kept
#   make perf-nodb TEST=...        # throughput, debug monitor stripped (pure sim)
#
# Author: Ran Ji

# ---------------------------------------------------------------- paths ----
COREX_ROOT  := $(abspath ../..)
MY_C_TEST   := $(COREX_ROOT)/my_c_test
HDL_DIR     := $(COREX_ROOT)/hdl_sv/core
TB_DIR      := $(MY_C_TEST)/tb_verilator

TOP        := CoreTop
TEST       ?= binary_search

# Pick core.sv source: keep the debug monitor, or strip it for clean perf runs.
# NODEBUG must come from the command line / recursive make so it resolves at
# parse time (BUILD_DIR uses := and cannot see target-specific variables).
ifeq ($(NODEBUG),1)
BUILD_DIR  := $(TB_DIR)/build/$(TEST)-nodb
CORE_SRC   := $(BUILD_DIR)/core_nodb.sv
else
BUILD_DIR  := $(TB_DIR)/build/$(TEST)
CORE_SRC   := $(HDL_DIR)/core.sv
endif

OBJ_DIR    := $(BUILD_DIR)/obj_dir
BIN        := $(OBJ_DIR)/V$(TOP)

HEX        := $(MY_C_TEST)/build/$(TEST)/test.hex

VERILATOR  ?= verilator

# HDL sources, in dependency order (must match the cocotb test list).
HDL_SRC := \
	$(HDL_DIR)/control_unit.sv \
	$(HDL_DIR)/ibus_if.sv \
	$(HDL_DIR)/dbus_if.sv \
	$(HDL_DIR)/imem.sv \
	$(HDL_DIR)/dmem.sv \
	$(HDL_DIR)/reg_file.sv \
	$(HDL_DIR)/pipeline_reg.sv \
	$(HDL_DIR)/decoder.sv \
	$(HDL_DIR)/ALU.sv \
	$(HDL_DIR)/execute.sv \
	$(HDL_DIR)/ifu.sv \
	$(HDL_DIR)/core.sv

# Verilator flags.
#  - --public-flat-rw: flatten all signals so the DMem array is reachable
#                     without touching the RTL
#  - --exe --build   : compile testbench + link executable in one step
#  - --timing        : only needed for the $display/$time debug monitor in
#                      core.sv; omitted for the pure-sim (NODEBUG) build.
VFLAGS := --cc --exe --build --top-module $(TOP) \
          --public-flat-rw \
          -Wno-fatal -Wno-lint -Wno-WIDTH -Wno-UNUSEDSIGNAL \
          -Wno-UNUSEDPARAM -Wno-VARHIDDEN -Wno-CASEINCOMPLETE \
          --Mdir $(OBJ_DIR)
ifneq ($(NODEBUG),1)
VFLAGS += --timing
endif

# Compile the generated model at -O3 (measured ~1.6x faster than the default
# -Os); exported so verilator --build's inner make picks it up.
export OPT_FAST := -O3
export OPT_SLOW := -O3

# ---------------------------------------------------------------- targets ---
.PHONY: all build run perf perf-nodb clean clean-all

all: build

build: $(HEX) $(BIN)

# Cross-compile the C program to hex if it is missing (reuses my_c_test flow).
$(HEX):
	$(MAKE) -C $(MY_C_TEST) TEST=$(TEST) all

# Strip the DEBUG_CORE monitor into a per-build source file (NODEBUG mode).
$(CORE_SRC): $(HDL_DIR)/core.sv
	@mkdir -p $(BUILD_DIR)
	@echo "==> Stripping DEBUG_CORE monitor from core.sv"
	awk '/`ifdef DEBUG_CORE/{f=1; next} /`endif/{f=0; next} !f' $< | grep -v '`define DEBUG_CORE' > $@
	@if ! grep -q "endmodule" $@; then \
		echo "ERROR: stripping DEBUG_CORE produced an invalid core.sv"; exit 1; fi

$(BIN): $(TB_DIR)/sim_main.cpp $(HDL_SRC) $(CORE_SRC)
	@mkdir -p $(BUILD_DIR)
	$(VERILATOR) $(VFLAGS) \
		$(TB_DIR)/sim_main.cpp \
		$(filter-out $(HDL_DIR)/core.sv,$(HDL_SRC)) $(CORE_SRC)

run: build
	$(BIN) --hex $(HEX) --expect-idx1 5 --expect-idx2 -1

# Repeated-iteration throughput benchmark (avg cycles/s, debug prints on).
perf: build
	$(BIN) --hex $(HEX) --iters 50 --expect-idx1 5 --expect-idx2 -1

# Pure-sim throughput: debug $display monitor stripped.  Recursive make so
# NODEBUG reaches the parse-time BUILD_DIR/CORE_SRC/VFLAGS assignments.
perf-nodb:
	$(MAKE) NODEBUG=1 perf

clean:
	rm -rf $(TB_DIR)/build

clean-all: clean
	rm -rf $(MY_C_TEST)/build

# 在 Makefile 中增加一个单次公平基准测试目标
.PHONY: perf-single perf-single-nodb

# 只跑 1 次，模拟 cocotb 的真实单次工作流
perf-single: build
	$(BIN) --hex $(HEX) --iters 1 --expect-idx1 5 --expect-idx2 -1

perf-single-nodb:
	$(MAKE) NODEBUG=1 perf-single
