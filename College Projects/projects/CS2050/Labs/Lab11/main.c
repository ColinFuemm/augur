#include "lab11.h"

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

    Client *array = createArray(7, sizeof(Client *));
    array[0] = *Harold;
    array[1] = *Harold;
    array[2] = *Rick;
    array[3] = *Judy;
    array[4] = *Judy;
    array[5] = *Judy;
    array[6] = *Judy;

    printClientArray(array);

    int result = searchClients(array, Rick);
    (result == -1) ? printf("Element not found") 
                   : printf("Element at index %zu", result);

    freeArray(array);
    free(Rick);
    free(Judy);
    free(Harold);
}