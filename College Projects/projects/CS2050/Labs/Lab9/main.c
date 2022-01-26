#include "lab9.h"

typedef struct {
	unsigned long accountNumber;
	float accountWorth;
	int daysActive;
} Client;

int main() {

    Client *Rick = malloc(sizeof(Client));
    Client *Judy = malloc(sizeof(Client));
    Client *Harold = malloc(sizeof(Client));
    
    Rick->accountNumber = 5;
    Rick->accountWorth = 32.7;
    Rick->daysActive = 365;
    
    Judy->accountNumber = 2;
    Judy->accountWorth = 420.6;
    Judy->daysActive = 7;

    Harold->accountNumber = 9;
    Harold->accountWorth = 1.0;
    Harold->daysActive = 31;
    
    List *list = initList();
    
    insertAtTail(list, Rick);
    insertAtTail(list, Judy);
    insertAtTail(list, Harold);

    printf("Size: %d\n", getSize(list));
    printClients(list);

    if (Judy == getAtIndex(list, 1)) {
        printf("Judy found!\n");
    }
    if (Rick == getHead(list)) {
        printf("Rick found!\n");
    }
    removeHead(list);
    printClients(list);

    freeList(list);
    free(Rick);
    free(Judy);
    free(Harold);
}
