#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int32_t x;
    scanf("%d", &x);
    unsigned char *p = (unsigned char *)&x;
    uint16_t check = 1;
    int little = *(unsigned char *)&check;
    for (int i = 0; i < 4; i++) {
        unsigned v = *(p + (little ? 3 - i : i));
        printf("%s%x %x", i ? " " : "", v >> 4, v & 15);
    }
    return 0;
}
