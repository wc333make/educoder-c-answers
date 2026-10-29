#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char s[1000];
    scanf("%999s", s);
    if (strlen(s) != 11) {
        printf("长度不合法");
        return 0;
    }
    for (int i = 0; i < 11; i++)
        if (s[i] < '0' || s[i] > '9') {
            printf("字符串中存在非数字字符");
            return 0;
        }
    if (s[0] != '1')
        printf("第1位不合法");
    else if (s[1] < '3' || s[1] > '9')
        printf("第2位不合法");
    else
        printf("合法");
    return 0;
}
