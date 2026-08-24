// 来源：c_test/zsq/mem_ops.c（2026-08-24 适配 corex 测试约定）
// 适配：done 标志地址 0x8000 → 0x2000（corex 统一约定，0x8000 超出 DMem 范围）
// 期望：0x1020 处 sum = 5+10+15+20 = 50

int main() {
    volatile int *mem = (volatile int *)0x1000;
    mem[0] = 5; mem[1] = 10; mem[2] = 15; mem[3] = 20;
    int sum = mem[0] + mem[1] + mem[2] + mem[3];
    volatile int *result = (volatile int *)0x1020;
    *result = sum;
    *(volatile int *)0x2000 = 1;
    return sum;
}
