#include <stdio.h>

#define BLANKS_PER_TAB 8

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0; i < BLANKS_PER_TAB; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
