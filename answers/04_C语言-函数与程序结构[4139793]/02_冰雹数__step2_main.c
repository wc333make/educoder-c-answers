#include "step2_stu.h"
#include <stdio.h>

// 请根据此函数补全文件step2_stu.h中冰雹产生函数
int main() {
    int number;

    printf("input a number:");
    scanf("%d", &number);

    hailstone(number);

    return 0;
}