#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    int *a = malloc(n * m * sizeof(int));
    unsigned char *mark = calloc(n * m, 1);
    for (int i = 0; i < n * m; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m;) {
            int k = j + 1;
            while (k < m && a[i * m + k] == a[i * m + j])
                k++;
            if (k - j >= 3)
                for (int p = j; p < k; p++)
                    mark[i * m + p] = 1;
            j = k;
        }
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n;) {
            int k = i + 1;
            while (k < n && a[k * m + j] == a[i * m + j])
                k++;
            if (k - i >= 3)
                for (int p = i; p < k; p++)
                    mark[p * m + j] = 1;
            i = k;
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%s%d", j ? " " : "", mark[i * m + j] ? 0 : a[i * m + j]);
        putchar('\n');
    }
    free(a);
    free(mark);
    return 0;
}
