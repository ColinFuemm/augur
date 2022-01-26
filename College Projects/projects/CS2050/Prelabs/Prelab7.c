#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node *head;
    int listLength;
} ListStuff;

typedef struct {
    ListStuff *p;
} List;

List initList();
int insertAtHead(void* address,List list);
void* getAtIndex(int index, List list);
int getLength(List list);
void clearList(List list);
void freeList(List list);

int main ()
{
    List test = initList();
    int *p = malloc(sizeof(int *));
    int *q = malloc(sizeof(int *));
    *p = 2;
    *q = 3;
    printf("Count: %d\n", getLength(test));

    insertAtHead((void *)p, test);
    insertAtHead((void *)q, test);
    printf("Count: %d\n", getLength(test));
    void *t = malloc(sizeof(void *));
    t = getAtIndex(1, test);
    printf("Test Value: %d\n", ((int*)t));

    clearList(test);
    printf("Count: %d\n", getLength(test));
    t = getAtIndex(0, test);

    freeList(test);
}

/* This function returns an empty List object. */
List initList() {
    List empty;
    empty.p = malloc(sizeof(ListStuff));
    empty.p->head = NULL;
    empty.p->listLength = 0;
    return empty;
}
 
 /* This function inserts the object of the first parameter 
 at the head of the list and returns an error code of -1 on failure. */
int insertAtHead(void* newPtr, List list) {
    Node *temp = list.p->head;
    list.p->head = newPtr;
    list.p->head->next = temp;
    list.p->listLength += 1;
    return 0;
}

 /* This function returns the object at the index location 
 given by the first parameter. */
void* getAtIndex(int index, List list) {
    Node *node = list.p->head;

    for(int i = 1; i < index; i++)
    { node = node->next; }

    return node;
}
  
  /* This function returns the number of objects in the list. */
int getLength(List list) {
    return list.p->listLength;
}
  
  /* This function clears the list (makes it empty) just like
  it was after initList was called.*/
void clearList(List list) {
    for(int i = getLength(list); i > 0; i--)
    {
        Node *temp = getAtIndex(i, list);
        temp->data = 0;
        temp->next = NULL;
    }
    list.p->listLength = 0;
}
  
  /* This function frees all memory allocated for a list and 
  so is not the same as clearList.*/
void freeList(List list) {
    free(list.p);
}