#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define SECT_F
typedef struct {
	unsigned long accountNumber;
	float accountWorth;
	int daysActive;
} Client;

int compareClients(Client *a, Client *b);
int insertClientAscending(List *list, Client *client);
int countAllLesserClients(List *list, Client *client);
void printClients(List *list);
