#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strnCpy(char *t, char *s, int n) {
    int i = 0;
    for (; i < n && s[i]; i++)
        t[i] = s[i];
    t[i] = 0;
}
