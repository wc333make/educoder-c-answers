#include <stdio.h>
#include <stdlib.h>
/* C_NODE is defined by the platform before including this file. */
void createLinkList(C_NODE **headp, char s[]) {
    *headp = NULL;
    C_NODE **tail = headp;
    while (*s) {
        *tail = malloc(sizeof **tail);
        if (!*tail)
            exit(EXIT_FAILURE);
        (*tail)->data = *s++;
        (*tail)->next = NULL;
        tail = &(*tail)->next;
    }
}
static C_NODE *reverseHalf(C_NODE *head) {
    C_NODE *previous = NULL;
    while (head) {
        C_NODE *next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;
}
void judgePalindrome(C_NODE *head) {
    if (!head) {
        printf("true");
        return;
    }
    C_NODE *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    C_NODE *second = reverseHalf(slow->next);
    int palindrome = 1;
    for (C_NODE *a = head, *b = second; b; a = a->next, b = b->next) {
        if (a->data != b->data)
            palindrome = 0;
    }
    slow->next = reverseHalf(second);
    printf("%s", palindrome ? "true" : "false");
}
