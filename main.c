#include <stdio.h>
#include <stdbool.h>

bool contains(const char str[], const char c) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}

void squeeze(char s[], const char c[]) {
    int j;
    for (int i = j = 0; s[i] != 0; i++) {
        if (!contains(c, s[i])) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}

int main() {
    char word[] = "hello, world!";
    const char blacklist[] = "hl";

    squeeze(word, blacklist);

    printf("%s", word);

    return 0;
}
