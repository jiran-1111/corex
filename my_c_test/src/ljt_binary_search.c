// 来源：c_test/ljt/binary_search.c（2026-08-24 适配 corex 裸机测试约定）
// 适配：去掉 printf/stdio；数组改为逐个赋值（初始化列表的字面量池在 corex
//       下 DMem 读不到）；结果写 DMem 0x1000/0x1004，结束写 0x2000=1
// 期望：data={1,3,5,7,9,11} 中找 7 → index 3；找 6（不存在）→ -1(0xFFFFFFFF)

int binary_search(int *data, int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;   // 除以 2 编译为移位
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
    int data[6];
    data[0] = 1; data[1] = 3; data[2] = 5;
    data[3] = 7; data[4] = 9; data[5] = 11;
    int found = binary_search(data, 6, 7);
    int missing = binary_search(data, 6, 6);

    volatile int *result = (volatile int *)0x1000;
    result[0] = found;
    result[1] = missing;
    *(volatile int *)0x2000 = 1;
    return 0;
}
