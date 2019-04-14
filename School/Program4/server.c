/*****************************************************************************
* Programmer: Ethan Hann                                                     *
*                                                                            *
* Course: CSCI 4534                                                          *
*                                                                            *
* Date: November 17, 2017                                                    *
*                                                                            *
* Assignment: Programming Assignment #4: Round Robin CPU Scheduler w/ IO     *
*                                                                            *
* Environment: Notepad++ & Sapphire UNIX Server                              *
*                                                                            *
* Files Included: server.c, queue.c, queue.h, s_func.c, s_func.h             *
*                                                                            *
* Purpose: To simulate a short-term round robin CPU and IO scheduler using   *
*          a server and multiple clients                                     *
*                                                                            *
* Input: From clients: an array of integer representing alternating CPU and  *
*                      IO bursts; privateFIFOName of client                  *
*                                                                            *

*/
#include "s_func.h"
#include "queue.h"

int main()
{
	struct client CPUcurrent; //bursts array, privateFIFOName
	struct client IOcurrent; //bursts array, privateFIFOName
	struct client current; //bursts array, privateFIFOName
	
	struct server complete; //clock value at completion time
	
	
	memset(&CPUcurrent.bursts, 0, sizeof(CPUcurrent.bursts));
	memset(&IOcurrent.bursts, 0, sizeof(IOcurrent.bursts));
	memset(&complete.clock, 0, sizeof(complete.clock));
	
	int l;
	for (l = 0; l < MAX_LENGTH_BURSTS; l++)
	{
		printf("%d\t", CPUcurrent.bursts[l]);
	}
	
	Queue ready;
	Queue wait;
	
	ready.head = NULL;
	ready.tail = NULL;
	ready.sz = 0;
	
	wait.head = NULL;
	wait.tail = NULL;
	wait.sz = 0;

	char message1[] = "SERVER:> Enter the number of clients\n";
	char message2[] = "SERVER:> The number of clients should be in between 3 and 32 and should be an integer value.\n";
	char message3[] = "SERVER:> Enter the time quantum\n";
	char message4[] = "SERVER:> The time quantum should be in between 1 and 64 and should be an integer.\n";
	
	int fdIn = 0;
	int fdOut = 0;
	int numOfClients = getInput(message1, message2, 0);
	int timeQuant = getInput(message3, message4, 1);
	int totalTime = 0;
	
	int *finish;
	finish = (int *)malloc(sizeof(int));
	
	//Getting client input
	int i;
	int j;
	for (i = 0; i < numOfClients; i++)
	{
		createCommonFIFO();
		printf("\n");
		printf("SERVER:> Waiting on client . . .\n\n");
		openCommonFIFO(&fdIn);
		
		*finish = read(fdIn, &CPUcurrent, sizeof(CPUcurrent));
		
		createPrivateFIFO(CPUcurrent);
		
		if (size(&ready) > 0)
		{
			printf("Clients in READY State\n");
			printf("====================================\n");
			printf("Burst\tFIFO Name\n");
			traverseQueue(&ready, visitStruct);
		}
		
		if (*finish == -1)
		{
			perror("SERVER:> Could not read data from client! Exiting . . .");
			exit(-1);
		}
		
		for (j = 0; i < MAX_LENGTH_BURSTS; i++)
		{
			totalTime += CPUcurrent.bursts[i];
			printf("Burst: %d\n", CPUcurrent.bursts[i]);
		}

		enqueue(&ready, CPUcurrent); //enqueue the current client's PCB to the ready queue
		closeCommonFIFO(&fdIn);
	}
	free(finish);
	
	
	int CPUclock = 0;
	int IOclock = 0;
	int isDone = 0;
	while (isDone == 0)
	{
		CPUcurrent = first(&ready);
		//IOcurrent = first(&wait);
		
		int i;
		for (i = 0; i < MAX_LENGTH_BURSTS; i++)
		{
			if (CPUcurrent.bursts[i] == 0)
			{
				printf("test\n");
				dequeue(&ready);
				enqueue(&wait, CPUcurrent);
			}
			else
			{
				if (CPUcurrent.bursts[i] < timeQuant)
				{
					printf("test2\n");
					CPUclock += CPUcurrent.bursts[i];
					CPUcurrent.bursts[i] = 0;
					printf("Client %s completed CPU burst at time %d\n\n", CPUcurrent.privateFIFOName, CPUclock);
				}
				else
				{
					printf("test3\n");
					CPUclock += timeQuant;
					CPUcurrent.bursts[i] -= timeQuant;
					dequeue(&ready);
					enqueue(&wait, CPUcurrent);
				}
			}
		}
		
		if (size(&ready) > 0)
		{
			printf("Clients in READY State\n");
			printf("====================================\n");
			printf("Burst\tFIFO Name\n");
			traverseQueue(&ready, visitStruct);
		}
		
		if (size(&wait) > 0)
		{
			printf("Clients in WAIT State\n");
			printf("====================================\n");
			printf("Burst\tFIFO Name\n");
			traverseQueue(&wait, visitStruct);
		}
		
		printf("CPU Clock: %d", CPUclock);
		//processCPU();
		//processIO();
	}
	
	return 0;
}

void processCPU(int *CPUclock)
{
	
}

void processIO(int *IOclock)
{
	
}
