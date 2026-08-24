// 来源：c_test/zsq/bubble_sort.c（2026-08-24 适配 corex 测试约定）
// 适配：done 标志地址 0x8000 → 0x2000（corex 统一约定，0x8000 超出 DMem 范围）

int main() {
    int arr[8];
    arr[0] = 64; arr[1] = 34; arr[2] = 25; arr[3] = 12;
    arr[4] = 22; arr[5] = 11; arr[6] = 90; arr[7] = 45;
    int n = 8;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    volatile int *result = (volatile int *)0x1000;
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    *(volatile int *)0x2000 = 1;
    return 0;
}
