#include <stdio.h>
#include <stdlib.h>
/*
##################### Question 1 #####################
    BST 1: Minimum Height
         7
       /   \
      5     9   h = 3
     / \   / \
    1   3 11  13

    BST 2:
    1 
     \
      5
     / \
    3   7       h = 5
         \
          11
         /  \
        9    13

    BST 3:
           9
         /   \
        5     11  h = 4 
       / \      \
      3   7      13
     /
    1

*/ 
/*
##################### Question 2 #####################
    Traversal order for Post-Order Walk:
    1, 4, 3, 6, 5, 8, 10, 9, 13, 17, 15, 12, 7
*/
/*
##################### Question 3 #####################
recursive_Count(tree t) 
    internal, lcount, rcount = 0
    if x->left not NULL
        internal = 1;
        lcount = rCount_Branch(x->left);
    if x->right not NULL
        internal = 1;
        rcount = rCount_Branch(x->right);
    return lcount + rcount + internal;
iterative_Count(tree t)
    count = 0
    stack* S
    cursor = t
    while stack not empty && cursor not NULL
        if cursor not NULL
            if cursor->left or ->right not NULL
                count++
            S->push(cursor)
            left<-cursor
        else
            cursor = S->head
            S.pop()
            right<-cursor

*/
/*
##################### Question 4 #####################
Range_Walk(node x, key a, key b)
    if x not NULL
        if a <= x < b
            print(x)
        Range_Walk(node x->left, a, b)
        Range_Walk(node x->right, a, b)
*/
/*
##################### Question 5 #####################
check_Identical(node x, node y) 
    if x & y not NULL
        if x equals y
            check_Identical(x->left, y->left)
            check_Identical(x->right, y->right)
        else
            print("Trees are not identical.")        
*/