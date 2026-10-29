#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n, a, b, c, count = 0;
    scanf("%d", &n);
    if (n > 0)
        scanf("%d", &a);
    if (n > 1)
        scanf("%d", &b);
    for (int i = 2; i < n; i++) {
        scanf("%d", &c);
        if ((b > a && b > c) || (b < a && b < c))
            count++;
        a = b;
        b = c;
    }
    printf("%d", count);
    return 0;
}
