#include "step4_stu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 请根据此主函数流程补全step4_stu.h文件中mystrlen()函数

int main() {
    char s[100];
    int strlenth = 0;
    scanf("%s", &s);
    strlenth = mystrlen(s);
    printf("%d", strlenth);
    return 0;
}