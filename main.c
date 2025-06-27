#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 1000000000

long binsearch_slow(const long x, const long v[], const long n) {
    long low = 0;
    long high = n - 1;
    long mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

long binsearch_fast(const long x, const long v[], const long n) {
    long low = 0;
    long high = n - 1;
    long mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (x == v[low - 1]) {
        return low - 1;
    }

    return -1;
}

int main() {
    long* v = malloc(N * sizeof(long));
    for (long i = 0; i < N; i++) {
        v[i] = i;
    }

    const clock_t start_fast = clock();
    const long fast = binsearch_fast(1, v, N);
    const clock_t end_fast = clock();

    const clock_t start_slow = clock();
    const long slow = binsearch_slow(1, v, N);
    const clock_t end_slow = clock();

    printf("slow=%ld, fast=%ld\n", slow, fast);
    printf("slow: %f\n", (float)(end_slow - start_slow));
    printf("fast: %f\n", (float)(end_fast - start_fast));

    free(v);
}
