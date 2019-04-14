#ifndef QUEUE_H_
#define QUEUE_H_

#define MAX_LENGTH_FIFO_NAME 32
#define MAX_LENGTH_BURSTS 5

#include <stdio.h>
#include <stdlib.h>

typedef struct client //define the client struct (for client TO server)
{
	int bursts[MAX_LENGTH_BURSTS];
	char privateFIFOName[MAX_LENGTH_FIFO_NAME];
} PCB;

typedef struct server //define the server struct (for server TO client)
{
	int clock;
} S_PCB;

typedef struct client Object;  /*Datatype of the elements in the queue*/

typedef struct node
{  /*Nodes stored in the linked list*/

	Object element;

	struct node *next;

} Node;

typedef struct queue /*A struct facilitates passing a queue as an argument*/
{
	Node *head;       /*Pointer to the first node holding the queue's data*/

	Node *tail;       /*Pointer to the last node holding the queue's data*/

	int sz;           /*Number of nodes in the queue*/

} Queue;

int size(Queue *Q);
int isEmpty(Queue *Q);
void enqueue(Queue *Q, Object elem);
Object dequeue(Queue *Q);
Object first(Queue *Q);
Object last(Queue *Q);
void destroyQueue(Queue *Q);
void visitChar(Object elem);
void visitStruct(Object elem);
void traverseQueue(Queue *Q, void (*visit)(Object elem));

#endif
