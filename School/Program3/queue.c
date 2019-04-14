/**
 *FILENAME: queue.c

 *PURPOSE: Implements a simple queue data structure using C.

 *         This queue's data is stored in a linked list.

 *         Since the queue is passed to the functions as an argument,

 *         a program can have many different queues.

 *         This queue can be traversed with the traverseQueue function,

 *         however the visit function must be different for each

 *         different datatype stored in the queue.

 *DATE: 16-Apr-2005

 *PROGRAMMER: Charles Moen
 
 *DATE: 5-Nov-2017
 
 *PROGRAMMER: Ethan Hann

 */

#include "queue.h"

int size(Queue *Q)
{
	return Q->sz;
}

int isEmpty(Queue *Q)
{
	if( Q->sz == 0 )
	{
		return 1;
	}
	return 0;
}

void enqueue(Queue *Q, Object elem)
{
	Node *v = (Node*)malloc(sizeof(Node));/*Allocate memory for the Node*/

	if( !v )
	{
		printf("ERROR: Insufficient memory\n");
		return;
	}

	v->element = elem;
	v->next = NULL;

	if (isEmpty(Q))
	{
		Q->head = v;
	}
	
	else
	{
		Q->tail->next = v;
	}
	
	Q->tail = v;
	Q->sz++;
}

Object dequeue(Queue *Q)
{
	Node *oldHead;
	Object temp;
	
	if (isEmpty(Q))
	{

		printf("ERROR: Queue is empty\n");
		return temp;

	}
	
	oldHead = Q->head;
	temp = Q->head->element;
	Q->head = Q->head->next;
	free(oldHead);
	Q->sz--;
	
	return temp;
}

Object first(Queue *Q)
{
	if (isEmpty(Q))
	{
		printf("ERROR: Queue is empty\n");
		return Q->head->element;
	}
	return Q->head->element;
}

Object last(Queue *Q)
{
	if (isEmpty(Q))
	{
		printf("ERROR: Queue is empty.\n");
		return Q->tail->element;
	}
	return Q->tail->element;
}

void destroyQueue(Queue *Q)
{
	while(!isEmpty(Q)) dequeue(Q);
}

/*A different visit function must be used for each different datatype.
The name of the appropriate visit function is passed as an argument
to traverseQueue.*/
void visitStruct(Object elem)
{
	printf("%d\t%d\t\t%s", elem.burst, elem.arrivalTime, elem.privateFIFOName);
	printf("\n");
}

/*The following function isn't part of the Queue ADT, however
it can be useful for debugging.*/
void traverseQueue(Queue *Q, void (*visit)(Object elem)){

	Node *current = Q->head;

	while(current)
	{
		visit(current->element);
		current = current->next;
	}
	printf("\n");
}
