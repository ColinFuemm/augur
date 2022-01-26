#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct BST BST;
typedef struct Node Node;

// Complexity: O(1)
BST* initBST();

// Complexity: O(n)
size_t BSTSize(BST *tree);

// Complexity: O(n)
void freeBST(BST *tree);

#define SECT_F

typedef struct {
    unsigned long accountNumber;
    float accountWorth;
    int daysActive;
} Client;

// Complexity: O(log(n))
int insertClient(BST *tree, Client *client);

// Complexity: O(log(n))
int searchClients(BST *tree, Client *query);

// Complexity: O(n)
void inOrderPrintClients(BST *tree);

//Helper functions
Node* makeNode(void *data, Node *left, Node *right);
void DeleteTree(Node *t);
int compareClients(Client *a, Client *b);
int insertNode(Node* head, Client* client);
int searchNode(Node* head, Client* client);
void printNode(Node *head);