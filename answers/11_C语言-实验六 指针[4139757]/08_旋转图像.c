#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    int *a = malloc(n * m * sizeof(int));
    for (int i = 0; i < n * m; i++)
        scanf("%d", a + i);
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++)
            printf("%s%d", i ? " " : "", a[i * m + j]);
        putchar('\n');
    }
    free(a);
    return 0;
}
