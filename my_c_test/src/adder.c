#define RESULT_ADDR ((volatile int *) 0x00001000)
#define DONE_ADDR   ((volatile int *) 0x2000)

int main() {
    int a = 3;
    int b = 5;
    int c = a + b;

    *RESULT_ADDR = c;
    *DONE_ADDR = 1;
    return 0;
}