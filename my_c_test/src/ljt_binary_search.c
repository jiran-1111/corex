#include <stdio.h>

__attribute__((noinline))
int binary_search(volatile int *data, int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        int value = data[middle];

        if (value == target) {
            return middle;
        }
        if (value < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main()
{
    volatile int data[] = {1, 3, 5, 7, 9, 11};
    int found = binary_search(data, 6, 7);
    int missing = binary_search(data, 6, 6);

    printf("%d %d", found, missing);
    return 0;
}
