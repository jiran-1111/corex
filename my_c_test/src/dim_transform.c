// 来源：c_test/dim/main.c（2026-08-24 适配 corex 裸机测试约定）
// 适配：原程序用 .data 段的静态数组 values[8]（corex 测试不加载 .data 段，
//       DMem 默认全零），改为 main 内局部数组由指令初始化；
//       结果 (sum & 0x1f) + 65 写 DMem 0x1000，结束写 0x2000=1
// 期望：sum = 173，result = (173 & 0x1f) + 65 = 78

typedef unsigned int uint32_t;

static uint32_t transform(uint32_t value, uint32_t index)
{
    /* value * 3，写成移位加法以避免乘法指令。 */
    uint32_t result = (value << 1) + value;

    result ^= index + 0x12;

    if (result & 1)
        result += 7;
    else
        result -= 3;

    return result;
}

int main(void)
{
    uint32_t values[8];
    values[0] = 3; values[1] = 1; values[2] = 4; values[3] = 1;
    values[4] = 5; values[5] = 9; values[6] = 2; values[7] = 6;

    uint32_t sum = 0;

    for (uint32_t i = 0; i < 8; ++i)
        sum += transform(values[i], i);

    volatile uint32_t *result = (volatile uint32_t *)0x1000;
    result[0] = (sum & 0x1f) + 65;
    *(volatile uint32_t *)0x2000 = 1;
    return 0;
}
