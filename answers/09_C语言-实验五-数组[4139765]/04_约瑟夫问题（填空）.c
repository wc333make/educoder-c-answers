#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int m, n;
    scanf("%d%d", &m, &n);
    int *a = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        a[i] = i + 1;
    int p = 0;
    for (int k = m; k > 1; k--) {
        p = (p + n - 1) % k;
        printf("%6d", a[p]);
        memmove(a + p, a + p + 1, (k - p - 1) * sizeof(int));
    }
    printf("\n%6d", a[0]);
    free(a);
    return 0;
}
