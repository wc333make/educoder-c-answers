#include <stdio.h>
int main(void) {
    int c;
    unsigned long long chars = 0, lines = 0;
    while ((c = getchar()) != EOF) {
        chars++;
        if (c == '\n')
            lines++;
    }
    printf("字符数:%llu,行数:%llu", chars, lines);
    return 0;
}
