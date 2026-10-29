#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int asc(const void *p, const void *q) {
    int a = *(const int *)p, b = *(const int *)q;
    return (a > b) - (a < b);
}
int main(int argc, char **argv) {
    char line[1000], cmd[100], opt[100] = "";
    int n;
    if (argc >= 2) {
        n = atoi(argv[1]);
        if (argc >= 3)
            strcpy(opt, argv[2]);
    } else {
        fgets(line, sizeof line, stdin);
        sscanf(line, "%99s%d%99s", cmd, &n, opt);
    }
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    qsort(a, n, sizeof(int), asc);
    int desc = !strcmp(opt, "-d");
    for (int i = 0; i < n; i++)
        printf("%s%d", i ? " " : "", a[desc ? n - i - 1 : i]);
    free(a);
    return 0;
}
