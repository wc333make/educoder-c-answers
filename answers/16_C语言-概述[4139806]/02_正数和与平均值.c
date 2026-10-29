#include <stdio.h>
int main() {
    /**********  Begin  **********/
    int sum = 0, n = 0;
    for (int i = 1; i <= 10; ++i) {
        int a;
        scanf("%d", &a);
        if (a > 0)
            sum += a, n++;
    }

    printf("累加和:%d\n", sum);
    printf("平均值:%.1f\n", sum / (double)(n ? n : 1));

    /**********  End  **********/
    return 0;
}