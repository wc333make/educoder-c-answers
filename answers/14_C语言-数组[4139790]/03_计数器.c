#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int counts[128] = {0}, others = 0, c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (c >= '0' && c <= '9')
            counts[c]++;
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            counts[toupper(c)]++;
        else
            others++;
    }
    for (int i = '0'; i <= '9'; i++)
        if (counts[i])
            printf("%c:%d\n", i, counts[i]);
    for (int i = 'A'; i <= 'Z'; i++)
        if (counts[i])
            printf("%c:%d\n", i, counts[i]);
    printf("others:%d\n", others);
    return 0;
}
