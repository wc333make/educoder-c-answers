#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n;
    scanf("%d", &n);
    int *a = calloc(n * n, sizeof(int)), top = 0, bot = n - 1, left = 0, right = n - 1, k = 1;
    while (top <= bot && left <= right) {
        for (int j = left; j <= right; j++)
            a[top * n + j] = k++;
        top++;
        for (int i = top; i <= bot; i++)
            a[i * n + right] = k++;
        right--;
        if (top <= bot) {
            for (int j = right; j >= left; j--)
                a[bot * n + j] = k++;
            bot--;
        }
        if (left <= right) {
            for (int i = bot; i >= top; i--)
                a[i * n + left] = k++;
            left++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%s%d", j ? " " : "", a[i * n + j]);
        putchar('\n');
    }
    free(a);
    return 0;
}
