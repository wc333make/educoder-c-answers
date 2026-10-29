#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
    if (argc != 4 || !*argv[2])
        return 1;
    FILE *f = fopen(argv[1], "rb"), *out = fopen("out.txt", "wb");
    if (!f || !out)
        return 1;
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    rewind(f);
    char *s = malloc(n + 1);
    size_t got = fread(s, 1, n, f);
    s[got] = 0;
    fclose(f);
    char *p = s, *match;
    size_t len = strlen(argv[2]);
    while ((match = strstr(p, argv[2]))) {
        fwrite(p, 1, match - p, out);
        fputs(argv[3], out);
        p = match + len;
    }
    fputs(p, out);
    fclose(out);
    free(s);
    return 0;
}
