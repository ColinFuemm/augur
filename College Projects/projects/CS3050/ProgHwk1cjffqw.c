#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hash_size 10

typedef struct Node Node;
typedef struct friendList friendList;

struct friendList {
    char key[100];
    friendList* next;
    friendList* prev;
};

struct Node {
	char key[100];
    friendList* friends;
    Node *next;
};

typedef struct {
    Node *head;
} List;

typedef struct {
	List *entry[hash_size];
} hashtable;

hashtable* newTable();
List* initList();
int simpleHash(char s[100]);
void printList(List * a);
void printHash(hashtable* table);
void appendHead(List* list, Node* append);
Node* search(hashtable* table, char key[100]);
Node* makeNode(char key[100]);
void addFriend(Node * user, char key[100]);
int searchFriends(Node * user, char key[100]);
void removeFriend(Node *user, char key[100]);
void P(hashtable* table, char key[100]);
void F(hashtable* table, char first[100], char second[100]);
void Q(hashtable* table, char first[100], char second[100]);
void L(hashtable* table, char key[100]);
void U(hashtable* table, char first[100], char second[100]);
void X(hashtable* table);


int main() {
    hashtable* test = newTable();
    P(test, "Sam");
    P(test, "Lisa");
    P(test, "Mark");
    P(test, "Amy");
    printHash(test);
    F(test, "Lisa", "Amy");
    F(test, "Lisa", "Mark");
    F(test, "Amy", "Sam");
    Q(test, "Mark", "Lisa");
    Q(test, "Amy", "Lisa");
    Q(test, "Mark", "Amy");
    L(test, "Lisa");
    U(test, "Lisa", "Amy");
    Q(test, "Amy", "Lisa");
    L(test, "Lisa");
    X(test);
}

void P(hashtable* table, char key[100]) {
    int index = simpleHash(key);
    List* list = table->entry[index];
    if(list->head == NULL) {
        //no collision
        Node* node = makeNode(key);
        table->entry[index]->head = node;
        return;
    }
    else {
        //collision
        Node *a = list->head;
        while (a != NULL) {
            a = a->next;
            if(a == NULL) {
                Node* node = makeNode(key);
                appendHead(table->entry[index], node); 
            }
            else {
                if(strcmp(a->key, key) == 0) break;
            } //if they're the same
        }
    }
}

void L(hashtable* table, char key[100]) {
    Node* node = search(table, key);
    if (node == NULL) {
        printf("Error: %s not found.", key);
        return;
    }
    friendList* cursor = node->friends;
    while(cursor != NULL) {
        printf("%s ", cursor->key);
        cursor = cursor->next;
    }
    printf("\n");
    return;
}
void F(hashtable* table, char first[100], char second[100]) {
    //Initialization & Error Checking
    Node* Friend1 = search(table, first);
    if (Friend1 == NULL) {
        printf("Error: %s not found.\n", first);
        return;
    }

    Node* Friend2 = search(table, second);
    if (Friend2 == NULL) {
        printf("Error: %s not found.\n", second);
        return;
    } 

    //First adds second to friends
    if(searchFriends(Friend1, second) == 1) {
        addFriend(Friend1, second);
    }
    //Second adds first to friends
    if(searchFriends(Friend2, first) == 1) {
        addFriend(Friend2, first);
    }
}
void U(hashtable* table, char first[100], char second[100]) {
    Node* Friend1 = search(table, first);
    if (Friend1 == NULL) {
        printf("Error: %s not found.\n", first);
        return;
    }

    Node* Friend2 = search(table, second);
    if (Friend2 == NULL) {
        printf("Error: %s not found.\n", second);
        return;
    }

    //First adds second to friends
    if(searchFriends(Friend1, second) == 0) {
        removeFriend(Friend1, second);
    }
    //Second adds first to friends
    if(searchFriends(Friend2, first) == 0) {
        removeFriend(Friend2, first);
    }
}
//searches table for name and returns node profile, NULL on fail
Node* search(hashtable* table, char key[100]) { //checkpoint, review search return values
    int index = simpleHash(key);
    Node* cursor = table->entry[index]->head;
    while (cursor != NULL) {
        if(strcmp(cursor->key, key) == 0) { //if they're the same string
            break;
        }
        cursor = cursor->next;
    }
    return cursor;
}
//Q checks if two people are friends by retrieving
//the first person's profile & then cycling through
//their friend list to see if the second name matches the entries.
//prints the result
void Q(hashtable* table, char first[100], char second[100]) {
    Node* node = search(table, first);
    int index = simpleHash(second);
    if (node == NULL) {
         printf("Error: %s not found.", first);
         return;
    }
    //at this point 'node' should be the first name's container
    if(searchFriends(node, second) == 0) {
        printf("%s and %s are friends.\n", first, second);
    }
    else {
        printf("%s and %s are not friends.\n", first, second);
    }
    return;
}
int simpleHash(char s[100]) {
    int i = 0;
    int hash = 0;
    while (i < 100 && s[i] != '\0') {
        hash = (hash + (s[i]%128))%hash_size;
        i++;
    }
    return hash; 
}

