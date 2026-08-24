// 来源：c_test/ljt/factorial.c（2026-08-24 适配 corex 裸机测试约定）
// 适配：去掉 printf/stdio；变量乘法改为软件 multiply（RV32I 无 M 扩展）；
//       call_count 由全局 volatile 改为局部变量 + 指针（避免依赖 .bss 段）；
//       结果写 DMem 0x1000/0x1004，结束写 0x2000=1
// 期望：factorial(6)=720，递归调用 6 次

int multiply(int a, int b) {
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

int factorial(int n, int *count)
{
    (*count)++;
    if (n <= 1) {
        return 1;
    }
    return multiply(n, factorial(n - 1, count));
}

int main()
{
    int call_count = 0;
    int result = factorial(6, &call_count);

    volatile int *out = (volatile int *)0x1000;
    out[0] = result;
    out[1] = call_count;
    *(volatile int *)0x2000 = 1;
    return 0;
}
