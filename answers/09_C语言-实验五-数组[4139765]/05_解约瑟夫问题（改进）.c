#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int m, n;
    scanf("%d%d", &m, &n);
    unsigned char *out = calloc(m, 1);
    int remain = m, p = 0, count = 0;
    while (remain > 1) {
        if (!out[p] && ++count == n) {
            out[p] = 1;
            remain--;
            count = 0;
        }
        p = (p + 1) % m;
    }
    for (int i = 0; i < m; i++)
        if (!out[i])
            printf("%d", i + 1);
    free(out);
    return 0;
}
