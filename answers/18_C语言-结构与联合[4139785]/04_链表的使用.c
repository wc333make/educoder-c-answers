#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char c;
    struct Node *next;
} Node;
Node *create(void) {
    Node head = {0, NULL}, *tail = &head;
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        tail->next = malloc(sizeof(Node));
        tail = tail->next;
        tail->c = c;
        tail->next = NULL;
    }
    return head.next;
}
void show(Node *p, int spaced) {
    for (; p; p = p->next) {
        putchar(p->c);
        if (spaced)
            putchar(' ');
    }
    putchar('\n');
}
void change(Node **head, char c) {
    Node **link = head, *closest = NULL;
    int diff = 1000;
    while (*link) {
        Node *p = *link;
        if (p->c == c) {
            *link = p->next;
            free(p);
            return;
        }
        int d = abs((unsigned char)p->c - (unsigned char)c);
        if (d < diff) {
            diff = d;
            closest = p;
        }
        link = &p->next;
    }
    Node *n = malloc(sizeof(Node));
    n->c = c;
    if (closest) {
        n->next = closest->next;
        closest->next = n;
    } else {
        n->next = *head;
        *head = n;
    }
}
int main(void) {
    Node *h = create();
    show(h, 1);
    int n = 0;
    for (Node *p = h; p; p = p->next)
        n++;
    char *s = malloc(n + 1);
    int i = 0;
    for (Node *p = h; p; p = p->next)
        s[i++] = p->c;
    s[i] = 0;
    puts(s);
    free(s);
    int c = getchar();
    change(&h, c);
    show(h, 0);
    while (h) {
        Node *p = h;
        h = h->next;
        free(p);
    }
    return 0;
}
