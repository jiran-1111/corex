#include <stdio.h>

volatile int call_count;

__attribute__((noinline, optimize("O0")))
int factorial(int n)
{
    call_count++;
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int result = factorial(6);
    printf("%d %d", result, call_count);
    return 0;
}
