#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    for (int n = 1; n < 100000; n++) {
        int a = (int)sqrt(n + 100), b = (int)sqrt(n + 268);
        if (a * a == n + 100 && b * b == n + 268)
            printf("%d\n", n);
    }
    return 0;
}
