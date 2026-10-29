#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double sum(double x, int n) {
    static double term, result;
    term = result = 1;
    for (int i = 1; i <= n; i++) {
        term *= x / i;
        result += term;
    }
    return result;
}
int main(void) {
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    printf("The result is %lf", sum(x, n));
    return 0;
}
