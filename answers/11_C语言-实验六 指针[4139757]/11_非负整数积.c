#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char a[201], b[201];
    int c[402] = {0};
    scanf("%200s%200s", a, b);
    int n = strlen(a), m = strlen(b);
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            c[n - 1 - i + m - 1 - j] += (a[i] - '0') * (b[j] - '0');
    for (int i = 0; i < 400; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    int k = 401;
    while (k > 0 && !c[k])
        k--;
    for (; k >= 0; k--)
        printf("%d", c[k]);
    return 0;
}
