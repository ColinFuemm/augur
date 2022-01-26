#include <stdio.h>
#include <stdlib.h>

// partial typedef, so the Node type can contain itself
typedef struct Node Node;

struct Node {
	Node *next;
	void *data;
};

typedef struct {
	Node *head;
	int size;
} List;

List* initList();
int getSize(List *list);
void freeList(List *list);
void* getAtIndex(List *list, int index);

#define SECT_F
int insertBefore(List *list, void *object, void *sentinel);
int hasDuplicates(List *list, void *object);
void* removeAfter(List *list, void *sentinel);

//Helper Functions
int isValidIndex(List *list, int index);
Node* makeNode(void *data, Node *next);
void* freeNode(Node *node);
void* nodeAtIndex(List *list, int index);
void clearList(List *list);
int indexOf(List *list, void *object);
Node* setHead(List *list, Node *newHead);
int insertAtIndex(List *list, void *object, int index);
