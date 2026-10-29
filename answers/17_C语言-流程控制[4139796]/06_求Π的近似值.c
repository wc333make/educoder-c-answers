#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    double e, s = 0, term;
    scanf("%lf", &e);
    int sign = 1;
    unsigned long long k = 0;
    do {
        term = 1.0 / (2 * k + 1);
        s += sign * term;
        sign = -sign;
        k++;
    } while (term >= e);
    printf("%.6f", 4 * s);
    return 0;
}
