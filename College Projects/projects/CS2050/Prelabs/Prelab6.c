#include <stdio.h>
#include <stdlib.h>

typedef struct arrayListStruct {
    void **array;
    int arraySize, quantity;
} List;

List* initList(int size);
int insertAtHead(void* address,List* list);
void* getAtIndex(int index, List* list);
int getListSizeLimit(List* list);
int getListLength(List* list);
void clearList(List* list);
void freeList(List* list);

int main ()
{
    List* test = initList(1);
    int *p = malloc(sizeof(int *));
    *p = 5;
    printf("Size: %d\n", getListSizeLimit(test));
    printf("Count: %d\n", getListLength(test));

    insertAtHead((void *)p, test);
    insertAtHead((void *)p, test);
    printf("Count: %d\n", getListLength(test));
    int *t = malloc(sizeof(int *));
    t = getAtIndex(0, test);
    printf("Test Value: %d\n", *t);

    clearList(test);
    printf("Count: %d\n", getListLength(test));
    t = getAtIndex(0, test);

    free(p);
    free(t);
    freeList(test);
}

/* This function returns an empty List object. The parameter
 specifies the maximum length of the list. */
List* initList(int size) {
    List* empty = malloc(sizeof(List));
    empty->arraySize = size;
    empty->array = malloc(size*(sizeof(void *)));
    empty->quantity = 0;
    return empty;
}
 
 /* This function inserts the object of the first parameter 
 at the head of the list and returns an error code of -1 if
 the list is full. */
int insertAtHead(void* newPtr, List* list) {
    if(getListSizeLimit(list) == getListLength(list)) 
    {
        printf("error: list is full.\n");
        return -1;
    }

    for(int i = (getListSizeLimit(list)-1); i > 0; i--)
        { list->array[i] = list->array[i-1]; }
    
    list->array[0] = newPtr;
    list->quantity += 1;
    return 0;
}

 /* This function returns the object at the index location 
 given by the first parameter. */
void* getAtIndex(int index, List* list) {
    return list->array[index];
}
 
 /* This function returnsthesize limit of the array, i.e.,
  the value that was specified when the List was created.*/
int getListSizeLimit(List* list) {
    return list->arraySize;
}
  
  /* This function returns the number of objects in the list. */
int getListLength(List* list) {
    return list->quantity;
}
  
  /* This function clears the list (makes it empty) just like
  it was after initList was called.*/
void clearList(List* list) {
    for(int i = 0; i < getListSizeLimit(list); i++)
        { list->array[i] = NULL; }
    list->quantity = 0;
}
  
  /* This function frees all memory allocated for a list and 
  so is not the same as clearList.*/
void freeList(List* list) {
    free(list->array);
    free(list);
}