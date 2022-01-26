#include "lab6.h"

/* This function initializes and returns a List
 with the specified maxSize. */
List* initList(int maxSize) {
    List* empty = malloc(sizeof(List));
    empty->maxSize = maxSize;
    empty->array = malloc(maxSize*(sizeof(void *)));
    empty->size = 0;
    return empty;
}

 /* This function takes a List and returns the number of 
 elements on the list. */
int getSize(List* list) {
    return list->size;
}
  
  /* This function returns the max size of the list. */
int getmaxSize(List* list) {
    return list->maxSize;
}

  /* This function frees all memory allocated by the init function..*/
void freeList(List* list) {
    free(list->array);
    free(list);
}

  /* This function clears the list (makes it empty) just like
  it was after initList was called.*/
void clearList(List* list) {
    for(int i = 0; i < getmaxSize(list); i++)
        { list->array[i] = NULL; }
    list->size = 0;
}

 /* This function takes a List and returns the object at the 
 given index, or NULL on error.*/
void* getAtIndex(List *list, int index) {
    return list->array[index];
}
 
 /* This function inserts the object of the first parameter 
 at the head of the list and returns an error code of -1 if
 the list is full. */
int insertAtHead(List *list, void *object) {
    if((isFull(list)) == 1) 
    {
        printf("error: list is full.\n");
        return 0;
    }

    for(int i = (getmaxSize(list)-1); i > 0; i--)
        { list->array[i] = list->array[i-1]; }
    
    list->array[0] = object;
    list->size += 1;
    return 1;
}

/* This function takes a list and returns 1 if the list is full,
0 if it is not.*/
int isFull(List *list) {
    if(getSize(list) == getmaxSize(list))
    { return 1; }
    else { return 0; }
}

/* This function takes a list and returns 1 if the given object 
is on the list more than once, or 0 if otherwise. */
int hasDuplicates(List *list, void *object) {
    int count = 0;

    for(int i = 0; i < getmaxSize(list); i++) 
        { if(object == list->array[i]) count++; }

    if (count > 1) return 1;
    else return 0;
}

/* This function takes a List and removes the object at the end 
of the list. This function must return the object to the user. */
void* removeFromTail(List *list) {
    void * temp;
    for(int i = (getmaxSize(list)-1); i > 0; i--) {
        if (list->array[i] != NULL) {
            temp = list->array[i];
            list->array[i] = NULL;
            list->size -= 1;
            break;
        }
    }
    return temp;
}