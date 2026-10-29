#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prime(unsigned long long n) {
    if (n < 2)
        return 0;
    for (unsigned long long i = 2; i <= n / i; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main(void) {
    unsigned long long m;
    scanf("%llu", &m);
    for (unsigned p = 2; p < 64; p++) {
        unsigned long long x = (1ULL << p) - 1;
        if (x > m)
            break;
        if (prime(p) && prime(x))
            printf("M(%u)=%llu\n", p, x);
    }
    return 0;
}
