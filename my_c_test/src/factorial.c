volatile int call_count = 0;

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

    *(volatile int *)0x1000 = result;  
    *(volatile int *)0x1004 = call_count; 

    *(volatile int *)0x2000 = 1;

    return 0;
}