// 来源：c_test/ljt/matrix.c（2026-08-24 适配 corex 裸机测试约定）
// 适配：去掉 printf/stdio（-nostdlib 无标准库）；变量乘法改为软件 multiply
//       （RV32I 无 M 扩展）；数组用逐个赋值（初始化列表的字面量池在 corex 下
//       DMem 读不到）；结果写 DMem 0x1000 起，结束写 0x2000=1
// 期望：2×2 矩阵乘 c = {{1,2},{3,4}} × {{5,6},{7,8}} = {{19,22},{43,50}}

int multiply(int a, int b) {
    int result = 0;
    while (b > 0) {
        if (b & 1) {
            result += a;
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

int main() {
    int a[2][2], b[2][2], c[2][2];
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;
    c[0][0] = 0; c[0][1] = 0; c[1][0] = 0; c[1][1] = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += multiply(a[i][k], b[k][j]);
            }
        }
    }

    volatile int *result = (volatile int *)0x1000;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i * 2 + j] = c[i][j];
        }
    }
    *(volatile int *)0x2000 = 1;
    return 0;
}
