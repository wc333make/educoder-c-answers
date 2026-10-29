#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TASK(i)                                                                                    \
    void task##i(void) { puts("task" #i " is called!"); }
TASK(0) TASK(1) TASK(2) TASK(3) TASK(4) TASK(5) TASK(6) TASK(7) TASK(8) TASK(9) int main(void) {
    void (*tasks[])(void) = {task0, task1, task2, task3, task4, task5, task6, task7, task8, task9};
    int c;
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            tasks[c - '0']();
    return 0;
}
