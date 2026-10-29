#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void myrever(void) {
    int c = getchar();
    if (c != EOF && c != '\n') {
        myrever();
        putchar(c);
    }
}
