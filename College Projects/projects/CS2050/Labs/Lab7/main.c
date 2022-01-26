#include "lab7.h"

int main() {
    List *list = initList();
    printf("Size: %d\n", getSize(list));

    Node *p = malloc(sizeof(Node));
    Node *q = malloc(sizeof(Node));
    int x = 3;
    int y = 5;
    p->data = &x;
    q->data = &y;

    insertBefore(list, p, NULL);
    insertBefore(list, q, p);
    insertBefore(list, p, q);
    printf("Size: %d\n", getSize(list));
    printf("%d\n", hasDuplicates(list, p));
    removeAfter(list, q);
    printf("Size: %d\n", getSize(list));

    Node *t = malloc(sizeof(Node));
    t = getAtIndex(list, 2);
    printf("%d", (t->data));

    freeList(list);
    return 0;
}