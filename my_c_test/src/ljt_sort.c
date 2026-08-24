#include <stdio.h>

int main()
{
    volatile int data[4] = {7, 2, 5, 1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf(
        "%d %d %d %d",
        data[0],
        data[1],
        data[2],
        data[3]
    );

    return 0;
}
