#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverseOrder(int *a, int n) {
    if (n <= 1)
        return;
    for (int *p = a, *q = a + n - 1; p < q; p++, q--) {
        int t = *p;
        *p = *q;
        *q = t;
    }
}
