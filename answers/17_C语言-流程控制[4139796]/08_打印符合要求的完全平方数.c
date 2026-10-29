#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n;
    scanf("%d", &n);
    for (int a = 1; a * a <= n; a++)
        for (int b = 1; 10 * b * b < a * a; b++) {
            int cc = a * a - 10 * b * b, c = (int)sqrt(cc);
            if (c * c == cc) {
                printf("%d=%d*%d=%d*%d*10+%d*%d\n", a * a, a, a, b, b, c, c);
                break;
            }
        }
    return 0;
}
