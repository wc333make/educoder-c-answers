#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int y, m, d, days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d", &y, &m, &d);
    days[2] += (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
    for (int i = 1; i < m; i++)
        d += days[i];
    printf("%d", d);
    return 0;
}
