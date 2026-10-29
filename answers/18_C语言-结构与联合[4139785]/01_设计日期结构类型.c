#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct date {
    int year, month, day;
};
int main(void) {
    struct date d;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d", &d.year, &d.month, &d.day);
    days[2] += (d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0));
    if (d.year < 1 || d.month < 1 || d.month > 12 || d.day < 1 || d.day > days[d.month]) {
        printf("不存在这样的日期");
        return 0;
    }
    int n = d.day;
    for (int i = 1; i < d.month; i++)
        n += days[i];
    printf("%d", n);
    return 0;
}
