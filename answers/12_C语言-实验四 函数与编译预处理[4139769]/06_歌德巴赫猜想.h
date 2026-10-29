#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prime(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void goldbach(int n) {
    for (int p = 2; p <= n / 2; p++)
        if (prime(p) && prime(n - p)) {
            printf("%d=%d+%d", n, p, n - p);
            return;
        }
}
