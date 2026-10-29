#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static FILE *open_matrix(const char *filename) {
    FILE *in = NULL;
    if (filename) {
        in = fopen(filename, "r");
        if (!in) {
            char path[8192];
            int length = snprintf(path, sizeof path, "src/step6/%s", filename);
            if (length >= 0 && (size_t)length < sizeof path)
                in = fopen(path, "r");
        }
    }
    /* The statement also permits a preinstalled matrix.in in the working directory. */
    return in ? in : fopen("matrix.in", "r");
}

int main(int argc, char *argv[]) {
    char filename[4096];
    const char *input = argc > 1 ? argv[1] : NULL;
    if (!input && scanf("%4095s", filename) == 1)
        input = filename;
    FILE *in = open_matrix(input);
    if (!in)
        return 1;
    int n, m;
    if (fscanf(in, "%d%d", &n, &m) != 2 || n <= 0 || m <= 0 ||
        (size_t)n > SIZE_MAX / (size_t)m / sizeof(int)) {
        fclose(in);
        return 1;
    }
    size_t count = (size_t)n * (size_t)m;
    int *a = malloc(count * sizeof *a);
    if (!a) {
        fclose(in);
        return 1;
    }
    for (size_t i = 0; i < count; i++) {
        if (fscanf(in, "%d", a + i) != 1) {
            free(a);
            fclose(in);
            return 1;
        }
    }
    fclose(in);
    FILE *out = fopen("matrix.out", "w");
    if (!out) {
        free(a);
        return 1;
    }
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++)
            fprintf(out, "%s%d", i ? " " : "", a[(size_t)i * (size_t)m + (size_t)j]);
        fputc('\n', out);
    }
    free(a);
    return fclose(out) == 0 ? 0 : 1;
}
