#include <stdio.h>
#include <stdlib.h>

// partial typedef, so you can define your own list type
typedef struct List List;

typedef struct Node Node;

struct Node {
	Node *next;
    Node *prev;
	void *data;
};

// COMPLEXITY: O(1)
List* initList();
// COMPLEXITY: O(1)
int getSize(List *list);
// COMPLEXITY: O(n)
void* getAtIndex(List *list, int index);
// COMPLEXITY: O(n)
void freeList(List *list);

#define SECT_F
// COMPLEXITY: O(1)
int insertAtTail(List *list, void *object);
// COMPLEXITY: O(1)
void* getHead(List *list);
// COMPLEXITY: O(n)
void* removeHead(List *list);

//Helper Functions
Node* makeNode(void *data, Node *next, Node *prev);
void printClients(List *list);
