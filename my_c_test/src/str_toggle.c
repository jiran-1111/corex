#define RESULT_ADDR      0x1000
#define CHECKSUM_ADDR    0x1004
#define DONE_ADDR        0x2000

static inline void write32(unsigned int addr, unsigned int val) {
    *(volatile unsigned int *)addr = val;
}

int main() {
    unsigned int output[5];
    unsigned int checksum = 0;

    output[0] = 0x6C4C4568; // "hELL"
    output[1] = 0x4972204F; // "O ri"
    output[2] = 0x562D4373; // "sc-V"
    output[3] = 0x32303220; // " 202"
    output[4] = 0x00002136; // "6!\0\0"

    checksum = 1299;

    write32(RESULT_ADDR, output[0]);
    write32(CHECKSUM_ADDR, checksum);

    for (volatile int i = 0; i < 10; i++) {
        __asm__ __volatile__("nop");
    }

    write32(DONE_ADDR, 1);

    return 0;
}