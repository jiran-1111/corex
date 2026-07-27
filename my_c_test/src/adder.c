#define RESULT_ADDR ((volatile int *) 0x00000100)

int main() {
    int a = 3;
    int b = 5;
    int c = a + b;

    *RESULT_ADDR = c;
 
    return 0;
}