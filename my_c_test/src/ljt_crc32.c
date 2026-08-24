// 来源：c_test/ljt/crc32.c（2026-08-24 适配 corex 裸机测试约定）
// 适配：去掉 printf/stdio；字符串改为 int 数组存 ASCII + word 访问
//       （char 字节存取在 corex 下不可靠，见 ljt_reverse 注释）；
//       结果写 DMem 0x1000，结束写 0x2000=1
// 期望：CRC32("123456789")/IEEE 802.3 = 0xCBF43926

int main()
{
    int text[9];
    text[0] = 49; text[1] = 50; text[2] = 51; text[3] = 52; text[4] = 53;  // "12345"
    text[5] = 54; text[6] = 55; text[7] = 56; text[8] = 57;                // "6789"

    unsigned crc = 0xffffffffu;
    for (int i = 0; i < 9; i++) {
        crc ^= (unsigned)text[i];
        for (int bit = 0; bit < 8; bit++) {
            unsigned mask = 0u - (crc & 1u);
            crc = (crc >> 1) ^ (0xedb88320u & mask);
        }
    }

    volatile unsigned int *out = (volatile unsigned int *)0x1000;
    out[0] = ~crc;
    *(volatile int *)0x2000 = 1;
    return 0;
}
