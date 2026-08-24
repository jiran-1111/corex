// 来源：c_test/ljt/sort.c（2026-08-24 适配 corex 裸机测试约定）
// 适配：去掉 printf/stdio；数组改为逐个赋值（初始化列表的字面量池在 corex
//       下 DMem 读不到）；结果写 DMem 0x1000 起，结束写 0x2000=1
// 期望：冒泡排序 {7,2,5,1} → {1,2,5,7}

int main() {
    int data[4];
    data[0] = 7; data[1] = 2; data[2] = 5; data[3] = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    volatile int *result = (volatile int *)0x1000;
    for (int i = 0; i < 4; i++) {
        result[i] = data[i];
    }
    *(volatile int *)0x2000 = 1;
    return 0;
}
