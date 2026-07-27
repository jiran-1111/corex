/*
 * @COREX: Co-modeling RISC-V Example Core
 * 
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 * 
 * @Author: Ran Ji
 */
volatile int x=0;

__attribute__((noinline))
void func()
{
    x=123;
}

int main()
{
    func();

    *(volatile int*)0x2000=1;
}