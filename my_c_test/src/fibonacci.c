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
