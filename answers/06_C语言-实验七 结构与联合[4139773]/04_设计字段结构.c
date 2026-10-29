#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bits {
    unsigned bit0 : 1, bit1 : 1, bit2 : 1, bit3 : 1, bit4 : 1, bit5 : 1, bit6 : 1, bit7 : 1;
};
#define FUN(i)                                                                                     \
    void f##i(int b) {                                                                             \
        (void)b;                                                                                   \
        printf("the function " #i " is called!\n");                                                \
    }
FUN(0) FUN(1) FUN(2) FUN(3) FUN(4) FUN(5) FUN(6) FUN(7) int main(void) {
    unsigned x;
    scanf("%u", &x);
    struct bits b = {x & 1,        (x >> 1) & 1, (x >> 2) & 1, (x >> 3) & 1,
                     (x >> 4) & 1, (x >> 5) & 1, (x >> 6) & 1, (x >> 7) & 1};
    int flags[] = {b.bit0, b.bit1, b.bit2, b.bit3, b.bit4, b.bit5, b.bit6, b.bit7};
    void (*p_fun[])(int) = {f0, f1, f2, f3, f4, f5, f6, f7};
    for (int i = 0; i < 8; i++)
        if (flags[i])
            p_fun[i](flags[i]);
    return 0;
}
