#include <stdio.h>
#include <stdbool.h>

int main() {
    int c;

    bool in_word = false;
    long lines = 0;
    long words = 0;
    long chars = 0;

    while ((c = getchar()) != EOF) {
        chars++;

        if (c == '\n') {
            lines++;
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            in_word = false;
        } else if (!in_word) {
            in_word = true;
            words++;
        }
    }

    printf("\t%ld\t%ld\t%ld\n", lines, words, chars);
}
