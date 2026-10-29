#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    long long a, b, x, y;
    scanf("%lld%lld", &a, &b);
    x = a;
    y = b;
    while (y) {
        long long t = x % y;
        x = y;
        y = t;
    }
    printf("%lld %lld", x, a / x * b);
    return 0;
}
