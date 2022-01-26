#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *name;
    int hp;
    int str;

    struct Node* next;
} Ally;

void printNames(struct Node* n);
void printHealth(struct Node* n);
void printStrength(struct Node* n);

int main()
{
    Ally* partyLeader = NULL;
    Ally* second = NULL;
    Ally* third = NULL;

    partyLeader = (Ally*)malloc(sizeof(Ally));
    second = (Ally*)malloc(sizeof(Ally));
    third = (Ally*)malloc(sizeof(Ally));

    partyLeader->name = "Colin";
    partyLeader->hp = 298;
    partyLeader->str = 23;
    partyLeader->next = second;

    second->name = "Cole";
    second->hp = 420;
    second->str = 15;
    second->next = third;

    third->name = "Jackson";
    third->hp = 369;
    third->str = 30;
    third->next = NULL;

    printNames(partyLeader);
    printHealth(second);
    printStrength(third);

    return 0;
}

void printNames(struct Node* n)
{
    while (n != NULL) {
        printf(" %s ", n->name);
        n = n->next;
    }
}

void printHealth(struct Node* n)
{
    printf(" %d ", n->hp);
}

void printStrength(struct Node* n)
{
    printf(" %d ", n->str);
}