
__attribute__((noinline))
int binary_search(const int *arr, int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        int mid_val = arr[mid];

        if (mid_val == target) {
            return mid;
        }
        if (mid_val < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    // Explicit element assignments force the compiler to generate SW instructions 
    // directly on the stack, eliminating reliance on .rodata/.data section loading.
    int arr[8];
    arr[0] = 2;
    arr[1] = 5;
    arr[2] = 8;
    arr[3] = 12;
    arr[4] = 16;
    arr[5] = 23;
    arr[6] = 38;
    arr[7] = 56;

    int idx1 = binary_search(arr, 8, 23);
    int idx2 = binary_search(arr, 8, 99);

    *(volatile int *)0x1000 = idx1;
    *(volatile int *)0x1004 = idx2;

    // Signal completion
    *(volatile int *)0x2000 = 1;

    return 0;
}