#include "lab8.h"

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
    
    insertClientAscending(list, Rick);
    insertClientAscending(list, Judy);
    insertClientAscending(list, Harold);
    
    printf("\n%d lesser clients.\n", countAllLesserClients(list, Judy));
    printClients(list);

    freeList(list);
    free(Rick);
    free(Judy);
    free(Harold);
}
