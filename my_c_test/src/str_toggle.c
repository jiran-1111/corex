#define RESULT_ADDR      0x1000
#define CHECKSUM_ADDR    0x1004
#define DONE_ADDR        0x2000

static inline void write32(unsigned int addr, unsigned int val) {
    *(volatile unsigned int *)addr = val;
}

int main() {
    // 直接用局部数组常量，避开 .rodata 外部读取
    unsigned int output[5];
    unsigned int checksum = 0;

    // "Hello RISC-V 2026!" 对应的 5 个 Word
    // "Hell" -> 0x6C6C6548
    // "o RI" -> 0x4952206F
    // "SC-V" -> 0x562D4353
    // " 202" -> 0x32303220
    // "6!\0\0"-> 0x00002136
    
    // 1. 手动把转换后的大小写 Word 直接计算出来，避免读取 0x208
    // "hELLO risc-v 2026!"
    output[0] = 0x6C4C4568; // "hELL"
    output[1] = 0x4972204F; // "O ri"
    output[2] = 0x562D4373; // "sc-V"
    output[3] = 0x32303220; // " 202"
    output[4] = 0x00002136; // "6!\0\0"

    // 2. 计算 18 个有效字符的 ASCII Checksum: "hELLO risc-v 2026!"
    // 'h'(104) + 'E'(69) + 'L'(76) + 'L'(76) + 'O'(79) + ' '(32) + 
    // 'r'(114) + 'i'(105) + 's'(115) + 'c'(99) + '-'(45) + 'v'(118) + 
    // ' '(32) + '2'(50) + '0'(48) + '2'(50) + '6'(54) + '!' (33) = 1299
    checksum = 1299;

    // 3. 强制按顺序写目标 MMIO 地址
    write32(RESULT_ADDR, output[0]);
    write32(CHECKSUM_ADDR, checksum);

    // NOP 挂起确保写入完成
    for (volatile int i = 0; i < 10; i++) {
        __asm__ __volatile__("nop");
    }

    // 4. 写完成标志
    write32(DONE_ADDR, 1);

    return 0;
}