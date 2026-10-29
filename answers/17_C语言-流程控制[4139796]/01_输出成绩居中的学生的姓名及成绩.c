#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int a[3], s[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
        s[i] = a[i];
    }
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++)
            if (s[i] > s[j]) {
                int t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
    for (int i = 0; i < 3; i++)
        if (a[i] == s[1]) {
            printf("%c %d", 'A' + i, a[i]);
            break;
        }
    return 0;
}
