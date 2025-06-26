#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
 ((byte) & 0x80 ? '1' : '0'), \
 ((byte) & 0x40 ? '1' : '0'), \
 ((byte) & 0x20 ? '1' : '0'), \
 ((byte) & 0x10 ? '1' : '0'), \
 ((byte) & 0x08 ? '1' : '0'), \
 ((byte) & 0x04 ? '1' : '0'), \
 ((byte) & 0x02 ? '1' : '0'), \
 ((byte) & 0x01 ? '1' : '0')
#define PRINT_BITS(x) printf(BYTE_TO_BINARY_PATTERN "\n", BYTE_TO_BINARY(x))

unsigned int set_bits(const unsigned int x, const int p, const int n, const unsigned int y) {
    const int shift = p - n + 1;
    const int mask_static = (1 << n) - 1;
    const int mask = mask_static << shift;
    return x & ~mask | (y & mask_static) << shift;
}

int main() {
    const unsigned int x = 992;
    const unsigned int y = 5;
    const unsigned int z = set_bits(x, 4, 3, y);

    PRINT_BITS(z);

    return 0;
}
