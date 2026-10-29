#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int m;
    scanf("%d", &m);
    unsigned char *c = calloc(m + 1, 1);
    for (int i = 2; i <= m / i; i++)
        if (!c[i])
            for (int j = i * i; j <= m; j += i)
                c[j] = 1;
    for (int i = 3; i + 2 < m; i++)
        if (!c[i] && !c[i + 2])
            printf("(%d,%d) ", i, i + 2);
    free(c);
    return 0;
}
