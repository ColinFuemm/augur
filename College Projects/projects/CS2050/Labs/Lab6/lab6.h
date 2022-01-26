#include <stdio.h>
#include <stdlib.h>

#define COMMON_1
typedef struct {
	void **array;
	int size;
	int maxSize;
} List;

List* initList(int maxSize);
int getSize(List *list);
int getmaxSize(List* list);
void freeList(List *list);
void clearList(List* list);
void* getAtIndex(List *list, int index);

#define SECT_F
int insertAtHead(List *list, void *object);
int isFull(List *list);
int hasDuplicates(List *list, void *object);
void* removeFromTail(List *list);
