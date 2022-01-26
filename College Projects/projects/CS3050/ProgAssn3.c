#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node {
	Node *next;
	int data;
    Node *parent;
    Node *up;
    Node *down;
    char color;
};

typedef struct {
	Node *head;
    Node *tail;
	int size;
} List;

List* initList();
void insertAtHead(List *list, Node *newHead);
void insertAtTail(List *list, Node *newTail);
Node* removeHead(List *list);
Node* makeNode(Node *next, int data, Node *parent, Node *up, Node *down, char color);
void ElevatorSearch(int floors, int start, int end, int up, int down);
void VictoryPath(Node* node);
void BuildSkyscraper(int floors, Node* node, int up, int down);

int main() {
    ElevatorSearch(100, 3, 10, 2, 1);
}

//Prerequisite Functions
List* initList() {
	List *list = malloc(sizeof(List));
	if(list) {
		*list = (List){ NULL, 0 };
	}
	return list;
}
void insertAtHead(List *list, Node *newHead) {
	newHead->next = list->head;
	list->head = newHead;
    list->size++;
    if(list->size == 1) { list->tail = newHead; }
}
void insertAtTail(List *list, Node *newTail) {
    list->tail->next = newTail;
    list->tail = newTail;
    list->size++;
    if(list->size == 1) { list->head = newTail; }
}
Node* removeHead(List *list) {
    if(list->size > 0) {
        Node* temp = list->head;
        list->head = temp->next;
        list->size--;
        if(list->size == 0) { list->tail = NULL; }
        return temp;
    }
}
Node* makeNode(Node *next, int data, Node *parent, Node *up, Node *down, char color) {
    Node *node = malloc(sizeof(Node));
	if(node) {
		*node = (Node){ next, data, parent, up, down, color };
	}
	return node;
}
void BuildSkyscraper(int floors, Node* node, int up, int down) {
    int UP = node->data + up;
    int DOWN = node->data -down;
    if(UP <= floors) {
        Node* lift = makeNode(NULL, UP, node, NULL, node, 'w');
        node->up = lift;
        BuildSkyscraper(floors, lift, up, down);
    }
    if(DOWN >= 0) {
        Node* lower = makeNode(NULL, DOWN, node, node, NULL, 'w');
        node->down = lower;
        BuildSkyscraper(floors, lower, up, down);
    }
}
void VictoryPath(Node* node) {
    Node* temp = node;
    List* finalists = initList();
    while(temp != NULL) {
        node = temp;
        insertAtHead(finalists, node);
        temp = node->parent;
    }
    Node* cursor = finalists->head;
    printf("%d", cursor->data);
    cursor->next;
    while(cursor) {
        printf("->%d", cursor->data);
        cursor = cursor->next;
    }
}
void ElevatorSearch(int floors, int start, int end, int up, int down) {
    Node* Start = makeNode(NULL, start, NULL, NULL, NULL, 'g');
    BuildSkyscraper(floors, Start, up, down);
    List* Queue = initList();
    insertAtHead(Queue, Start);
    while(Queue->size > 0) {
        Node* Cursor = removeHead(Queue);
        if(Cursor->data == end) {
            VictoryPath(Cursor);
            return;
        }
        if(Cursor->up != NULL) {
            if(Cursor->up->color == 'w') {
                Cursor->up->color = 'g';
                Cursor->up->parent = Cursor;
                insertAtTail(Queue, Cursor->up);
            }
        }
        if(Cursor->down != NULL) {
            if(Cursor->down->color == 'w') {
                Cursor->down->color = 'g';
                Cursor->down->parent = Cursor;
                insertAtTail(Queue, Cursor->down);
            }
        }
        Cursor->color = 'b';
    }
    printf("use the stairs");
}