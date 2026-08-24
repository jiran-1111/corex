// 来源：c_test/zsq/fibonacci.c（2026-08-24 适配 corex 测试约定）
// 适配：done 标志地址 0x8000 → 0x2000（corex 统一约定，0x8000 超出 DMem 范围）

int main() {
    int fib[10];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 10; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    volatile int *result = (volatile int *)0x1000;
    for (int i = 0; i < 10; i++) {
        result[i] = fib[i];
    }
    *(volatile int *)0x2000 = 1;
    return 0;
}
