#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    unsigned k;
    scanf("%u", &k);
    printf("%u", ((k & 15) << 12) | (k & 0x0ff0) | ((k >> 12) & 15));
    return 0;
}
