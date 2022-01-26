#include "lab5.h"

int main() {
    
    Client * array = loadClientsFromFile("clients.txt");
    
    printf("Size: %d\n", getArraySize(array));
    
    printClientArray(array);

    printf("Oldest Acct: %lu", (getOldestAccount(array))->accountNumber);

    return 0;
}

