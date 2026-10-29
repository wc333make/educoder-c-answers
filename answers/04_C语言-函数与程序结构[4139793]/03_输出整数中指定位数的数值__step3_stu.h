#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int digit(long n, int k) {
    if (k < 1)
        return -1;
    unsigned long u = n < 0 ? 0UL - (unsigned long)n : (unsigned long)n;
    while (--k) {
        u /= 10;
        if (!u)
            return -1;
    }
    return u % 10;
}
