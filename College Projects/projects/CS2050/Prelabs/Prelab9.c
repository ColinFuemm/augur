#include <stdio.h>
#include <stdlib.h>

// partial typedef, so the Node type can contain itself
typedef struct Node Node;

struct Node {
	Node *next;
    Node *prev;
	void *data;
};

typedef struct {
	Node *head;
    Node *tail;
	int size;
} List;

typedef struct {
	unsigned long accountNumber;
	float accountWorth;
	int daysActive;
} Client;

int getSize(List *list) {
    return list->size;
}

/* This function initializes and returns a linked list 
and sets errorcheck to -1 upon failure. */
List* initList(int *errorcheck) {

    List *list = malloc(sizeof(List));

    if(list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    else { *errorcheck = -1; }

    return list;
}

void clearList(List *list) {

    Node *cursor = list->head;

    while(cursor) {
        Node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void freeList(List *list) {
    clearList(list);
    free(list);
}

Node* makeNode(void *data, Node *next, Node *prev) {
    Node *node = malloc(sizeof(Node));
    if(node) {
        *node = (Node){ next, prev, data };
    }
return node;
}

int insertHead(void *object, List *list) {
    if(getSize(list) == 0) {
        Node *new = makeNode(object, NULL, NULL);
        if(!new) { return 1; }
        list->head = new;
        list->tail = new;
        ++list->size;
        return 0;
    }
    
    Node *new = makeNode(object, list->head, NULL);
        if(!new) { return 1; }
    //new->next = list->head;
    list->head->prev = new;
    list->head = new;
    //new->prev = NULL;
    ++list->size;
    return 0;
}

void* removeHead(List *list) {
    if(getSize(list) == 1) {
        Node *old = list->head;
        list->head = NULL;
        list->tail = NULL;
        --list->size;
        return old;
    }
    
    Node *old = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    --list->size;
    return old;
}

int insertTail(void *object, List *list) {
    if(getSize(list) == 0) {
        Node *new = makeNode(object, NULL, NULL);
        if(!new) { return 1; }
        list->head = new;
        list->tail = new;
        ++list->size;
        return 0;
    }
    
    Node *new = makeNode(object, NULL, list->tail);
        if(!new) { return 1; }
    list->tail->next = new;
    list->tail = new;
    ++list->size;
    return 0;
}

void* removeTail(List *list) {
    if(getSize(list) == 1) {
        Node *old = list->head;
        list->head = NULL;
        list->tail = NULL;
        --list->size;
        return old;
    }
    
    Node *old = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    --list->size;
    return old;
}

void printClients(List *list) {
    Node *cursor = list->head;
    while(cursor) {
        Client *ptr = cursor->data;
        printf("Acct Number: %lu, Acct Worth: %f, Days Active: %d\n", ptr->accountNumber, ptr->accountWorth, ptr->daysActive);
        cursor = cursor->next;
    }
}

int main() {

    Client *Rick = malloc(sizeof(Client));
    Client *Judy = malloc(sizeof(Client));
    Client *Harold = malloc(sizeof(Client));
    
    Rick->accountNumber = 5;
    Rick->accountWorth = 32.7;
    Rick->daysActive = 365;
    
    Judy->accountNumber = 2;
    Judy->accountWorth = 420.6;
    Judy->daysActive = 7;

    Harold->accountNumber = 9;
    Harold->accountWorth = 1.0;
    Harold->daysActive = 31;
    
    int *check = 0;
    
    List *list = initList(check);
    
    insertHead(Rick, list);
    insertHead(Harold, list);
    insertTail(Judy, list);

    printf("Size: %d\n", getSize(list));
    printClients(list);

    removeHead(list);

    printf("Size: %d\n", getSize(list));
    printClients(list);

    removeTail(list);
    removeHead(list);

    printf("Size: %d\n", getSize(list));

    freeList(list);
    free(Rick);
    free(Judy);
    free(Harold);
}