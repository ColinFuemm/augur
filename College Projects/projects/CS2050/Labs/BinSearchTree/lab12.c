#include "lab12.h"

/*My structuring of BST and nodes is most likely not what
you all were looking for. Achieving recursion with this lab's
prototypes was tricky as my BST is only good for starting
at the top of the tree. Because of this, I created multiple
functions that utilized nodes over BST in order to achieve 
recursion. It may look confusing, but my functions still operate 
as intended. */
struct BST {
    Node *head;
    size_t size;
};

struct Node {
	void *data;
    Node *left;
    Node *right;
};

//initializes a binary search tree and returns it to the user
BST* initBST() {
    BST *tree = malloc(sizeof(BST));

    if(tree) {
        tree->head = NULL;
        tree->size = 0;
    }

    return tree;
}

//returns the current number of objects in the tree.
size_t BSTSize(BST *tree) {
    return tree->size;
}

//calls DeleteTree to free each node in the tree recursively 
//before then freeing the tree itself.
void freeBST(BST *tree) {
    if (tree == NULL) return;
    DeleteTree(tree->head);
    free(tree);
}

//checks if tree is empty and inserts client at head if so.
//otherwise, calls recursize insertNode to traverse tree and
//finds a place for given client based on accountWorth.
//returns a 1 on success and 0 on failure
int insertClient(BST *tree, Client *client) {
    if(tree->size == 0) {
        Node * new = makeNode(client, NULL, NULL);
        tree->head = new;
        ++tree->size;
        return 1;
    }
    if(insertNode(tree->head, client) == 1) {
        ++tree->size;
        return 1;
    }
    return 0;
}

/*checks if tree is empty and returns error code if so.
otherwise, calls recursive searchNode to traverse tree and 
checks for the given client in the list. returns a 1 on success
and a 0 on failure.*/
int searchClients(BST *tree, Client *query) {
    if(tree->size == 0) {
        printf("error: tree empty\n");
        return 0;
    }
    if(searchNode(tree->head, query) == 1) {
        printf("client found!\n");
        return 1;
    }
    printf("client not found :(\n");
    return 0;
}

//calls recursive printNode function to traverse
//tree and print clients in order
void inOrderPrintClients(BST *tree) {
    printNode(tree->head);
}

//traverses tree recursively and prints clients in order
void printNode(Node *head) {
    if(head == NULL) return;
    printNode(head->left);
    Client *ptr = head->data;
    printf("Acct Number: %lu, Acct Worth: %f, Days Active: %d\n", ptr->accountNumber, ptr->accountWorth, ptr->daysActive);
    printNode(head->right);
}

//helper function to create nodes within other functions
Node* makeNode(void *data, Node *left, Node *right) { 
    Node *node = malloc(sizeof(Node));

    if(node) {
        *node = (Node){ data, left, right };
    }

    return node;
}

//traverses tree recursively to free each node
void DeleteTree(Node *t) {
    if (t == NULL) return;
    DeleteTree(t->left);
    DeleteTree(t->right);
    free(t); 
}

//compares clients by accountWorth, returns negative if a < b,
// 0 if equal, and positive if a > b
int compareClients(Client *a, Client *b) {
    if(a->accountWorth < b->accountWorth) {
        return -1;
    } 
    else if(a->accountWorth == b->accountWorth) {
        return 0;
    }
    return 1;
}

/*traverse tree and finds a place for given client based on 
accountWorth. returns a 1 on success and 0 on failure. */
int insertNode(Node* head, Client* client) {
    if (compareClients(client, head->data) < 0) {
        if(head->left == NULL) {
            Node *new = makeNode(client, NULL, NULL);
            head->left = new;
            return 1;
        }
        else { insertNode(head->left, client); }
    }
    if (compareClients(client, head->data) >= 0) {
        if(head->right == NULL) {
            Node *new = makeNode(client, NULL, NULL);
            head->right = new;
            return 1;
        }
        else { insertNode(head->right, client); }
    }
    return 0;
}

/*traverse tree and finds a given client based on 
accountWorth. returns a 1 on success and 0 on failure. */
int searchNode(Node* head, Client* client) {
    if (compareClients(client, head->data) < 0) {
        if(head->left != NULL) {
            searchNode(head->left, client); 
        }
    }
    if (compareClients(client, head->data) > 0) {
        if(head->right != NULL) {
            searchNode(head->right, client); 
        }
    }
    if (compareClients(client, head->data) == 0) {
        return 1;
    }
    return 0;
}