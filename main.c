#include <stdio.h>

int main() {
    int c;
    long whitespace = 0;
    long digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long others = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            digits[c - '0']++;
        } else if (c == ' ' || c == '\t' || c == '\n') {
            whitespace++;
        } else {
            others++;
        }
    }

    printf("whitespace: %ld\n", whitespace);
    for (int i = 0; i <= 9; i++) {
        printf("digit %d: %ld\n", i, digits[i]);
    }
    printf("others: %ld\n", others);
}
