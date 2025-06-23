#include <stdio.h>

int main() {
    int c;
    long blanks = 0;
    long tabs = 0;
    long newlines = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ': blanks++; break;
            case '\t': tabs++; break;
            case '\n': newlines++; break;
            default:;
        }
    }
    printf("blanks: %ld\n", blanks);
    printf("tabs: %ld\n", tabs);
    printf("newlines: %ld\n", newlines);
}
