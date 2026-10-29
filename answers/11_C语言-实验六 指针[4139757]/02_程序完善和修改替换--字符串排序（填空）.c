#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strsort(char **s, int size) {
    for (char **p = s; p < s + size; p++)
        for (char **q = p + 1; q < s + size; q++)
            if (strcmp(*p, *q) > 0) {
                char *t = *p;
                *p = *q;
                *q = t;
            }
}
int main(void) {
    int n;
    scanf("%d", &n);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    char **s = malloc(n * sizeof(*s)), line[10000];
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof line, stdin);
        line[strcspn(line, "\r\n")] = 0;
        s[i] = malloc(strlen(line) + 1);
        strcpy(s[i], line);
    }
    strsort(s, n);
    for (int i = 0; i < n; i++) {
        puts(s[i]);
        free(s[i]);
    }
    free(s);
    return 0;
}
