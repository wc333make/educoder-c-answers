#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n = 0, x;
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &x);
        if (x <= 0)
            continue;
        n++;
        sum += x;
    }
    printf("numbers=%d, average=%f", n, n ? sum / n : 0);
    return 0;
}
