#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char s[10000];
    scanf("%9999s", s);
    int sum = 0;
    for (int i = 0; s[i]; i++)
        sum += s[i] - '0';
    printf("%s是%zu位数，且各位数字之和为%d。", s, strlen(s), sum);
    return 0;
}
