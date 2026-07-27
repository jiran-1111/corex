CROSS_COMPILE ?= riscv64-unknown-elf-
CC          := $(CROSS_COMPILE)gcc
OBJCOPY     := $(CROSS_COMPILE)objcopy
OBJDUMP     := $(CROSS_COMPILE)objdump

# 默认单个测试名称（不带 .c 后缀，如 adder）
TEST ?= adder

BSP_DIR   := bsp
MY_SRC_DIR:= src
BUILD_DIR := build/$(TEST)

CFLAGS    := -march=rv32i -mabi=ilp32 -O0 -nostdlib -T $(BSP_DIR)/link.ld -I $(BSP_DIR)

TARGET_ELF := $(BUILD_DIR)/test.elf
TARGET_HEX := $(BUILD_DIR)/test.hex
TARGET_DUMP:= $(BUILD_DIR)/test.dump

# 自动获取 my_src/ 目录下所有 .c 文件的名称（去掉路径和 .c 后缀，例如 adder, sort）
ALL_TESTS := $(patsubst $(MY_SRC_DIR)/%.c,%,$(wildcard $(MY_SRC_DIR)/*.c))

# 默认只编译指定的单个 TEST
all: $(TARGET_HEX) $(TARGET_DUMP)

# 依赖直接指向 my_src/$(TEST).c
$(TARGET_ELF): $(BSP_DIR)/crt0.s $(MY_SRC_DIR)/$(TEST).c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET_HEX): $(TARGET_ELF)
	$(OBJCOPY) -O verilog $< $@

$(TARGET_DUMP): $(TARGET_ELF)
	$(OBJDUMP) -D $< > $@

# 1. 运行单个指定的测试 (例如 make run TEST=sort 或直接 make run 运行默认的 adder)
run: all
	python -m pytest testcases/test_core_$(TEST).py -s -v --log-cli-level=INFO

# 2. 编译并运行 my_src 下的所有 .c 测试 (make run-all)
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