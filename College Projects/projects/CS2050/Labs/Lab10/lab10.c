#include "lab10.h"
#include <float.h>

typedef struct Node Node;

struct Node {
	Node *next;
    Node *prev;
	void *data;
};

/* for my queue structure i decided to use a head, a tail, and 
an int to keep track of size. while a head or even a next ptr in
the node is not necessary for these functions, I find it allows
for easier list traversal and two dummy nodes on either end
allow for storage of a MAX and MIN priority, meaning I always
have something to compare to*/
struct Queue{
    Node *head;
    Node *tail;
	int size;
};

Node* makeNode(void *data, Node *next, Node *prev) { 
    Node *node = malloc(sizeof(Node));

    if(node) {
        *node = (Node){ next, prev, data };
    }

    return node;
}

//Complexity: O(1)
//Initializes an empty priority queue and returns it to the user
Queue* initPQ() {
    Queue *queue = malloc(sizeof(Queue));
    Client *maximus = malloc(sizeof(Client));
    maximus->accountWorth = FLT_MAX;
    Client *minnie = malloc(sizeof(Client));
    minnie->accountWorth = FLT_MIN;

    if(queue) {
        Node* begin = makeNode(maximus, NULL, NULL);
        Node* end = makeNode(minnie, NULL, begin);
        begin->next = end;
        queue->head = begin;
        queue->tail = end;
        queue->size = 0;
    }

    return queue;
}
/* This function frees all memory associated with the
priority queue. the user should not try to access PQ after*/
void freePQ(Queue *pq) {
    Node *cursor = pq->head;

    while(cursor) {
        Node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }

    pq->head = NULL;
    pq->tail = NULL;
    pq->size = 0;
    free(pq);
}
// Complexity: O(n)
//this function inserts a client into the queue based on its
//accountWorth member. it returns a 0 on fail and 1 on success
int insertClientDescendingPQ(Queue *pq, Client *client) {
    Node *cursor = pq->head->next;
    while(cursor) {
        Client *lesser = cursor->data;
        Client *greater = cursor->prev->data;
        if(client->accountWorth >= lesser->accountWorth && client->accountWorth <= greater->accountWorth) {
            Node* new = makeNode(client, cursor, cursor->prev);            
            cursor->prev->next = new;
            cursor->prev = new;
            ++pq->size;
            return 1;
        }
        else { cursor = cursor->next; }
    }
    return 0;
}
/* This function returns the smallest priority value in the
PQ in O(1) time*/
Client* peekMinClient(Queue *pq) {
    if(pq->size == 0) {
        printf("error: list empty :(\n");
        return NULL;
    }
    return pq->tail->prev->data;
}
// Complexity: O(1)
//this function removes the client with lowest acctWorth from
//this list and returns the client to the user.
Client* deQueueMinClient(Queue *pq) {
    if(pq->size == 0) {
        printf("error: list empty\n");
        return NULL;
    }

    Node *old = pq->tail->prev;
    pq->tail->prev = old->prev;
    old->prev->next = pq->tail;
    --pq->size;
    return old->data;
}

void printClients(Queue *list) {
    Node *cursor = list->head->next;
    while(cursor->next) {
        Client *ptr = cursor->data;
        printf("Acct Number: %lu, Acct Worth: %f, Days Active: %d\n", ptr->accountNumber, ptr->accountWorth, ptr->daysActive);
        cursor = cursor->next;
    }
}

int getSizePQ(Queue* q) {
    return q->size;
}