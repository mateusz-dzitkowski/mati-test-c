#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool contains(const char str[], const char c) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}

char* any(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) {
        if (contains(s2, s1[i])) {
            return &s1[i];
        }
    }
    return NULL;
}

int main() {
    char word[] = "hello, world!";

    char* out = any(word, "rod");
    printf("%s\n", out);

    char* out_std = strpbrk(word, "rod");
    printf("%s\n", out_std);

    char* null = any(word, "g");
    printf("%s\n", null);

    return 0;
}
