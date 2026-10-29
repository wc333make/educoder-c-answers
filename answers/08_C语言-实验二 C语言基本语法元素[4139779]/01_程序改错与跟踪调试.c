#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int f;
    double r;
    printf("Input Fahrenheit:\n");
    scanf("%d", &f);
    printf(" %d(F)=%.2f(C)\n\n", f, 5.0 / 9 * (f - 32));
    printf("input the radius r:\n");
    scanf("%lf", &r);
    printf("The acreage is %.2f\n\n", 3.14159 * r * r);
    unsigned short k = 0xa1b2, p = 0x8423;
    unsigned newint = (p & 0xff00) | (k >> 8);
    printf("new int = %#x\n\n", newint);
    return 0;
}
