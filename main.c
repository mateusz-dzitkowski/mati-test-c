#include <stdio.h>
#include <stdbool.h>

#define MAX_WORD_LEN (20)

int main() {
    int c;
    int current_word_len = 0;

    int lengths[MAX_WORD_LEN];
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        const bool is_whitespace = c == ' ' || c == '\t' || c == '\n';

        if (is_whitespace) {
            if (current_word_len > 0) {
                lengths[current_word_len]++;
                current_word_len = 0;
            }
        } else {
            current_word_len++;
        }
    }

    for (int i = 1; i < MAX_WORD_LEN; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < lengths[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}
