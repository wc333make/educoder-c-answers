#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    long long v;
    struct Node *next;
} Node;
int main(void) {
    Node *h = NULL;
    char token[100];
    while (scanf("%99s", token) == 1) {
        char *end;
        long long v = strtoll(token, &end, 10);
        if (*end == 0) {
            Node *p = malloc(sizeof(Node));
            p->v = v;
            p->next = h;
            h = p;
        } else {
            if (!h || !h->next)
                return 1;
            Node *p = h;
            long long b = p->v;
            h = p->next;
            free(p);
            long long a = h->v;
            switch (token[0]) {
            case '+':
                h->v = a + b;
                break;
            case '-':
                h->v = a - b;
                break;
            case '*':
                h->v = a * b;
                break;
            case '/':
                if (!b)
                    return 1;
                h->v = a / b;
                break;
            default:
                return 1;
            }
        }
    }
    if (h) {
        printf("%lld", h->v);
        free(h);
    }
    return 0;
}
