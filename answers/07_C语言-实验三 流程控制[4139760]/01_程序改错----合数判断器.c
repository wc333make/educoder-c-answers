#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int x;
    while (scanf("%d", &x) == 1) {
        int composite = 0;
        for (int i = 2; !composite && i <= x / i; i++)
            if (x % i == 0)
                composite = 1;
        printf("%d%s合数", x, composite ? "是" : "不是");
    }
    return 0;
}
