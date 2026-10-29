#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long fac(int n) { return n <= 1 ? 1 : n * fac(n - 1); }
long long sum_fac(int n) { return n <= 0 ? 0 : sum_fac(n - 1) + fac(n); }
int main(void) {
    for (int k = 1; k <= 20; k++)
        printf("k=%d the sum is %lld\n", k, sum_fac(k));
    return 0;
}
