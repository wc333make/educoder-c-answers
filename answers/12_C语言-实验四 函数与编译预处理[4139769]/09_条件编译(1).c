#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHANGE 1
int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
#if CHANGE
        if (c >= 'a' && c <= 'z')
            c = c - 'a' + 'A';
        else if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
#endif
        putchar(c);
    }
    return 0;
}
