#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n, p = 1, first = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        p *= 10;
    for (int x = p / 10; x < p; x++)
        if ((long long)x * x % p == x) {
            printf("%s%d", first ? "" : " ", x);
            first = 0;
        }
    return 0;
}
