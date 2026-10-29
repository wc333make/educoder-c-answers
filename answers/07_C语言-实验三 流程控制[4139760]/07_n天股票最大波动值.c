#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n;
    double prev, x, best = 0;
    scanf("%d", &n);
    if (n > 0)
        scanf("%lf", &prev);
    for (int i = 1; i < n; i++) {
        scanf("%lf", &x);
        if (fabs(x - prev) > best)
            best = fabs(x - prev);
        prev = x;
    }
    printf("%g", best);
    return 0;
}
