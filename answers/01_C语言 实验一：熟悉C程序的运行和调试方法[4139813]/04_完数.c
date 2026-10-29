#include <stdio.h>
/*判断x是否是完全数，是则返回1，否则返回0*/
int isPerfect(int x) {
    int tot = 0;
    int i;
    for (i = 1; i * i < x; ++i) {
        if (x % i == 0)
            tot += i + x / i;
    }
    if (i * i == x)
        tot += i;
    return tot - x == x;
}

int main() {
    int a;
    for (a = 1; a <= 1000; a++) /*遍历所有数*/
        if (isPerfect(a))
            printf("%d\n", a);
    return 0;
}
