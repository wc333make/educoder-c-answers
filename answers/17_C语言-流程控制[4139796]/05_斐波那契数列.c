#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n;
    scanf("%d", &n);
    unsigned long long a = 0, b = 1;
    for (int i = 1; i <= n; i++) {
        printf("%10llu", b);
        unsigned long long c = a + b;
        a = b;
        b = c;
        if (i % 8 == 0)
            putchar('\n');
    }
    return 0;
}
