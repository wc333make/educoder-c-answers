#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int c, words = 0, chars = 0, lines = 0, inword = 0, last = '\n';
    while ((c = getchar()) != EOF) {
        last = c;
        if (c == '\n')
            lines++;
        if ((c & 0xc0) == 0x80)
            continue;
        if ((unsigned char)c >= 0xc0) {
            words++;
            chars++;
            inword = 0;
        } else if (isspace((unsigned char)c)) {
            inword = 0;
        } else {
            chars++;
            if (!inword)
                words++;
            inword = 1;
        }
    }
    if (last != '\n')
        lines++;
    printf("字数 %d\n字符数 %d\n行数 %d", words, chars, lines);
    return 0;
}
