#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int32_t n;
    scanf("%d", &n);
    char s[40];
    int k = 0;
    for (int i = 31; i >= 0; i--) {
        s[k++] = ((uint32_t)n >> i & 1) + '0';
        if (i && i % 4 == 0)
            s[k++] = ' ';
    }
    s[k] = 0;
    printf("%s", s);
    return 0;
}
