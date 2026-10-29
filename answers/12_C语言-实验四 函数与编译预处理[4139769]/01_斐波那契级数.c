#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long sum_fib(int n, long long a, long long b) {
    return n <= 0 ? 0 : b + sum_fib(n - 1, b, a + b);
}
int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld", sum_fib(n, 0, 1));
    return 0;
}
