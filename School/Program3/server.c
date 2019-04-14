/*****************************************************************************
* Programmer: Ethan Hann                                                     *
*                                                                            *
* Course: CSCI 4534                                                          *
*                                                                            *
* Date: October 31, 2017                                                     *
*                                                                            *
* Assignment: Programming Assignment #3: Round Robin CPU Scheduler           *
*                                                                            *
* Environment: Notepad++ & Sapphire UNIX Server                              *
*                                                                            *
* Files Included: server.c, queue.c, queue.h, s_func.c, s_func.h             *
*                                                                            *
* Purpose: To simulate a short-term round robin CPU scheduler using a server *
*          and multiple clients                                              *
*                                                                            *
* Input: From clients to server: an integer named burst, the name of its     *
*        private FIFO, and arrival time                                      *
*        From server: the number of clients and an integer named timeQuant   *
*                                                                            *
* Preconditions: Arrival times may be given in increasing order              *
*                                                                            *
* Output: To each client: after burst is completed, the value in the "clock" *
*         and a turnaround time                                              *
*         On server: the ready queue (periodically), the client's completion *
*         time, when all clients are done report the average turnaround time *
*                                                                            *
* Postconditions: None                                                       *
*                                                                            *
* Estimated Time: 3 days                                                     *
*                                                                            *
* Actual Time: 3.5 days                                                      *
*                                                                            *
* Algorithm:                                                                 *
*            Define a struct for input from client                           *
*            Define a struct for output to client                            *
*            Create commonFIFO                                               *
*            Open commonFIFO for reading                                     *
*            Ask user for number of clients and timeQuant                    *
*            For (each client):                                              *
*                Read from the commonFIFO                                    *
*                Create a node for client                                    *
*                Enqueue to a queue name Ready                               *
*            End For.                                                        *
*            Create privateFIFO                                              *
*            Open privateFIFO for writing                                    *
*            Subtract timeQuant from burst for each client                   *
*            Dequeue client and place at end of queue if burst is complete   *
*                or timeQuant is complete                                    *
*            When clients burst is completed                                 *
*                Output clock value and turnaround time for client           *
*                to clients private FIFO; output completed time on server    *
*            When all clients are done, output average turnaround time       *
*            END SERVER                                                      *
*****************************************************************************/

#include "s_func.h"
#include "queue.h"

int main()
{
	Queue ready;
	ready.head = NULL;
	ready.tail = NULL;
	ready.sz = 0;
	
	char message1[] = "SERVER:> Enter the number of clients\n";
	char message2[] = "SERVER:> The number of clients should be in between 3 and 32 and should be an integer value.\n";
	char message3[] = "SERVER:> Enter the time quantum\n";
	char message4[] = "SERVER:> The time quantum should be in between 1 and 64 and should be an integer.\n";
	
	int fdIn = 0;
	int fdOut = 0;
	int numOfClients = getInput(message1, message2, 0);
	int timeQuant = getInput(message3, message4, 1);
	int totalTime = 0;
	float averageTurnaround = 0.0;
	
	int i;
	
	int *finish;
	finish = (int *)malloc(sizeof(int));
	struct client current = {0, 0, "CURRENT"}; //burst, arrivalTime, and privateFIFOName
	struct server complete = {0, 0}; //clock and turnAroundTime
	
	for (i = 0; i < numOfClients; i++)
	{
		createCommonFIFO();
		printf("\n");
		printf("SERVER:> Waiting on client . . .\n\n");
		openCommonFIFO(&fdIn);
		
		*finish = read(fdIn, &current, sizeof(current));
		createPrivateFIFO(current);
		
		if (*finish == -1)
		{
			perror("SERVER:> Could not read data from client! Exiting . . .");
			exit(-1);
		}
		
		//current.arrivalTime = i;
		totalTime += current.burst;
		
		enqueue(&ready, current); //enqueue the current client's PCB to the ready queue
		closeCommonFIFO(&fdIn);
	}
	free(finish);
	struct client sFirst = first(&ready);
	
	int clock = sFirst.arrivalTime;
	int done = 0;
	while (done == 0)
	{
		printf("Clock Value: %d\n", clock);
		current = first(&ready);
		if (current.burst < timeQuant)
		{
			clock += current.burst;
			openPrivateFIFO(&fdOut, current); //open this client's FIFO
			current.burst = 0;
			complete.clock = clock; //the process is done and the 'clock' value is recorded
			complete.turnAroundTime = clock - current.arrivalTime;
			averageTurnaround += complete.turnAroundTime;
			dequeue(&ready);
			write(fdOut, &complete, sizeof(complete)); //write the completed struct to client
			printf("Client %s completed at time: %d\n\n", current.privateFIFOName, clock);
		}
		else
		{
			clock += timeQuant;
			current.burst -= timeQuant;
			dequeue(&ready);
			enqueue(&ready, current);
		}
		
		if (size(&ready) > 0)
		{
			printf("Clients in Ready State\n");
			printf("====================================\n");
			printf("Burst\tArrival Time\tFIFO Name\n");
			traverseQueue(&ready, visitStruct);
		}
		else
		{
			done = 1; //when queue is empty, all clients have been processed
		}
	}
	
	printf("Average Turnaround Time for %d clients is: %.2f\n", numOfClients, averageTurnaround / numOfClients);
	printf("SERVER:> Shutting down . . .\n\n");
	
	return 0;
}
