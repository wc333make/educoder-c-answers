#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int c, last = -1;
    while ((c = getchar()) != EOF) {
        if (c != ' ' || last != ' ')
            putchar(c);
        last = c;
    }
    return 0;
}
