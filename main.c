#include <stdio.h>
#include <stdbool.h>

int main() {
    int c;
    bool was_previously_blank = false;

    while ((c = getchar()) != EOF) {
        const bool is_blank = c == ' ';
        if (!(is_blank & was_previously_blank)) {
            putchar(c);
        }
        was_previously_blank = is_blank;
    }
}
