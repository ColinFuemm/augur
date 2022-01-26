#include "lab10.h"

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
    
    Queue *list = initPQ();
    
    int x = insertClientDescendingPQ(list, Rick);
    printf("Check %d\n", x);
    int y = insertClientDescendingPQ(list, Judy);
    printf("Check %d\n", y);
    int z = insertClientDescendingPQ(list, Harold);
    printf("Check %d\n", z);

    printf("Size: %d\n", getSizePQ(list));
    printClients(list);
    if(peekMinClient(list) == Harold) {
        printf("Harold found.\n");
    }

    deQueueMinClient(list);

    printf("Size: %d\n", getSizePQ(list));
    printClients(list);

    deQueueMinClient(list);
    if(peekMinClient(list) == Judy) {
        printf("Judy found.\n");
    }
    deQueueMinClient(list);
    if(peekMinClient(list) == Harold) {
        printf("Harold found.\n");
    }

    printf("Size: %d\n", getSizePQ(list));

    freePQ(list);
    free(Rick);
    free(Judy);
    free(Harold);
}