void printList(List * a) {
    if (a->head == NULL) {
        printf("[ ]\n");
        return;
    }
    Node * cursor = a->head;
    printf("[(%s)", cursor->key);
    cursor = cursor->next;
    while (cursor != NULL) {
        printf(", (%s)", cursor->key);
        cursor = cursor->next;
    }
    printf("]\n");
}

void printHash(hashtable* table) {
    for (int i = 0; i < hash_size; i++) {
        printList(table->entry[i]);
    }
    return;
}

void appendHead(List* list, Node* append) {
    if(append->next == NULL) {
        append->next = list->head;
        list->head = append;
    }
}

hashtable* newTable() {
    hashtable* h = malloc(sizeof(hashtable));
    for (int i = 0; i < hash_size; i++) {
        h->entry[i] = initList();
    }
    return h;
}

List* initList() {
	List *list = malloc(sizeof(List));
	if(list) {
        list->head = NULL;
	}
	return list;
}

int searchFriends(Node * user, char key[100]) {
    friendList *cursor = user->friends;
    while(cursor != NULL) {
        if (strcmp(cursor->key, key) == 0) {
            return 0;
        }
        else { 
            cursor = cursor->next; 
        }
    }
    return 1; //failure
}

void addFriend(Node * user, char key[100]) {
    friendList * new = malloc(sizeof(friendList));
    strcpy(new->key, key);
    new->prev = NULL;
    new->next = user->friends;
    if(user->friends != NULL) { user->friends->prev = new; }
    user->friends = new;
}

void removeFriend(Node *user, char key[100]) {
    friendList *cursor = user->friends;
    while(cursor != NULL) {
        if (strcmp(cursor->key, key) == 0) {
            if(cursor->prev == NULL) {
                if(cursor->next == NULL) {
                    user->friends = NULL;
                    cursor = NULL;
                }
                else {
                    cursor->next->prev = NULL;
                    user->friends = cursor->next;
                    cursor = NULL;
                }
            }
            else {
                if(cursor->next == NULL) {
                    cursor->prev->next = NULL;
                    cursor = NULL;
                }
                else {
                    friendList* temp = cursor->prev;
                    cursor->next->prev = temp;
                    temp->next = cursor->next;
                    cursor = NULL;
                }
            }

            
        }
        else { 
            cursor = cursor->next; 
        }
    }
}

Node* makeNode(char key[100]) {
    Node *node = malloc(sizeof(Node));
    if(node) {
        strcpy(node->key, key);
        node->next = NULL;
        node->friends = NULL;
    }
}

void X(hashtable* table) {
    Node* cursor;
    friendList* fcursor;
    for (int i = 0; i < hash_size; i++) {
        free(table->entry[i]);
    }
    free(table);
    printf("Memory Freed. End of Program.\n");
}