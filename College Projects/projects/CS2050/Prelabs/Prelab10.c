#include <stdio.h>
#include <stdlib.h>
#include <float.h>

typedef struct Node Node;

struct Node {
	Node *next;
    Node *prev;
	void *data;
    double priority;
};

typedef struct {
    Node *head;
    Node *tail;
	int size;
} PQueue;

Node* makeNode(void *data, Node *next, Node *prev, double priority) { 
    Node *node = malloc(sizeof(Node));

    if(node) {
        *node = (Node){ next, prev, data, priority };
    }

    return node;
}

/* This function initializes a priority queue and returns a
pointer to the user. Upon failure, eCode is a -1.*/
PQueue* initPQueue(int* eCode) {
    PQueue *queue = malloc(sizeof(PQueue));

    if(queue) {
        Node* begin = makeNode(NULL, NULL, NULL, -DBL_MAX);
        Node* end = makeNode(NULL, NULL, begin, DBL_MAX);
        begin->next = end;
        queue->head = begin;
        queue->tail = end;
        queue->size = 0;
    }
    else { *eCode = -1; }

    return queue;
}
/* This function returns the number of objects in the priority
queue in O(1) time.*/
int getSizePQ(PQueue* q) {
    return q->size;
}
/* This function inserts obj with its associated priority and
returns a 1 on success, 0 upon failure.*/
int insertPQ(void* obj, double order, PQueue* q) {
    Node *cursor = q->head->next;
    while(cursor) {
		printf("in the loop\n");
        if(cursor->prev->priority < order && cursor->priority >= order) {
            printf("if statement passed\n");
            Node* new = makeNode(obj, cursor, cursor->prev, order);
            printf("node made\n");
            cursor->prev->next = new;
            cursor->prev = new;
            ++q->size;
            return 1;
        }
        else { cursor = cursor->next; }
	}
	return 0;
}
/* This function removes and returns the object with minimum
priority in O(1) time.*/
void* minDeletePQ(PQueue* q) {
    if(getSizePQ(q) == 0) {
        printf("error: list empty\n");
        return NULL;
    }

    Node *old = q->head->next;
    q->head->next = old->next;
    old->next->prev = q->head;
    --q->size;
    return old->data; 
}
/* This function removes and returns the object with maximum
priority in O(1) time. */
void* maxDeletePQ(PQueue* q) {
    if(getSizePQ(q) == 0) {
        printf("error: list empty\n");
        return NULL;
    }

    Node *old = q->tail->prev;
    q->tail->prev = old->prev;
    old->prev->next = q->tail;
    --q->size;
    return old->data;
}
/* This function returns the smallest priority value in the
PQ in O(1) time*/
double getMinPriority(PQueue* q) {
    return q->head->next->priority;
}
/* This function returns the largest priority value in the PQ
in O(1) time */
double getMaxPriority(PQueue* q) {
    return q->tail->prev->priority;
} 
/* This function frees all memory associated with the
priority queue. Documentation should explicitly inform the
user to not attempt to use the PQ after calling this function. */
void freePQ(PQueue* q) {
    Node *cursor = q->head;
    printf("Cursor Start.");

    while(cursor) {
        Node *temp = cursor;
        cursor = cursor->next;
        free(temp);
        printf("Node Freed.");
    }

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    printf("List Emptied.");
    free(q);
    if(q == NULL) {
       printf("Memory Freed.");
    }
}

typedef struct {
	unsigned long accountNumber;
	float accountWorth;
	int daysActive;
} Client;

void printClients(PQueue *list) {
    if(getSizePQ(list) == 0) {
        printf("List Empty.\n");
    }
    Node *cursor = list->head->next;
    while(cursor->next) {
        Client *ptr = cursor->data;
        printf("Acct Number: %lu, Acct Worth: %f, Days Active: %d\n", ptr->accountNumber, ptr->accountWorth, ptr->daysActive);
        cursor = cursor->next;
    }
}

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
    
    int *check = 0;
    
    PQueue *list = initPQueue(check);

    printf("Check %d\n", check);
    
    int x = insertPQ(Rick, 3.75, list);
    printf("Check %d\n", x);
    int y = insertPQ(Judy, -203.75, list);
    printf("Check %d\n", y);
    int z = insertPQ(Harold, 3000.75, list);
    printf("Check %d\n", z);

    printf("Size: %d\n", getSizePQ(list));
    printClients(list);
    printf("Max Priority: %f\n", getMaxPriority(list));
    printf("Min Priority: %f\n", getMinPriority(list));

    if(Judy == minDeletePQ(list)) {
        printf("Judy removed.\n");
    }

    printf("Size: %d\n", getSizePQ(list));
    printClients(list);

    if(Harold == maxDeletePQ(list)) {
        printf("Harold removed.\n");
    }
    if(Rick == maxDeletePQ(list)) {
        printf("Rick removed.\n");
    }

    printf("Size: %d\n", getSizePQ(list));

    freePQ(list);
    free(Rick);
    free(Judy);
    free(Harold);
}