CROSS_COMPILE ?= riscv64-unknown-elf-
CC          := $(CROSS_COMPILE)gcc
OBJCOPY     := $(CROSS_COMPILE)objcopy
OBJDUMP     := $(CROSS_COMPILE)objdump

# 默认单个测试名称
TEST ?= adder

BSP_DIR   := bsp
SRC_DIR   := src/$(TEST)
BUILD_DIR := build/$(TEST)

CFLAGS    := -march=rv32i -mabi=ilp32 -O0 -nostdlib -T $(BSP_DIR)/link.ld -I $(BSP_DIR)

TARGET_ELF := $(BUILD_DIR)/test.elf
TARGET_HEX := $(BUILD_DIR)/test.hex
TARGET_DUMP:= $(BUILD_DIR)/test.dump

# 自动获取 src/ 目录下的所有测试用例名称 (例如 adder sort factorial)
ALL_TESTS := $(notdir $(wildcard src/*))

# 默认只编译指定的单个 TEST
all: $(TARGET_HEX) $(TARGET_DUMP)

$(TARGET_ELF): $(BSP_DIR)/crt0.s $(SRC_DIR)/main.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET_HEX): $(TARGET_ELF)
	$(OBJCOPY) -O verilog $< $@

$(TARGET_DUMP): $(TARGET_ELF)
	$(OBJDUMP) -D $< > $@

# 1. 运行单个指定的测试 (例如 make run TEST=sort)
run: all
	
	python -m pytest testcases/test_core_$(TEST).py -s -v --log-cli-level=INFO

# 2. 编译并运行所有测试 (make run-all)
build-all:
	@for t in $(ALL_TESTS); do \
		echo "Building $$t..."; \
		$(MAKE) TEST=$$t all || exit 1; \
	done
	

run-all: build-all
	python -m pytest testcases/

clean:
	rm -rf build/

.PHONY: all clean run run-all build-all