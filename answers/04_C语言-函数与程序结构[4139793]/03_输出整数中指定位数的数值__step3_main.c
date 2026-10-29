#include "step3_stu.h"
#include <stdio.h>

// 请根据此函数补全step3_stu.h文件中digit()函数
int main() {
    long n;
    int k;
    scanf("%ld%d", &n, &k);
    if (n < 0)
        n = -n;
    printf("%d", digit(n, k));
    return 0;
}
