#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void isPerfect(int n) {
    int a[10000], k = 0;
    long long sum = 0;
    for (int i = 1; i <= n / i; i++)
        if (n % i == 0) {
            if (i < n) {
                a[k++] = i;
                sum += i;
            }
            int j = n / i;
            if (j != i && j < n) {
                a[k++] = j;
                sum += j;
            }
        }
    if (sum != n) {
        printf("%d is not a perfect number", n);
        return;
    }
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++)
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    printf("%d=", n);
    for (int i = 0; i < k; i++)
        printf("%s%d", i ? "+" : "", a[i]);
}
