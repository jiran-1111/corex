/*
 * @COREX: Co-modeling RISC-V Example Core
 * 
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 * 
 * @Author: Ran Ji
 */

// 将结果写到数据存储器 (DMem) 的 0x100 地址处，方便 Cocotb 读取验证
#define RESULT_ADDR ((volatile int *) 0x00000100)

int main() {
    int a = 3;
    int b = 5;
    int c = a + b;

    *RESULT_ADDR = c; // 把 8 写入 0x100 处
 
    return 0;
}