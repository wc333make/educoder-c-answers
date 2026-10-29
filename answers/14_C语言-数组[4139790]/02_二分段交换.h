#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(int *a, int left, int right) {
    while (left < right) {
        int t = a[left];
        a[left++] = a[right];
        a[right--] = t;
    }
}
void move(int *a, int n, int k) {
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
    reverse(a, 0, n - 1);
}
