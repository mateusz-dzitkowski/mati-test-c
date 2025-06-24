#include <stdio.h>

/*
 * This is a multiline comment
 * // mati
 */

enum state {normal, in_string, in_char, in_multiline, exiting_multiline, in_single_line};

/*
 * This is a multiline comment
 * // mati
 */// this is a oneline comment right after the multiline comment

char test[] = "this is a character string with comment tokens /* hello */ world // test";

// this is a oneline comment */ test

int main()
{
    enum state state = normal;

    int cur = getchar();
    if (cur == '"')
        state = in_string;
    if (cur == '\'')
        state = in_char;
    putchar(cur);

    int prev = cur;
    while ((cur = getchar()) != EOF) {
        // fprintf(stderr, "state=%d, prev=%c, cur=%c\n", state, prev, cur);
        switch (state) {
            case in_string:
                if (prev != '\\' && cur == '"') {
                    state = normal;
                }
                putchar(cur);
                break;
            case in_char:
                if (prev != '\\' && cur == '\'') {
                    state = normal;
                }
                putchar(cur);
                break;
            case in_multiline:
                if (prev == '*' && cur == '/') {
                    state = exiting_multiline;
                }
                break;
            case exiting_multiline:
                if (cur != '/') {
                    putchar(cur);
                }
                state = normal;
                break;
            case in_single_line:
                if (cur == '\n') {
                    state = normal;
                    putchar(cur);
                }
                break;
            case normal:
                if (cur == '"') {
                    state = in_string;
                    putchar(cur);
                } else if (cur == '\'') {
                    state = in_char;
                    putchar(cur);
                } else if (prev == '/' && cur == '/') {
                    state = in_single_line;
                } else if (prev == '/' && cur == '*') {
                    state = in_multiline;
                } else if (prev == '/') {
                    putchar(prev);
                    putchar(cur);
                } else if (cur != '/') {
                    putchar(cur);
                }
                break;
        }
        prev = cur;
    }

    return 0;
}
