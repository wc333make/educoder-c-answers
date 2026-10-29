#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPalindrome(char *s, int n) {
    return n <= 1 || (*s == s[n - 1] && isPalindrome(s + 1, n - 2));
}
int main(void) {
    char s[1000];
    fgets(s, sizeof s, stdin);
    s[strcspn(s, "\r\n")] = 0;
    printf(isPalindrome(s, strlen(s)) ? "Yes" : "No");
    return 0;
}
