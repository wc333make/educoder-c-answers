#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    double x, tax = 0;
    scanf("%lf", &x);
    for (int i = 1; i <= 5; i++) {
        double slice = x - i * 1000;
        if (slice > 0) {
            if (i < 5 && slice > 1000)
                slice = 1000;
            tax += slice * i * 0.05;
        }
    }
    printf("%d", (int)tax);
    return 0;
}
