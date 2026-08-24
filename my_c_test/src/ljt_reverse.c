// 来源：c_test/ljt/reverse.c（2026-08-24 适配 corex 裸机测试约定）
// 适配：去掉 printf/stdio；原程序用 char 数组 + 字节存取（corex 字节访存
//       LB/SB 不可靠），改为 int 数组存字符 ASCII + word 访问；
//       结果写 DMem 0x1000 起，结束写 0x2000=1
// 期望："COREX" 反转 = "XEROC"，ASCII = [88,69,82,79,67]

int main() {
    int input[5], output[5];
    input[0] = 67; input[1] = 79; input[2] = 82; input[3] = 69; input[4] = 88;  // "COREX"

    for (int i = 0; i < 5; i++) {
        output[i] = input[4 - i];
    }

    volatile int *result = (volatile int *)0x1000;
    for (int i = 0; i < 5; i++) {
        result[i] = output[i];
    }
    *(volatile int *)0x2000 = 1;
    return 0;
}
