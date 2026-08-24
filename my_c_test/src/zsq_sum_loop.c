// 来源：c_test/zsq/sum_loop.c（2026-08-24 适配 corex 测试约定）
// 适配：done 标志地址 0x8000 → 0x2000（corex 统一约定，0x8000 超出 DMem 范围）
// 期望：0x1000 处 sum = 1..10 = 55

int main() {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    volatile int *result = (volatile int *)0x1000;
    *result = sum;
    *(volatile int *)0x2000 = 1;
    return sum;
}
