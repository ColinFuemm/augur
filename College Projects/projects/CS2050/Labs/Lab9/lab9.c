#include "lab9.h"

struct List {
    Node *head;
    Node *tail;
	int size;
};

typedef struct {
	unsigned long accountNumber;
	float accountWorth;
	int daysActive;
} Client;

//Helper Functions
Node* makeNode(void *data, Node *next, Node *prev) {
    Node *node = malloc(sizeof(Node));
    if(node) {
        *node = (Node){ next, prev, data };
    }
    return node;
}
void printClients(List *list) {
    Node *cursor = list->head;
    while(cursor) {
        Client *ptr = cursor->data;
        printf("Acct Number: %lu, Acct Worth: %f, Days Active: %d\n", ptr->accountNumber, ptr->accountWorth, ptr->daysActive);
        cursor = cursor->next;
    }
}

// COMPLEXITY: O(1)
List* initList() {
    List *list = malloc(sizeof(List));

    if(list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }

    return list;
}
// COMPLEXITY: O(1)
int getSize(List *list) {
    return list->size;
}
// COMPLEXITY: O(n)
void* getAtIndex(List *list, int index) {

	Node *cursor = list->head;
    while(index--) {
		cursor = cursor->next;
	}

	return cursor->data;

}
// COMPLEXITY: O(n)
void freeList(List *list) {
    Node *cursor = list->head;

    while(cursor) {
        Node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    free(list);
}

#define SECT_F
// COMPLEXITY: O(1)
int insertAtTail(List *list, void *object) {
    if(getSize(list) == 0) {
        Node *new = makeNode(object, NULL, NULL);
        if(!new) { return 1; }
        list->head = new;
        list->tail = new;
        ++list->size;
        return 1;
    }
    
    Node *new = makeNode(object, NULL, list->tail);
        if(!new) { return 0; }
    list->tail->next = new;
    new->prev = list->tail;
    list->tail = new;
    ++list->size;
    return 1;
}
// COMPLEXITY: O(1)
void* getHead(List *list) {
    Node *node = list->head;
	if(node) {
		return node->data;
	}
	return NULL;
}
// COMPLEXITY: O(n)
void* removeHead(List *list) {
    Node *cursor = list->tail;
    int index = (getSize(list) -1);
    
    while(index--) {
		cursor = cursor->prev;
	}
    
    Node *old = cursor;
    list->head = cursor->next;
    list->head->prev = NULL;
    --list->size;
    return old;
}

