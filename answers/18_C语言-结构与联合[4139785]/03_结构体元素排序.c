#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct web {
    char key[100], name[200], url[500];
};
void sort(struct web *a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(a[i].key, a[j].key) > 0) {
                struct web t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}
int main(void) {
    struct web a[4];
    char key[100];
    for (int i = 0; i < 4; i++)
        scanf("%99s%199s%499s", a[i].key, a[i].name, a[i].url);
    scanf("%99s", key);
    sort(a, 4);
    for (int i = 0; i < 4; i++)
        printf("%s %s %s\n", a[i].key, a[i].name, a[i].url);
    for (int i = 0; i < 4; i++)
        if (!strcmp(key, a[i].key)) {
            printf("%s", a[i].url);
            return 0;
        }
    printf("未找到搜寻的网址");
    return 0;
}
