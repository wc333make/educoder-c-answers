#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    double r;
    scanf("%lf", &r);
    assert(r >= 0);
    printf("The integer fraction of area is %.0f", 3.141592653589793 * r * r);
    return 0;
}
