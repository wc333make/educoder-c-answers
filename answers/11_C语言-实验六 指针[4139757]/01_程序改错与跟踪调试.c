#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strcopy(char *t, const char *s) {
    char *start = t;
    while ((*t++ = *s++))
        ;
    return start;
}
int main(void) {
    char s[10000], t[10000];
    while (fgets(s, sizeof s, stdin)) {
        s[strcspn(s, "\r\n")] = 0;
        puts(strcopy(t, s));
    }
    return 0;
}
