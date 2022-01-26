#include "lab5.h"

//this function receives a pointer of type Client and returns
//the accountNumber member.
unsigned long getAN(Client *client) {
    return client->accountNumber;
}
//this function receives an accountNumber value and sets it equal to
//the corresponding Client pointer received
void setAN(Client *client, unsigned long AN) {
    client->accountNumber = AN;
}
//this function receives a pointer of type client and returns
//the accountWorth member.
float getAW(Client *client) {
    return client->accountWorth;
}
//this function receives an accountWorth value and sets it equal to
//the corresponding Client pointer received
void setAW(Client *client, float AW) {
    client->accountWorth = AW;
}
//this function receives a pointer of type client and returns
//the daysActive member.
int getDays(Client *client) {
    return client->daysActive;
}
//this function receives a daysActive value and sets it equal to
//the corresponding Client pointer received
void setDays(Client *client, int days) {
    client->daysActive = days;
}
//this function prints every member of the given array of Clients
void printClientArray(Client *clients) {
    for (int i = 0; i < getArraySize(clients); i++ )
    {
        printf("AN: %lu, AW: $%f, Age: %d\n", clients[i].accountNumber, clients[i].accountWorth, clients[i].daysActive);
    }
}
/*this function receives a filename which it then looks to open,
error checking if unsuccessful. it then takes the size and creates
an array of Clients, where it then stores the size in the 
beginning of the array and stores the Client info as well.*/
Client* loadClientsFromFile(const char *filename) {
     
    int total;
    
    FILE * fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error while opening file"); 
        return(0);
    }

    fscanf (fp, "%d", &total);
    
    Client * array = malloc(sizeof(int)+total * sizeof(Client));
    
    if(array == NULL)
    {
        printf("Failed to allocate memory.\n");
        return(0);
    }
    
    *((int*)array) = total;
    array += sizeof(int);
    
    
    for(int i = 0; i < total; i++)
    {
        fscanf (fp, "%lu, %f, %d", &array[i].accountNumber, &array[i].accountWorth, &array[i].daysActive);
    }
    
    fclose (fp);
    
    return array;
}
//this function iterates through an array of clients, then returns
//the Client with the largest daysActive value
Client* getOldestAccount(Client *clients) {
    Client * Oldest = clients;
    for (int i = 1; i < getArraySize(clients); i++ )
    {
        if(clients[i].daysActive > Oldest->daysActive) {
            Oldest = clients + i;
        }
    }
    return Oldest;
}
//this function searches an array of clients and returns
//the Client with the matching given acct number, if it exists
Client* getClientByAN(Client *clients, unsigned long AN) {
    for (int i = 0; i < getArraySize(clients); i++ )
    {
        if(clients[i].accountNumber == AN) 
        {
            return (clients + i);
        }
    }
    printf("Error: No such Account Number found.\n");
    return NULL;
}
//this function adds up all accountWorth values from a given array
//of Clients
double sumAccountWorth(Client *clients) {
    double totalSum = 0.0;
    for (int i = 0; i < getArraySize(clients); i++)
    {
        totalSum += clients[i].accountWorth;
    }
    return totalSum;
}
//returns size of array stored at the front of the given array of
//clients.
int getArraySize(Client *array)
{
    return *((int*)(array-sizeof(int)));
}