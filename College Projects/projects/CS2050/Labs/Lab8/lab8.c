#include "lab8.h"

int compareClients(Client *a, Client *b) {
    float difference = (a->accountWorth - b->accountWorth);
    if(difference < 0) return -1;
    else if(difference = 0) return 0;
    else if(difference > 0) return 1;
}

int insertClientAscending(List *list, Client *client) {
    if(getSize(list) == 0) {
        insertAtIndex(list, client, 0);
        return 1;
    }
    Node *cursor = list->head;
    int index = 0;
    if(compareClients(client, cursor->data) < 0) {
        insertAtIndex(list, client, 0);
        return 1;
    }
    if(getSize(list) == 1) {
        if(compareClients(client, cursor->data) > 0) {
        insertAtIndex(list, client, 1);
        return 1; }
    }
    while(cursor) {
        if(compareClients(client, cursor->data) >= 0 &&
           compareClients(client, cursor->next->data) <= 0) {
               insertAtIndex(list, client, index);
               return 1;
        }
        ++index;
        cursor = cursor->next;
    }
    return 0;
}

int countAllLesserClients(List *list, Client *client) {
    Node *cursor = list->head;
    int counter = 0;
    while(cursor) {
        if(compareClients(client, cursor->data) > 0) {
            counter++;
        }
        cursor = cursor->next;
    }
    return counter -1;
}

void printClients(List *list) {
    Node *cursor = list->head;
    while(cursor) {
        Client *ptr = cursor->data;
        printf("Acct Number: %lu, Acct Worth: %f, Days Active: %d\n", ptr->accountNumber, ptr->accountWorth, ptr->daysActive);
        cursor = cursor->next;
    }
}