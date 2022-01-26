#include<stdio.h>
#include<stdlib.h>
#define StackMaxSize 10 
typedef char ElemType;  

typedef struct  {
    ElemType data;            
    struct BTreeNode* left;   
    struct BTreeNode* right;  
    char color;
} BTreeNode;
void PrintBTree(struct BTreeNode* BT);
//1. Initialize the binary tree
void InitBTree(struct BTreeNode** BT)
{
    *BT = NULL; //leave the root pointer empty
}
 
// 2.Buidl our Binary Tree using generalized list
/*
 *             A
 *           /   \
 *          B     E
 *        /  \     \
 *       C    D     F
 *                 /
 *                G
 * 
 * generalized list: A(B(C,D),E(,F(G)))   
*/
void CreateBTree(struct BTreeNode** BT, char* string)
{
    struct BTreeNode* p;
    struct BTreeNode* s[StackMaxSize]; // Define the s array to be used as a stack for storing pointers to the root node
    int top = -1; // The top of the stack pointer is set to -1, indicating an empty stack
    int k; //k is used as the flag for processing nodes, k=1 for left subtree andk=2 for right subtree
    int i = 0; //Scan the binary tree generalized table string stored in the array string with i, the initial value is 0
    *BT = NULL; //Null the root tree pointer, i.e., build a binary tree from the empty tree
    while (string[i])
    {
        switch (string[i])
        {
            case ' ':break;
            case '(':
            {
                if (top == StackMaxSize - 1)
                {
                    printf("The stack is full, we need to modify the StackMaxSize\n");
                    exit(1);// exit(1) means abnormal exit, 0 means normal exit
                }
                top++;
                s[top] = p;
                k = 1;
                break;
            }
            case ')':
            {
                if (top == -1)
                {
                    printf("generalized list is wrong\n");
                    exit(1);
                }
                top--;
                break;
            }
            case ',':k = 2;break;
            default:
            {
                p = malloc(sizeof(struct BTreeNode));
                p->data = string[i];
                p->left = p->right = NULL;
                if (*BT == NULL)
                    *BT = p;
                else
                {
                    if (k == 1)
                        s[top]->left = p;
                    else
                        s[top]->right = p;
                }
            }
        }//switch end
        i++;
    }//while end
}
 
// 3.Check if the binary tree is empty
int BTreeEmpty(struct BTreeNode* BT)
{
    if (BT == NULL)
        return 1;
    else
        return 0;
}
 
// 4.Calculate binary tree depth
int BTreeDepth(struct BTreeNode* BT)
{
    if (BT == NULL)
        return 0;
    else
    {
        int dep1 = BTreeDepth(BT->left); // Calculate left subtree depth
        int dep2 = BTreeDepth(BT->right);// Calculate right subtree depth
        if (dep1 > dep2)
            return dep1 + 1;
        else
            return dep2 + 1;
    }
}
 
//5.Find the node with value x from the binary tree and return the element storage 
//location if it exists, otherwise return the null value (the algorithm is similar to
//preorder traversal)
ElemType* FindBTree(struct BTreeNode* BT, ElemType x)
{
    if (BT == NULL)
        return NULL;
    else
    {
        if (BT->data == x)
            return &(BT->data);
        else
        {
            ElemType* p;
            if (p = FindBTree(BT->left, x))
                return p;
            if (p = FindBTree(BT->right, x))
                return  p;
            return NULL;
        }
    }
}
 
// 6.Output a binary tree, which can be modified on the basis of the preorder traversal. A generalized table is used as the output format.
void PrintBTree(struct BTreeNode* BT) {
    if (BT != NULL) {
        printf("%c", BT->data); // Output the value of the root node
        if (BT->left != NULL || BT->right != NULL)
        {
            printf("(");
            PrintBTree(BT->left); // Output left subtree
            if (BT->right != NULL) printf(",");
            PrintBTree(BT->right); // Output right subtree
            printf(")");
        }
    }
}
 
//7.Clear a binary tree
void ClearBTree(struct BTreeNode** BT)
{
    if (*BT != NULL)
    {
        ClearBTree(&((*BT)->left));// delete left subtree
        ClearBTree(&((*BT)->right));// delete right subtree
        free(*BT);            // free root node
        *BT = NULL;           // Set root pointer to null
    }
}
 
//8.preorder traversal: ABCDEFG
void Preorder(struct BTreeNode* BT)
{
    if (BT != NULL)
    {
        printf("%c,", BT->data);
        Preorder(BT->left);
        Preorder(BT->right);
    }
}
//9.inorder traversal :CBDAEGF
void Inorder(struct BTreeNode* BT) {
    if (BT != NULL)
    {
        Inorder(BT->left);
        printf("%c,", BT->data);
        Inorder(BT->right);
    }
}
//10. postorder traversal:CDBGFEA
void Postorder(struct BTreeNode* BT)
{
    if (BT != NULL)
    {
        Postorder(BT->left);
        Postorder(BT->right);
        printf("%c,", BT->data);
    }
}
void main()
{
    struct BTreeNode* bt;
    char b[50]; // define a string
    ElemType x, *px;
    InitBTree(&bt);
    printf("Please input a binary tree using generalized lists: \n");
    scanf("%s", b);
    CreateBTree(&bt, b);
    PrintBTree(bt);
    printf("\n");
 
    printf("preorder:");
    Preorder(bt);
    printf("\n");
 
    printf("inorder:");
    Inorder(bt);
    printf("\n");
 
    printf("Postorder:");
    Postorder(bt);
    printf("\n");
 
    printf("Please input a character you want to search in the tree\n");
    scanf(" %c", &x); //Spaces in the format string can skip any whitespace character
    px = FindBTree(bt, x);
    if (px)
        printf("Search successfully:%c\n", *px);
    else
        printf("Search failed\n");
 
    printf("Depth of Binary tree is ");
    printf("%d\n", BTreeDepth(bt));
    ClearBTree(&bt);
}