__attribute__((noinline))
unsigned int crc32(const unsigned char *data, int len) {
    unsigned int crc = 0xFFFFFFFF;

    const unsigned int *word_ptr = (const unsigned int *)data;

    for (int i = 0; i < len; i++) {
        int word_idx = i >> 2;          // i / 4
        int byte_offset = i & 3;        // i % 4

        unsigned int current_word = word_ptr[word_idx];
        unsigned char current_byte = (unsigned char)((current_word >> (byte_offset * 8)) & 0xFF);

        crc ^= current_byte;
        for (int j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            } else {
                crc >>= 1;
            }
        }
    }
    return ~crc; 
}

int main() {

    __attribute__((aligned(4))) unsigned char msg[12] = {
        '1', '2', '3', '4', '5', '6', '7', '8', '9', 0, 0, 0
    };
    unsigned int result = crc32(msg, 9);
    *(volatile unsigned int *)0x1000 = result;
    *(volatile int *)0x2000 = 1;
    return 0;
}