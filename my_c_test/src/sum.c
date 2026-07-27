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
