#include <stdio.h>

int main()
{
    volatile char input[] = "COREX";
    char output[6];

    for (int i = 0; i < 5; i++) {
        output[i] = input[4 - i];
    }
    output[5] = '\0';

    printf("%s", output);
    return 0;
}
