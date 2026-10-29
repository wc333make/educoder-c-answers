#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int x;
    struct Node *next;
} Node;
void create_list(Node **h) {
    int x;
    while (scanf("%d", &x) == 1 && x) {
        Node *p = malloc(sizeof(Node));
        p->x = x;
        p->next = *h;
        *h = p;
    }
}
int main(void) {
    Node *h = NULL;
    create_list(&h);
    while (h) {
        printf("%d\t", h->x);
        Node *p = h;
        h = h->next;
        free(p);
    }
    return 0;
}
