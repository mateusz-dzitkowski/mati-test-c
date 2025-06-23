#include <stdio.h>
#define MAX_LINE 1000

int get_line(char line[]);
void copy(const char from[], char to[]);

int main() {
    int len;
    int max;
    char line[MAX_LINE];
    char longest[MAX_LINE];

    max = 0;
    while ((len = get_line(line)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

int get_line(char line[]) {
    int c = 0, i;

    for (i = 0; i < MAX_LINE && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}

void copy(const char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
