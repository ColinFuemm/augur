#include<stdio.h>
#include<stdlib.h>
#define StackMaxSize 10 
typedef char ElemType;
typedef struct RBNode RBNode;

char* filename = "num.txt";

typedef struct {
    RBNode* root;
    RBNode* nil;
    int size;
} RBTree;
struct RBNode {
    int data;            
    RBNode* left;   
    RBNode* right;
    RBNode* parent;
    char color;  
};
//constructs a node from given possible parameters in order data, left, right, parent, color, returns null on fail
RBNode* makeNode(int data, RBNode* left, RBNode* right, RBNode* parent, char color) {
    RBNode* new = malloc(sizeof(RBNode));
    if(new) {
        new->data = data;
        new->left = left;
        new->right = right;
        new->parent = parent;
        new->color = color;
    }
    return new;
}
//constructs a new Red Black Tree with the Nil() node in the root spot to start
RBTree* InitRBTree()
{
    RBTree* T = malloc(sizeof(RBTree));
    T->nil = makeNode(0, NULL, NULL, NULL, 'b');
    T->root = T->nil;
    return T;
}
void leftRotate(RBTree* T, RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    if (y->left != T->nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == T->nil) {
        T->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else x->parent->right = y;
    y->left = x;
    x->parent = y;
}
void rightRotate(RBTree* T, RBNode* x) {
    RBNode* y = x->left;
    x->left = y->right;
    if (y->right != T->nil) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == T->nil) {
        T->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else x->parent->left = y;
    y->right = x;
    x->parent = y;
}
void RBInsertFixup(RBTree* T, RBNode* z) {
    RBNode* y;
    while (z->parent->color == 'r') {
        if(z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;   //y is uncle
            if (y->color == 'r') {
                z->parent->color = 'b';     //case 1
                y->color = 'b';
                z->parent->parent->color = 'r';
            }
            else if (z == z->parent->right) {
                leftRotate(T, z->parent);
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                rightRotate(T, z->parent->parent);
            }
        } else if (z->parent == z->parent->parent->right) {
            y = z->parent->parent->left;   //y is uncle
            if (y->color == 'r') {
                z->parent->color = 'b';     //case 1
                y->color = 'b';
                z->parent->parent->color = 'r';
            }
            else if (z == z->parent->left) {
                rightRotate(T, z->parent);
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                leftRotate(T, z->parent->parent);
            }
        }
    }
    T->root->color = 'b';
}
void RBInsert(RBTree* T, RBNode* z) {
    RBNode* x = T->root;
    if(x == T->nil) {
        T->root = z;
        z->color = 'b';
        return;
    } else {
    RBNode* y = x->parent;
    while (x != T->nil) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else x = x->right;
    }
    y = z->parent;
    if (y == T->nil) {
        T->root = z;
    } else if (z->data < y->data) {
       y->left = z; 
    } else y->right = z;
    z->left = T->nil;
    z->right = T->nil;
    z->color = 'r';
    RBInsertFixup(T, z);
    }
}
void CreateRBTree(RBTree* BT)
{
    RBNode* p;
    int k; //k is used as the flag for processing nodes, k=1 for left subtree andk=2 for right subtree
    int i = 0;
    int data;
    FILE *fp = fopen(filename, "r");
    if(!fp) {
		fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
		return;
	}
    while (fp)
    {
        fscanf(fp, "%4[^,]", data);
        p = makeNode(data, BT->nil, BT->nil, BT->nil, 'r');
        RBInsert(BT, p);
    }
    fclose(fp);
}
RBNode* TreeSuccessor(RBTree* T, RBNode* x) {
    if (x->right != T->nil) {
        while(x->left != T->nil) {
            x = x->left;
        } 
        return x;
    }
    RBNode* y = x->parent;
    while (y != T->nil && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}
RBNode* TreePredecessor(RBTree* T, RBNode* x) {
    if (x->left == T->nil) {
        while(x->right != T->nil) {
            x = x->right;
        } 
        return x;
    }
    RBNode* y = x->parent;
    while (y != T->nil && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}
void RBDeleteFixup(RBTree* T, RBNode* x) {
    while (x != T->root && x->color == 'b') {
        if (x == x->parent->left) {
            RBNode* w = x->parent->right;
            if(w->color == 'r') {
                w->color = 'b';
                x->parent->color = 'r';
                leftRotate(T, x->parent);
                w = x->parent->right;
            }
            if(w->left->color == 'b' && w->right->color == 'b') {
                w->color = 'r';
                x = x->parent;
            } else if (w->right->color == 'b') {
                w->left->color = 'b';
                w->color = 'r';
                rightRotate(T, x->parent);
                w = x->parent->right;
            }
            w->color = x->parent->color;
            x->parent->color = 'b';
            w->right->color = 'b';
            leftRotate(T, x->parent);
            x = T->root;
        } else {
            RBNode* w = x->parent->left;
            if(w->color == 'r') {
                w->color = 'b';
                x->parent->color = 'r';
                rightRotate(T, x->parent);
                w = x->parent->left;
            }
            if(w->right->color == 'b' && w->left->color == 'b') {
                w->color = 'r';
                x = x->parent;
            } else if (w->left->color == 'b') {
                w->right->color = 'b';
                w->color = 'r';
                leftRotate(T, x->parent);
                w = x->parent->left;
            }
            w->color = x->parent->color;
            x->parent->color = 'b';
            w->left->color = 'b';
            rightRotate(T, x->parent);
            x = T->root;
        }
        x->color = 'b';
    }
}
void RBDelete(RBTree* T, RBNode* z) {
    RBNode* y;
    RBNode* x;
    if (z->left == T->nil || z->right == T->nil) {
        y = z;
    } else y = TreeSuccessor(T, z); 
    if (y->left == T->nil) {
        y->left = x;
    } else y->right = x;
    y->parent = x->parent;
    if(y->parent == T->nil) {
        x = T->root;
    } else if (y == y->parent->left) {
        x = y->parent->left;
    } else x = y->parent->left;
    if (y == z) {
        y->data = z->data;
        y->color = z->color;
    }
    if (y->color == 'b') {
        RBDeleteFixup(T, x);
    }
}
int RBTreeEmpty(RBTree* T)
{
    if (T->root == NULL)
        return 1;
    else
        return 0;
}
int RBTreeDepth(RBNode* BT)
{
    if (BT == NULL)
        return 0;
    else
    {
        int dep1 = RBTreeDepth(BT->left); // Calculate left subtree depth
        int dep2 = RBTreeDepth(BT->right);// Calculate right subtree depth
        if (dep1 > dep2)
            return dep1 + 1;
        else
            return dep2 + 1;
    }
}
int BlackDepth(RBNode* BT)
{
    int isBlack = 0;
    if (BT->color == 'b') isBlack = 1;
    if (BT == NULL)
        return 0;
    else
    {
        int dep1 = BlackDepth(BT->left); // Calculate left subtree depth
        int dep2 = BlackDepth(BT->right);// Calculate right subtree depth
        if (dep1 != dep2) {
            printf("Error: Black Tree Height is uneven.");
        }
        return dep2 + isBlack;
    }
}
void ClearNodes(RBTree* T, RBNode* N) {
    if (N != T->nil)
    {
        ClearNodes(T, N->left);// delete left subtree
        ClearNodes(T, N->right);// delete right subtree
        free(N);            // free root node
        N = NULL;           // Set root pointer to null
    }
}
void ClearRBTree(RBTree* T) {
    ClearNodes(T, T->root);
    free(T);
    T = NULL;
}
void PrintNode(RBTree* T, RBNode* BT) {
    if (BT != T->nil) {
        printf("%d", BT->data);
        if (BT->left != NULL || BT->right != NULL)
        {
            printf("(");
            PrintNode(T, BT->left); // Output left subtree
            if (BT->right != NULL) printf(",");
            PrintNode(T, BT->right); // Output right subtree
            printf(")");
        }
    }
}
void PrintRBTree(RBTree* T) {
    PrintNode(T, T->root);
}
int main() {
    RBTree* T = InitRBTree();
    CreateRBTree(T);
    PrintRBTree(T);
    ClearRBTree(T);
}