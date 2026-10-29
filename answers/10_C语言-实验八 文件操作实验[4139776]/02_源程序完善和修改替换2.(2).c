#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
    if (argc < 2)
        return 1;
    int paged = argc > 2 && !strcmp(argv[2], "/p");
    FILE *f = fopen(argv[1], "r");
    if (!f)
        return 1;
    char line[10000];
    int n = 0;
    while (fgets(line, sizeof line, f)) {
        if (paged && n && n % 5 == 0) {
            int c;
            do {
                c = getchar();
            } while (c != EOF && (c == '\n' || c == '\r'));
            if (c == EOF)
                break;
        }
        printf("%d ", n + 1);
        printf("%s", line);
        n++;
    }
    fclose(f);
    return 0;
}
