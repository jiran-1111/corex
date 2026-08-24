#include <stdio.h>

int main()
{
    const char *text = "123456789";
    unsigned crc = 0xffffffffu;

    while (*text) {
        crc ^= (unsigned char)*text++;
        for (int bit = 0; bit < 8; bit++) {
            unsigned mask = 0u - (crc & 1u);
            crc = (crc >> 1) ^ (0xedb88320u & mask);
        }
    }

    printf("%x", ~crc);
    return 0;
}
