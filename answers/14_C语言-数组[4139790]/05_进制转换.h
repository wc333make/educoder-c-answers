#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void conversion(char *s) {
    int n = 0;
    for (; *s; s++) {
        int d = *s >= '0' && *s <= '9'   ? *s - '0'
                : *s >= 'a' && *s <= 'f' ? *s - 'a' + 10
                : *s >= 'A' && *s <= 'F' ? *s - 'A' + 10
                                         : -1;
        if (d < 0)
            break;
        n = n * 16 + d;
    }
    printf("%d", n);
}
