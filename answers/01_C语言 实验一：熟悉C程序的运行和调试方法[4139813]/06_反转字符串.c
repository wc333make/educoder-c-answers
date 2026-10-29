#include <stdio.h>
void strReverse(char s[]);
int strLength(char s[]);
int main() {
    char s[1000];
    scanf("%s", s);
    printf("串%s的长度为:%d\n", s, strLength(s));
    strReverse(s);
    printf("反转后:%s", s);
    return 0;
}

int strLength(char s[]) {
    int i = 0;
    while (s[i])
        i++;
    return i;
}

void strReverse(char s[]) /* 反转串s */
{
    int i, j;
    for (i = 0, j = strLength(s) - 1; i < j; i++, j--) /* 从两头遍历s */
    {
        char t;
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}