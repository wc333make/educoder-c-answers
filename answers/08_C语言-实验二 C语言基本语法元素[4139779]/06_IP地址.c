#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    unsigned long long n;
    while (scanf("%llu", &n) == 1)
        printf("%llu.%llu.%llu.%llu\n", (n >> 24) & 255, (n >> 16) & 255, (n >> 8) & 255, n & 255);
    return 0;
}
