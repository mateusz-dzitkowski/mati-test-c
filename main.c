#include <stdio.h>

long pow(const long m, const long n) {
    long out = 1;
    for (int i = 0; i < n; i++) {
        out *= m;
    }
    return out;
}

int main() {
    printf("%ld\n", pow(2, 5));

    return 0;
}
