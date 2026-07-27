/*
 * @COREX: Co-modeling RISC-V Example Core - Factorial Test
 * 
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 * 
 * @Author: Ran Ji
 */

volatile int call_count = 0;

// 软件位移实现乘法 (适应 RV32I 基础指令集，避免使用 mul 指令)
__attribute__((noinline))
int multiply(volatile int a, volatile int b) {
    int result = 0;
    while (b > 0) {
        if (b & 1) {
            result += a;
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

// 递归阶乘实现
__attribute__((noinline))
int factorial(int n) {
    call_count++;
    if (n <= 1) {
        return 1;
    }
    return multiply(n, factorial(n - 1));
}

int main() {
    volatile int n = 6;
    int result = factorial(n);

    // 将计算结果写入 MMIO 内存地址供 Python/cocotb 校验
    *(volatile int *)0x1000 = result;      // 0x1000 存储阶乘结果 (6! = 720)
    *(volatile int *)0x1004 = call_count;  // 0x1004 存储 call_count 次数 (6)

    // 写入 0x2000 = 1 标识程序执行完毕
    *(volatile int *)0x2000 = 1;

    return 0;
}