CROSS_COMPILE ?= riscv64-unknown-elf-
CC      := $(CROSS_COMPILE)gcc
OBJCOPY := $(CROSS_COMPILE)objcopy
OBJDUMP := $(CROSS_COMPILE)objdump

# -O0 禁用优化，让生成的指令更直观；-nostdlib 禁用标准库
CFLAGS  := -march=rv32i -mabi=ilp32 -O0 -nostdlib -T link.ld

all: add_test.hex add_test.dump

add_test.elf: crt0.s main.c
	$(CC) $(CFLAGS) crt0.s main.c -o add_test.elf

# 导出 Verilog Hex 格式
add_test.hex: add_test.elf
	$(OBJCOPY) -O verilog add_test.elf add_test.hex

# 导出反汇编，用于调试
add_test.dump: add_test.elf
	$(OBJDUMP) -D add_test.elf > add_test.dump

clean:
	rm -f *.elf *.hex *.dump