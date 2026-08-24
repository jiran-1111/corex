CROSS_COMPILE ?= riscv64-unknown-elf-
CC          := $(CROSS_COMPILE)gcc
OBJCOPY     := $(CROSS_COMPILE)objcopy
OBJDUMP     := $(CROSS_COMPILE)objdump

# 默认单个测试名称（不带 .c 后缀，如 adder）
TEST ?= adder

BSP_DIR   := bsp
MY_SRC_DIR:= src
BUILD_DIR := build/$(TEST)

# 最小 libc（printf/console）：为裸机提供 stdio.h 环境
LIB_SRCS  := $(BSP_DIR)/libc/printf.c $(BSP_DIR)/libc/console.c

# -ffreestanding：裸机编译，不假设宿主 libc；
# -nostdlib 放在链接命令行尾部（无默认 crt0/libc），再显式 -lgcc 提供软件乘法
# __mulsi3 等（RV32I 无 M 扩展）。
CFLAGS    := -march=rv32i -mabi=ilp32 -O0 -ffreestanding -T $(BSP_DIR)/link.ld \
             -I $(BSP_DIR) -I $(BSP_DIR)/libc

TARGET_ELF := $(BUILD_DIR)/test.elf
TARGET_HEX := $(BUILD_DIR)/test.hex
TARGET_DUMP:= $(BUILD_DIR)/test.dump

# 自动获取 my_src/ 目录下所有 .c 文件的名称（去掉路径和 .c 后缀，例如 adder, sort）
ALL_TESTS := $(patsubst $(MY_SRC_DIR)/%.c,%,$(wildcard $(MY_SRC_DIR)/*.c))

# 默认只编译指定的单个 TEST
all: $(TARGET_HEX) $(TARGET_DUMP)

# 依赖直接指向 my_src/$(TEST).c + 最小 libc 源
$(TARGET_ELF): $(BSP_DIR)/crt0.s $(MY_SRC_DIR)/$(TEST).c $(LIB_SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -nostdlib -lgcc -o $@

$(TARGET_HEX): $(TARGET_ELF)
	$(OBJCOPY) -O verilog $< $@

$(TARGET_DUMP): $(TARGET_ELF)
	$(OBJDUMP) -D $< > $@

# 1. 运行单个指定的测试 (例如 make run TEST=sort 或直接 make run 运行默认的 adder)
#    通用脚本 test_core_program.py 用 -k <TEST> 选中对应的参数化用例
run: all
	python -m pytest testcases/test_core_program.py -k $(TEST) -s -v --log-cli-level=INFO

# 2. 编译并运行 my_src 下的所有 .c 测试 (make run-all)
build-all:
	@for t in $(ALL_TESTS); do \
		echo "Building $$t..."; \
		$(MAKE) TEST=$$t all || exit 1; \
	done

run-all: build-all
	python -m pytest testcases/test_core_program.py -s -v --log-cli-level=INFO

clean:
	rm -rf build/

.PHONY: all clean run run-all build-all

# ==========================================
# RTL 覆盖率测试目标
# ==========================================

# 1. 带覆盖率运行单个测试
run-cov: all
	COVERAGE=1 python -m pytest testcases/test_core_program.py -k $(TEST) -s -v --log-cli-level=INFO
#run-cov: all
#	COVERAGE=1 python -m pytest testcases/test_core_program.py -k $(TEST) \
#		--cov=testcases \
#		--cov-report=html:build/coverage/python_html \
#		-s -v --log-cli-level=INFO
# 2. 带覆盖率运行所有测试并自动生成 HTML 报告
run-all-cov: build-all
	COVERAGE=1 python -m pytest testcases/test_core_program.py -s -v --log-cli-level=INFO
	@$(MAKE) cov-report

# 3. 收集并生成 Verilator 代码覆盖率 HTML 报告
cov-report:
	@echo "==> Collecting Verilator Coverage..."
	@mkdir -p build/coverage
	# 将所有的 .dat 覆盖率文件汇总合并
	verilator_coverage --write build/coverage/coverage.dat build/coverage/*.dat
	# 转换为 lcov 格式
	verilator_coverage --write-info build/coverage/coverage.info build/coverage/coverage.dat
	# 生成 HTML 报告
	genhtml build/coverage/coverage.info --output-directory build/coverage/html
	@echo "==> Coverage Report generated at: build/coverage/html/index.html"


.PHONY: run-cov run-all-cov cov-report