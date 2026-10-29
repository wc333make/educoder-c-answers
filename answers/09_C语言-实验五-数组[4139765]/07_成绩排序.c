#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student {
    char name[100];
    int score;
} Student;
int compare(const void *a, const void *b) {
    const Student *p = a, *q = b;
    if (p->score != q->score)
        return (q->score > p->score) - (q->score < p->score);
    return strcmp(p->name, q->name);
}
int main(void) {
    Student *a = NULL;
    int n = 0, op;
    while (scanf("%d", &op) == 1 && op) {
        if (op == 1) {
            scanf("%d", &n);
            free(a);
            a = malloc(n * sizeof(*a));
            for (int i = 0; i < n; i++)
                scanf("%99s%d", a[i].name, &a[i].score);
        } else if (op == 2)
            qsort(a, n, sizeof(*a), compare);
        else if (op == 3)
            for (int i = 0; i < n; i++)
                printf("%s %d\n", a[i].name, a[i].score);
        else if (op == 4) {
            int x;
            scanf("%d", &x);
            qsort(a, n, sizeof(*a), compare);
            int low = 0, high = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (a[mid].score > x)
                    low = mid + 1;
                else
                    high = mid;
            }
            if (low == n || a[low].score != x)
                puts("not found");
            else
                for (int i = low; i < n && a[i].score == x; i++)
                    printf("%s %d\n", a[i].name, a[i].score);
        }
    }
    free(a);
    return 0;
}
