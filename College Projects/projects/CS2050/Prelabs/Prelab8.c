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
void printNode(Node * node);
int cmp(void *first, void *second);

int main() {
    return 0;
}

void* removeAtIndex(List *list, int index) {
    if(!isValidIndex(list, index) ) {
        return NULL;
    }
    Node *previous = nodeAtIndex(list, index-1);
    Node *temp = previous->next;
    previous->next = temp->next;
    --list->size;
    return freeNode(temp);
}

int isValidIndex(List *list, int index) {
    return index >= 0 && index < list->size;
}
// Allocates space for a Node struct, and returns a 
//pointer to the allocated memory
Node* makeNode(void *data, Node *next) {
    Node *node = malloc(sizeof(Node));
    if(node) {
        *node = (Node){ next, data };
    }
return node;
}
// Frees the given node struct pointer, 
// and returns the data contained within
void* freeNode(Node *node) {
    void *temp = node->data;
    free(node);
    return temp;
}
// returns the node at the requested index, or NULL on failure
void* nodeAtIndex(List *list, int index) {
    
    if(!isValidIndex(list, index)) {
        return NULL; 
    }

    Node *cursor = list->head;

    while(index--) {
        cursor = cursor->next; 
    }

    return cursor;
}
//frees nodes in list and sets the list back to empty
void clearList(List *list) {

    Node *cursor = list->head;

    while(cursor) {
        Node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }

    list->head = NULL;
    list->size = 0;
}
//returns index of given object or -1
int indexOf(List *list, void *object) {
    Node *cursor = list->head;
    int count = 0;
    while(cursor) {
        if(cursor->data == object) {
            return count;
        }
        ++count;
        cursor = cursor->next;
    }
    return -1;
}
// Sets the head of the list to the given node, and returns the old head
Node* setHead(List *list, Node *newHead) {
    Node *oldHead = list->head;
    list->head = newHead;
    return oldHead;
}
/* inserts the given object on the list at the given 
index. Returns 1 on success and 0 on failure. 
Note that list->size is a valid index, as it represents
the end of the list. */
int insertAtIndex(List *list, void *object, int index) {
    
    if(!isValidIndex(list, index) &&
       index != list->size) {
        return 0;         
    } else if(!index) {
        Node *new = makeNode(object, NULL);
        if(!new) 
            return 0;
        new->next = setHead(list, new);
    } else {
        Node *previous = nodeAtIndex(list, index - 1);
        Node *new = makeNode(object, previous->next);
        if(!new)
            return 0;
        previous->next = new;
    }
    ++list->size;
    return 1;
}
/* This function initializes and returns a linked list 
and NULL upon failure. */
List* initList() {

    List *list = malloc(sizeof(List));

    if(list) {
        list->head = NULL;
        list->size = 0;
    }

    return list;
}
/* This function takes a linked list and returns the number
 of elements on the list. */
int getSize(List *list) {
    return list->size;
}
/* This function takes a linked list and frees all memory
allocated for the list. */
void freeList(List *list) {
    clearList(list);
    free(list);
}
/* This function takes a linked list and returns the object
 at the given index, or NULL on error. */
void* getAtIndex(List *list, int index) {

    Node *temp = nodeAtIndex(list, index);
    if(temp) {
        return temp->data;
    }
    return NULL;
}
//This function removes any object in the list equal to par
int removeEQ (void *object, List *list)
{
    Node *cursor = list->head;
    int index = 0;
    int count = 0;
    while(cursor) {
        if(cmp(object, cursor->data) == 0) { 
            removeAtIndex(list, index);
            count++; 
        }
        ++index;
        cursor = cursor->next;
    }
    return count;
}
//This function inserts given object in its ascending order
int insertInOrder(void *object, List *list) 
{
    Node *cursor = list->head;
    int index = 0;
    while(cursor) {
        if(cmp(object, cursor->data) >= 0 &&
           cmp(object, cursor->next->data) <= 0) {
            return insertAtIndex(list, object, (index + 1));
        }
        ++index;
        cursor = cursor->next;
    }
    return -1;       
}
//This function prints the data stored in the node
void printNode(Node * node) {
    int * object = node->data;
    printf("%d\n", *object);
}
//This function compares the two data sets, returns neg
// if data1 smaller, 0 if equal, pos if larger
int cmp(void *data1, void *data2) {
    int *first = (int*)data1;
    int *second = (int*)data2;
    return (*first - *second);
}