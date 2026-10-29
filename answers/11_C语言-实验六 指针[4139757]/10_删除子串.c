#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int deleteSubstr(char *s, const char *sub) {
    size_t n = strlen(sub);
    if (!n)
        return 0;
    int found = 0;
    char *p = s;
    while ((p = strstr(p, sub))) {
        memmove(p, p + n, strlen(p + n) + 1);
        found = 1;
    }
    return found;
}
int main(void) {
    char s[20000], sub[10000];
    fgets(s, sizeof s, stdin);
    fgets(sub, sizeof sub, stdin);
    s[strcspn(s, "\r\n")] = 0;
    sub[strcspn(sub, "\r\n")] = 0;
    int found = deleteSubstr(s, sub);
    printf("%s\n%d", s, found);
    return 0;
}
