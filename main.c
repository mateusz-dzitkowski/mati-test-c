#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* inet_ntoa(const unsigned int ip) {
    const unsigned char octet_1 = ip >> 24 & 255;
    const unsigned char octet_2 = ip >> 16 & 255;
    const unsigned char octet_3 = ip >> 8 & 255;
    const unsigned char octet_4 = ip & 255;

    char *ret = malloc(15*sizeof(char));
    if (ret == NULL) {
        return NULL;
    }

    sprintf(ret, "%d.%d.%d.%d",  octet_1, octet_2, octet_3, octet_4);
    return ret;
}

unsigned int inet_aton(const char *ip) {
    if (ip == NULL) {
        return 0;
    }

    char *ip_copy = malloc(15*sizeof(char));
    for (int i = 0; i < 15 && ip[i] != '\0'; i++) {
        ip_copy[i] = ip[i];
    }

    unsigned int ret = 0;
    for (int i = 3; i >= 0; i--) {
        const char *octet = strsep(&ip_copy, ".");
        char *err = 0;
        if (!octet) {
            return 0;
        }
        const long n = strtol(octet, &err, 10);
        if (*err != '\0') {
            return 0;
        }
        ret += pow(256, i) * n;
    }

    free(ip_copy);
    return ret;
}

int main() {
    const unsigned int ip_number = 123456789;
    char *ip_string = inet_ntoa(ip_number);
    printf("%s\n", ip_string);

    const unsigned int ip_number_back = inet_aton(ip_string);
    printf("%d\n", ip_number_back);

    free(ip_string);
    return 0;
}
