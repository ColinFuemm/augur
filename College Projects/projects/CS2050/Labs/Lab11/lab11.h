#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Complexity: O(1)
void* createArray(size_t size, size_t elemSize);

// Complexity: O(1)
size_t arraySize(void *array);

// Complexity: O(1)
void freeArray(void *array);

#define SECT_F

typedef struct {
	unsigned long accountNumber;
	float accountWorth;
	int daysActive;
} Client;

//helper functions
//Complexity: O(n)
void printClientArray(Client *clients);

//Complexity: O(1)
float getAW(Client *client);

// Complexity: O(log(n))
size_t searchClients(Client *array, Client *query);

// Complexity: O(1)
int compareClients(Client *a, Client *b);
