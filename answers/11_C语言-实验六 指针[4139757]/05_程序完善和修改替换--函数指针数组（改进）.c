#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char a[20000], b[10000], line[100];
    char *(*functions[])(char *, const char *) = {strcpy, strcat, strtok};
    while (fgets(line, sizeof line, stdin)) {
        int op = atoi(line);
        if (op == 4)
            break;
        if (op < 1 || op > 3)
            continue;
        fgets(a, 10000, stdin);
        a[strcspn(a, "\r\n")] = 0;
        fgets(b, sizeof b, stdin);
        b[strcspn(b, "\r\n")] = 0;
        char *r = functions[op - 1](a, b);
        puts(r ? r : "");
    }
    return 0;
}
