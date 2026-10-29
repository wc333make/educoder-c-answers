#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int k = 0; k < 2 * (n - i); k++)
            putchar(' ');
        int c = 1;
        for (int j = 0; j <= i; j++) {
            printf("%-4d", c);
            c = c * (i - j) / (j + 1);
        }
        putchar('\n');
    }
    return 0;
}
