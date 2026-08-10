# COREX: Pure-Verilator C++ testbench for C-program tests
COREX_ROOT  := $(abspath ../..)
MY_C_TEST   := $(COREX_ROOT)/my_c_test
HDL_DIR     := $(COREX_ROOT)/hdl_sv/core
TB_DIR      := $(MY_C_TEST)/tb_verilator

TOP         := CoreTop
TEST        ?= binary_search

# ---------------------------------------------------------------- COVERAGE ----
# 覆盖率开关控制：支持从命令行传入 COVERAGE=1 或指定具体覆盖率类型
# 支持值：1 (全部), line, toggle, expr, user
ifeq ($(COVERAGE),1)
COV_FLAGS := --coverage
else ifeq ($(COVERAGE),line)
COV_FLAGS := --coverage-line
else ifeq ($(COVERAGE),toggle)
COV_FLAGS := --coverage-toggle
else ifeq ($(COVERAGE),expr)
COV_FLAGS := --coverage-expr
endif

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

VFLAGS := --cc --exe --build --top-module $(TOP) \
          --public-flat-rw \
          -Wno-fatal -Wno-lint -Wno-WIDTH -Wno-UNUSEDSIGNAL \
          -Wno-UNUSEDPARAM -Wno-VARHIDDEN -Wno-CASEINCOMPLETE \
          --Mdir $(OBJ_DIR) \
          $(COV_FLAGS) \
		  -CFLAGS "-O3 -flto -fno-stack-protector" \
          -LDFLAGS "-O3 -flto"

ifneq ($(NODEBUG),1)
VFLAGS += --timing
endif

export OPT_FAST := -O3
export OPT_SLOW := -O3

# ---------------------------------------------------------------- targets ---
.PHONY: all build run perf perf-nodb clean clean-all run-cov cov-report

all: build

build: $(HEX) $(BIN)

$(HEX):
	$(MAKE) -C $(MY_C_TEST) TEST=$(TEST) all

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

perf: build
	$(BIN) --hex $(HEX) --iters 50 --expect-idx1 5 --expect-idx2 -1

perf-nodb:
	$(MAKE) NODEBUG=1 perf

perf-single: build
	$(BIN) --hex $(HEX) --iters 1 --expect-idx1 5 --expect-idx2 -1

perf-single-nodb:
	$(MAKE) NODEBUG=1 perf-single

# -------------------------------------------------------- Coverage Targets ---
# 1. 带覆盖率测试运行单次（测试吞吐量与编译耗时）
run-cov:
	$(MAKE) COVERAGE=1 perf-single
run-cov-50:
	$(MAKE) COVERAGE=1 perf

# 2. 纯仿真模式 + 覆盖率测试（排除 $display 的纯性能对比）
run-cov-nodb:
	$(MAKE) COVERAGE=1 NODEBUG=1 perf-single

# 3. 收集并生成 HTML 报告
cov-report:
	@echo "==> Collecting Pure-Verilator Coverage..."
	@mkdir -p $(TB_DIR)/build/coverage_report
	@verilator_coverage --write $(TB_DIR)/build/coverage_report/coverage.dat *.dat $(BUILD_DIR)/*.dat
	@verilator_coverage --write-info $(TB_DIR)/build/coverage_report/coverage.info $(TB_DIR)/build/coverage_report/coverage.dat
	@genhtml $(TB_DIR)/build/coverage_report/coverage.info --output-directory $(TB_DIR)/build/coverage_report/html
	@echo "==> Pure-Verilator Coverage Report generated at: $(TB_DIR)/build/coverage_report/html/index.html"

clean:
	rm -rf $(TB_DIR)/build *.dat

clean-all: clean
	rm -rf $(MY_C_TEST)/build