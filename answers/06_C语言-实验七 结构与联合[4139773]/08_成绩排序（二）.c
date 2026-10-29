#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student {
    char id[50], name[100];
    int scores[4];
    struct Student *next;
} Student;
int total(Student *p) {
    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum += p->scores[i];
    return sum;
}
void sort_data(Student *head) {
    for (Student *p = head; p; p = p->next)
        for (Student *q = p->next; q; q = q->next)
            if (total(p) > total(q)) {
                Student temp = *p;
                Student *pn = p->next, *qn = q->next;
                *p = *q;
                *q = temp;
                p->next = pn;
                q->next = qn;
            }
}
void sort_links(Student **head) {
    Student *sorted = NULL;
    while (*head) {
        Student *p = *head;
        *head = p->next;
        Student **q = &sorted;
        while (*q && total(*q) <= total(p))
            q = &(*q)->next;
        p->next = *q;
        *q = p;
    }
    *head = sorted;
}
int main(void) {
    Student *head = NULL;
    int op;
    while (scanf("%d", &op) == 1 && op) {
        if (op == 1) {
            int n;
            scanf("%d", &n);
            Student **p = &head;
            while (*p)
                p = &(*p)->next;
            for (int i = 0; i < n; i++) {
                *p = calloc(1, sizeof(Student));
                scanf("%49s%99s", (*p)->id, (*p)->name);
                for (int j = 0; j < 4; j++)
                    scanf("%d", &(*p)->scores[j]);
                p = &(*p)->next;
            }
        } else if (op == 3) {
            char id[50];
            int subject, score;
            scanf("%49s%d%d", id, &subject, &score);
            for (Student *p = head; p; p = p->next)
                if (!strcmp(p->id, id) && subject >= 1 && subject <= 4)
                    p->scores[subject - 1] = score;
        } else if (op == 6) {
            FILE *f = fopen("stu.dat", "wb");
            if (!f)
                return 1;
            for (Student *p = head; p; p = p->next) {
                fwrite(p->id, sizeof p->id, 1, f);
                fwrite(p->name, sizeof p->name, 1, f);
                fwrite(p->scores, sizeof p->scores, 1, f);
            }
            fclose(f);
        } else if (op == 7) {
            FILE *f = fopen("stu.dat", "rb");
            if (!f)
                return 1;
            while (head) {
                Student *p = head;
                head = p->next;
                free(p);
            }
            Student **tail = &head;
            Student temp;
            while (fread(temp.id, sizeof temp.id, 1, f) == 1) {
                if (fread(temp.name, sizeof temp.name, 1, f) != 1 ||
                    fread(temp.scores, sizeof temp.scores, 1, f) != 1)
                    return 1;
                *tail = calloc(1, sizeof(Student));
                strcpy((*tail)->id, temp.id);
                strcpy((*tail)->name, temp.name);
                memcpy((*tail)->scores, temp.scores, sizeof temp.scores);
                tail = &(*tail)->next;
            }
            fclose(f);
        } else if (op == 2 || op == 4 || op == 5) {
            sort_links(&head);
            for (Student *p = head; p; p = p->next) {
                int sum = total(p);
                printf("%s %s", p->id, p->name);
                if (op == 2)
                    for (int i = 0; i < 4; i++)
                        printf(" %d", p->scores[i]);
                else {
                    if (op == 5)
                        printf(" %d", sum);
                    printf(" %.2f", sum / 4.0);
                }
                putchar('\n');
            }
        }
    }
    while (head) {
        Student *p = head;
        head = p->next;
        free(p);
    }
    return 0;
}
