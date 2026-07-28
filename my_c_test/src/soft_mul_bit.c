#define RESULT_ADDR   0x1000
#define CHECKSUM_ADDR 0x1004
#define DONE_ADDR     0x2000

static inline void write32(unsigned int addr, unsigned int val) {
    *(volatile unsigned int *)addr = val;
}

// 纯 RV32I 移位加法模拟乘法
unsigned int soft_mul(unsigned int a, unsigned int b) {
    unsigned int res = 0;
    while (b > 0) {
        if (b & 1) {
            res += a;
        }
        a <<= 1;
        b >>= 1;
    }
    return res;
}

int main() {
    unsigned int x = 1234;
    unsigned int y = 5678;

    unsigned int product = soft_mul(x, y); // 7006652 (0x006AEBBC)

    // 位翻转测试
    unsigned int bit_reversed = 0;
    unsigned int temp = product;
    for (int i = 0; i < 32; i++) {
        bit_reversed = (bit_reversed << 1) | (temp & 1);
        temp >>= 1;
    }

    unsigned int checksum = product ^ bit_reversed;

    write32(RESULT_ADDR, product);
    write32(CHECKSUM_ADDR, checksum);

    for (volatile int i = 0; i < 5; i++) __asm__ __volatile__("nop");

    write32(DONE_ADDR, 1);
    return 0;
}