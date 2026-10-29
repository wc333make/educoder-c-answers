#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strncate(char *t, const char *s) {
    while (*t)
        t++;
    while ((*t++ = *s++))
        ;
}
void strdelc(char *s, char c) {
    char *w = s;
    for (; *s; s++)
        if (*s != c)
            *w++ = *s;
    *w = 0;
}
int main(void) {
    char a[20000], b[10000], c;
    scanf("%9999s%9999s %c", a, b, &c);
    strncate(a, b);
    puts(a);
    strdelc(a, c);
    printf("%s", a);
    return 0;
}
