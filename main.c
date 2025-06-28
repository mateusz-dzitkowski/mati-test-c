#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void escape(char* s, const char* t) {
    int i = 0;
    int j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\t':
                s[j] = '\\';
                j++;
                s[j] = 't';
                break;
            case '\n':
                s[j] = '\\';
                j++;
                s[j] = 'n';
                break;
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
}

void unescape(char* s, const char* t) {
    int i = 0;
    int j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\\':
                i++;
                switch (t[i]) {
                    case 't':
                        s[j] = '\t';
                        break;
                    case 'n':
                        s[j] = '\n';
                        break;
                    default:
                        s[j] = '\\';
                        j++;
                        s[j] = t[i];
                        break;
                }
                break;
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
}

int main() {
    char *str = "Hello\tworld!\n";
    char *str_escaped = malloc(2 * strlen(str) + 1);
    char *str_unescaped = malloc(strlen(str) + 1);
    if (str_escaped == NULL) {
        return 1;
    }
    if (str_unescaped == NULL) {
        return 1;
    }

    escape(str_escaped, str);
    unescape(str_unescaped, str_escaped);
    printf("%s\n", str);
    printf("%s\n", str_escaped);
    printf("%s\n", str_unescaped);

    free(str_escaped);
    free(str_unescaped);
    return 0;
}
