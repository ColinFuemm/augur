#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;

// Complexity: O(1)
Queue* initPQ();
// Complexity: O(n)
void freePQ(Queue *pq);

/* Priority:
 *	In an ascending priority queue, the "maximum" element is the next to dequeue,
 *	whereas in a descending priority queue, the "minimum" element is next.
 */

 #define SECT_F
 typedef struct {
 	unsigned long accountNumber;
 	float accountWorth;
 	int daysActive;
 } Client;

 // Complexity: O(n)
 int insertClientDescendingPQ(Queue *pq, Client *client);
 // Complexity: O(1)
 Client* peekMinClient(Queue *pq);
 // Complexity: O(1)
 Client* deQueueMinClient(Queue *pq);

 void printClients(Queue *list);
 int getSizePQ(Queue* q);
