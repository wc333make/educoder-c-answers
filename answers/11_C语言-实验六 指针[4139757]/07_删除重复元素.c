#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int RemoveSame(int *a, int n) {
    int k = 0;
    for (int i = 0; i < n; i++)
        if (!k || a[i] != a[k - 1])
            a[k++] = a[i];
    return k;
}
int main(void) {
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(*a));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int k = RemoveSame(a, n);
    for (int i = 0; i < k; i++)
        printf("%s%d", i ? " " : "", a[i]);
    printf("\n%d", k);
    free(a);
    return 0;
}
