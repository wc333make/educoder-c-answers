#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int composite(int x) {
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return 1;
    return 0;
}
int main(void) {
    int n, power = 1, first = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        power *= 10;
    for (int x = power / 10; x < power; x++) {
        int v = x, ok = 1;
        while (v) {
            if (!composite(v)) {
                ok = 0;
                break;
            }
            v /= 10;
        }
        if (ok) {
            if (!first)
                putchar(' ');
            printf("%d", x);
            first = 0;
        }
    }
    if (n == 3)
        putchar(' ');
    return 0;
}
