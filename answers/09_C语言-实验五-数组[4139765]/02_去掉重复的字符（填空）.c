#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void RemoveDuplicate(char *s) {
    int w = 0;
    for (int r = 0; s[r]; r++) {
        int found = 0;
        for (int i = 0; i < w; i++)
            if (s[i] == s[r])
                found = 1;
        if (!found)
            s[w++] = s[r];
    }
    s[w] = 0;
}
int main(void) {
    char s[20000];
    while (fgets(s, sizeof s, stdin)) {
        RemoveDuplicate(s);
        printf("%s", s);
    }
    return 0;
}
