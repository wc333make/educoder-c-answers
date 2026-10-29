#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    double a, b, r;
    char op;
    scanf("%lf%lf %c", &a, &b, &op);
    switch (op) {
    case '+':
        r = a + b;
        break;
    case '-':
        r = a - b;
        break;
    case '*':
        r = a * b;
        break;
    case '/':
        r = a / b;
        break;
    default:
        return 1;
    }
    printf("%.1f", r);
    return 0;
}
