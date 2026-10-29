#include <stdio.h>

enum month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

int main() {
    int year;
    scanf("%d", &year);

    // 判断闰年：能被4整除且不能被100整除，或能被400整除
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // 各月天数
    int days[13] = {0, 31, 28 + leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 各月英文全称
    char *names[13] = {"",    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    for (int m = Jan; m <= Dec; m++) {
        printf("%s: %d\n", names[m], days[m]);
    }

    return 0;
}