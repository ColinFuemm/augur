#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
###################  Question 1  ###################
The following question is answered in pseudocode, meanwhile an actual coded version
that runs is below the initial pseudocode, in case there is any confusion.

Palindrome( List ) {
    //First we make a reversed version of the list
    List reverseList;
    for x in list {
        addAtHead(x, reverseList); //this function inserts a node at the front of the list
        x->next;                   //like a stack, which reverses its order from the original
    }
    //Once that is complete, we will iterate through the list and check that each value is equal
    cursor = list->head;
    inverseCursor = inverseList->head;
    for x and y in list and reverseList {
        if(x != y) { 
            not a palindrome;
        }
        x->next;
        y->next;
    }
    if loop completes
    palindrome;
}
*/
typedef struct Node Node;

struct Node {
	Node *next;
	int data;
};

typedef struct {
	Node *head;
	int size;
} List;

Node* makeNode(int data, Node* next);
List* initList();
int addAtEnd(List *list, int data);
int addAtHead(List* list, int data);
void Palindrome(List* list);

int main() {
    List* list = initList();
    addAtEnd(list, 1);
    addAtEnd(list, 2);
    addAtEnd(list, 3);
    addAtEnd(list, 2);
    addAtEnd(list, 1);
    Palindrome(list);
    return 0;
}
// Allocates space for a Node struct, and returns a 
//pointer to the allocated memory
Node* makeNode(int data, Node *next) {
    Node *node = malloc(sizeof(Node));
    if(node) {
        *node = (Node){ next, data };
    }
return node;
}
// This function initializes and returns a linked list 
// and NULL upon failure. 
List* initList() {

    List *list = malloc(sizeof(List));

    if(list) {
        list->head = NULL;
        list->size = 0;
    }

    return list;
}
//Appends a node containing the data to the end of the list
int addAtEnd(List *list, int data) {

    Node* new = makeNode(data, NULL);

    if(list->size == 0) {
        list->head = new;
        ++list->size;
        return 1;
    } 
    else {
        Node* cursor = list->head;
        while(cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = new;
    }
}
// Sets the head of the list to the given node, and returns the old head
int addAtHead(List* list, int data) {
    Node* oldHead = list->head;
    Node* newHead = makeNode(data, oldHead);
    list->head = newHead;
    ++list->size;
    return 1;
}
//Checks to see if a given list reads the same forwards and backwards
void Palindrome(List* list) {
    //First we must build a reversed List
    List* inverseList = initList();
    Node* cursor = list->head;
    while(cursor) {
        addAtHead(inverseList, cursor->data);
        if(cursor == list->head) printf("%d"), cursor->data;
        else printf("->%d", cursor->data);
        cursor = cursor->next;
    }
    //Once that is complete, we will iterate through the list and check that each value is equal
    cursor = list->head;
    Node* inverseCursor = inverseList->head;
    while(cursor != NULL && inverseCursor != NULL) {
        if(cursor->data != inverseCursor->data) { 
            printf(" is not a palindrome."); 
            return;
        }
        cursor = cursor->next;
        inverseCursor= inverseCursor->next;
    }
    printf(" is a palindrome!");
    return;
}


/*
###################  Question 2  ###################
Issue 1:
    By squaring a negative number, it becomes positive.
    This array stores both negative and positive integers
    which means there will be a collision for each integer
    of the same absolute value.
Solution: 
    Split the array into a two dimensional version that has
    2500 spaces each. Place positive elements in Hash[][0]
    and negative elements in Hash[][1]

    
Issue 2:
    Implementing an array that indexes according to the square of
    it's values would have to be needlessly large or require
    very complicated memory allocation. For example, 4 would index 
    at 16 while 4507 is at index 20,313,049.
Solution:
    A better hash function in my opinion would be the multiplication
    method using ( sqrt(5) - 1 ) / 2 as our constant to receive the
    fraction and scaling up from there. We would still take the
    negative/positive value to decide which array to place it in.
*/


/*
###################  Question 3  ###################
Initial Array h(k) = k mod 17
|  |  |  |  |  |   |  |  |  |  |  |  |  |  |  |  |  |
0  1  2  3  4  5   6  7  8  9  10 11 12 13 14 15 16
Insert 13(13), 20(3), 30(13) --Collision  
|  |  |  |20|  |   |  |  |  |  |  |  |  |vv|  |  |  |
                                        13
                                        vv
                                        30
                                    Collision Managed

Insert 80(12), 74(6),92(7), 124(5), and 32(15)
|  |  |  |20|  |124|74|92|  |  |  |  |80|vv|  |32|  |
                                         13
                                         vv
                                         30

Insert 59(7) --Collision
|  |  |  |20|  |124|74|vv|  |  |  |  |80|vv|  |32|  |
                       92                13
                       vv                vv
                       59                30
                Collision Managed 

Insert 53(2), 393(2) --Collision
|  |  |vv|20|  |124|74|vv|  |  |  |  |80|vv|  |32|  |
       53              92                13
       vv              vv                vv
      393              59                30
Collision Managed

Insert 210(6)--Collision
|  |  |vv|20|  |124|vv|vv|  |  |  |  |80|vv|  |32|  |
       53           74 92                13
       vv           vv vv                vv
      393          210 59                30
Collision Managed

Insert 22(5) --Collision Insert 104(2) --Collision
|  |  |vv|20|  |124|vv|vv|  |  |  |  |80|vv|  |32|  |
       53        vv 74 92                13
       vv        22 vv vv                vv
      393          210 59                30
       vv
      104
Collisions Managed

Final Array:
|  |  |vv|20|  |124|vv|vv|  |  |  |  |80|vv|  |32|  |
       53        vv 74 92                13
       vv        22 vv vv                vv
      393          210 59                30
       vv
      104
*/

/*
###################  Question 4  ###################
    500 is at index 2.
    501 is at index 81.
    502 is at index 32.
    503 is at index 111.
    504 is at index 62.
    505 is at index 13.
    356 is also at index 2. Given the rarity of collisions
    with this hash function I believe the best method would
    be chaining values because whatever collisions do happen
    will be spread apart and thus won't stack up easily in one
    slot. At index 2 I would input a pointer to a struct
    that contained 500 and a ptr to the next struct, holding 356.
*/

/*
###################  Question 5  ###################
    Open Address Hash table
    i = 0
    h(k, i) = ((k mod 13) + i * (1 + (k mod 11)) mod 13 )
    |  |  |  |  |   |  |  |  |  |  |   |  |  |
    0  1  2  3  4   5  6  7  8  9  10  11 12 
    Insert 35(9), 41(2), 50(11), 9(9) --Collision Detected 26(), 54(), 27(), 0(), 100(), 200()
    |  |  |41|  |   |  |  |  |  |35|   |50|  |
     
    i = 1
    9(6), 26(5), 54(0), 27(7), 0(1), 100(11) --Collision Detected 200()
    |54| 0|41|  |   |26| 9|27|  |35|   |50|  |

    i = 2
    100(0) --Collision Detected
    i = 3
    100(2) --Collision Detected
    i = 4
    100(4), 200(4) --Collision Detected
    |54| 0|41|  |100|26| 9|27|  |35|   |50|  |

    i = 5
    200(7) --Collision Detected
    i = 6
    200(10)
    |54| 0|41|  |100|26| 9|27|  |35|200|50|  | 
    Numbers have been inserted.
*/