#define x (*(volatile int*)0x1000)

__attribute__((noinline))
void func()
{
    x = 123;
}

int main()
{
    func();
    *(volatile int*)0x2000 = 1;
    return 0;
}