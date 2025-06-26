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

unsigned int invert(const unsigned int x, const int p, const int n) {
    const int bits_of_interest = x >> (p - n + 1);
    return set_bits(x, p, n, ~bits_of_interest);
}


int main() {
    const unsigned int x = 992;
    const unsigned int y = 5;
    const unsigned int z = set_bits(x, 4, 3, y);
    const unsigned int t = invert(z, 4, 3);

    PRINT_BITS(x);
    PRINT_BITS(z);
    PRINT_BITS(t);

    return 0;
}
