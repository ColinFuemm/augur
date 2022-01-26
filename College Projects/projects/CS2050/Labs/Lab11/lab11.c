#include "lab11.h"

// Complexity: O(1)
void* createArray(size_t size, size_t elemSize) {
    size_t *array = malloc(sizeof(int) + size * elemSize);
    if(!array) {
        return NULL;
    }
    *array = size;
    return ++array;
}

// Complexity: O(1)
size_t arraySize(void *array) {
    size_t *sizePtr = array;
    return sizePtr[-1];
}

// Complexity: O(1)
void freeArray(void *array) {
    size_t *ptr = array;
    free(ptr - 1);
}

#define SECT_F

//helper function to print the array
void printClientArray(Client *clients) {
    for (int i = 0; i < arraySize(clients); i++ )
    {
        printf("AN: %lu, AW: $%f, Age: %d\n", clients[i].accountNumber, clients[i].accountWorth, clients[i].daysActive);
    }
}

// Complexity: O(log(n))
size_t searchClients(Client *array, Client *query) {
	printf("binary search called\n");
    int first = 0;
    int last = arraySize(array);

    while(last >= first) {
        int mid = first + (last - first)/2;
        printf("Mid: %d\n", mid);

        if(compareClients(query, (array + mid)) == 0) {
            return mid;
        }
        if (compareClients(query, (array + mid)) < 0) {
            last = (mid - 1);
        }
        if(compareClients(query, (array + mid)) > 0) {
            first = (mid + 1);
        }
    }
    return -1;
}

// Complexity: O(1)
int compareClients(Client *a, Client *b) {
    if(a->accountWorth < b->accountWorth) {
        return -1;
    } 
    else if(a->accountWorth == b->accountWorth) {
        return 0;
    }
    return 1;
}
