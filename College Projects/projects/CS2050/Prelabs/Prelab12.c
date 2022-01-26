#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void * data;
    Tree * left;
    Tree * right;
} Tree;

double * shuffleArray(double * array, int n) {
    int i, k, temp;
    for (i=0; i<n; i++) {
        k = random_int(n); 
        temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
}

void DeleteTree(Tree *t) {
    if (t == NULL) return;
    DeleteTree(t->left);
    DeleteTree(t->right);
    free(t); 
}