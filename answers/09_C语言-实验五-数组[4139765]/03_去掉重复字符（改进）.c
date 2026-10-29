#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void RemoveDuplicate(char *s) {
    unsigned char seen[256] = {0};
    char *w = s;
    for (; *s; s++)
        if (!seen[(unsigned char)*s]) {
            seen[(unsigned char)*s] = 1;
            *w++ = *s;
        }
    *w = 0;
}
int main(void) {
    char s[20000];
    while (fgets(s, sizeof s, stdin)) {
        RemoveDuplicate(s);
        printf("%s", s);
    }
    return 0;
}
