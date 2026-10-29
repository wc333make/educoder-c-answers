#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    double a, b, r;
    char op;
    scanf("%lf%lf %c", &a, &b, &op);
    if (op == '+')
        r = a + b;
    else if (op == '-')
        r = a - b;
    else if (op == '*')
        r = a * b;
    else if (op == '/')
        r = a / b;
    else
        return 1;
    printf("%.1f", r);
    return 0;
}
