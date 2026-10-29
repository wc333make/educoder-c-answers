#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long sum_fac(int n) {
    long long f = 1, s = 0;
    for (int i = 1; i <= n; i++) {
        f *= i;
        s += f;
    }
    return s;
}
int main(void) {
    for (int k = 1; k <= 20; k++)
        printf("k=%d the sum is %lld\n", k, sum_fac(k));
    return 0;
}
