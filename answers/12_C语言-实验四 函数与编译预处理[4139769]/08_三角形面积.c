#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SEMI(a, b, c) (((a) + (b) + (c)) / 2.0)
#define AREA(a, b, c, s) sqrt((s) * ((s) - (a)) * ((s) - (b)) * ((s) - (c)))
int main(void) {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double s = SEMI(a, b, c);
    printf("%.2f", AREA(a, b, c, s));
    return 0;
}
