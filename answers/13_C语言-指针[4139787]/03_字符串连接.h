#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char *p;
int main0(int argc, char *argv[]) {
    size_t n = 1;
    for (int i = 1; i < argc; i++)
        n += strlen(argv[i]);
    p = malloc(n);
    if (!p)
        return 1;
    *p = 0;
    for (int i = 1; i < argc; i++)
        strcat(p, argv[i]);
    return 0;
}
