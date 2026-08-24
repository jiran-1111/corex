// 来源：c_test/zsq/quick_sort.c（2026-08-24 适配 corex 测试约定）
// 适配：done 标志地址 0x8000 → 0x2000（corex 统一约定，0x8000 超出 DMem 范围）

int main() {
    int arr[8];
    arr[0] = 64; arr[1] = 34; arr[2] = 25; arr[3] = 12;
    arr[4] = 22; arr[5] = 11; arr[6] = 90; arr[7] = 45;
    int n = 8;
    int stack[16];
    int top = 0;
    stack[top++] = 0;
    stack[top++] = n - 1;
    while (top > 0) {
        int hi = stack[--top];
        int lo = stack[--top];
        if (lo >= hi) continue;
        int pivot = arr[hi];
        int i = lo - 1;
        for (int j = lo; j < hi; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[hi];
        arr[hi] = temp;
        int p = i + 1;
        stack[top++] = lo;
        stack[top++] = p - 1;
        stack[top++] = p + 1;
        stack[top++] = hi;
    }
    volatile int *result = (volatile int *)0x1000;
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    *(volatile int *)0x2000 = 1;
    return 0;
}
