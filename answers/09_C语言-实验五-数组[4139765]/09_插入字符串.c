#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strnins(char *t, const char *s, int n) {
    size_t a = strlen(t), b = strlen(s);
    if (n < 0 || (size_t)n > a)
        return;
    memmove(t + n + b, t + n, a - n + 1);
    memcpy(t + n, s, b);
}
int main(void) {
    char t[20000], s[10000];
    int n;
    fgets(t, 10000, stdin);
    t[strcspn(t, "\r\n")] = 0;
    fgets(s, sizeof s, stdin);
    s[strcspn(s, "\r\n")] = 0;
    scanf("%d", &n);
    strnins(t, s, n);
    printf("%s", t);
    return 0;
}
