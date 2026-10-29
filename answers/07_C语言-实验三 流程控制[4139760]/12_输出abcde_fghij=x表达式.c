#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int x;
    scanf("%d", &x);
    for (int b = 1234; b * x <= 98765; b++) {
        int a = b * x, used = 0, ok = 1, u = a, v = b;
        for (int i = 0; i < 5; i++) {
            int d = u % 10;
            if (used & (1 << d))
                ok = 0;
            used |= 1 << d;
            u /= 10;
        }
        for (int i = 0; i < 5; i++) {
            int d = v % 10;
            if (used & (1 << d))
                ok = 0;
            used |= 1 << d;
            v /= 10;
        }
        if (ok && used == 1023)
            printf("%05d/%05d=%d\n", a, b, x);
    }
    return 0;
}
