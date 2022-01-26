#include "lab12.h"
int main () {
    Client *Rick = malloc(sizeof(Client));
    Client *Judy = malloc(sizeof(Client));
    Client *Harold = malloc(sizeof(Client));
    Client *John = malloc(sizeof(Client));
    Client *Jake = malloc(sizeof(Client));
    Client *Jeff = malloc(sizeof(Client));
    
    Rick->accountNumber = 5;
    Rick->accountWorth = 32.7;
    Rick->daysActive = 365;
    
    Judy->accountNumber = 2;
    Judy->accountWorth = 420.6;
    Judy->daysActive = 7;

    Harold->accountNumber = 9;
    Harold->accountWorth = 1.0;
    Harold->daysActive = 31;

    John->accountWorth = 5.0;
    John->accountNumber = 2;
    John->daysActive = 7;

    Jake->accountWorth = 25.0;
    Jake->accountNumber = 2;
    Jake->daysActive = 7;

    Jeff->accountWorth = 3000.69;
    Jeff->accountNumber = 2;
    Jeff->daysActive = 7;

    BST* list = initBST();
    printf("Size: %d\n", BSTSize(list));

    insertClient(list, Rick);
    insertClient(list, Jake);
    insertClient(list, Harold);
    insertClient(list, Judy);
    insertClient(list, Rick);
    insertClient(list, John);
    printf("Size: %d\n", BSTSize(list));

    inOrderPrintClients(list);
    if(searchClients(list, Judy) == 1) {
        printf("Judy found!\n");
    }
    if(searchClients(list, Jeff) == 1) {
        printf("Judy found!\n");
    }
    if(searchClients(list, John) == 1) {
        printf("Judy found!\n");
    }

    freeBST(list);
    free(Rick);
    free(Judy);
    free(Harold);
    free(John);
    free(Jeff);
    free(Jake);
}