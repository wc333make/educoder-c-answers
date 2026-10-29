#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void connect(char *output, char *f1, char *f2, char *f3) {
    FILE *out = fopen(output, "wb");
    if (!out)
        exit(1);
    char *names[] = {f1, f2, f3};
    for (int i = 0; i < 3; i++) {
        FILE *in = fopen(names[i], "rb");
        if (!in)
            exit(1);
        int c;
        while ((c = fgetc(in)) != EOF)
            fputc(c, out);
        fclose(in);
    }
    fclose(out);
}
