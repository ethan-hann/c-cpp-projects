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
* Files Included: client.c, c_func.h, c_func.c                               *
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
* Algorithm:                                                				 *
*            Define struct for output to server                              *
*            Define struct for input from server                             *
*            Get burst value and arrival time from user                      *
*            Assign struct values to input values from user                  *
*            Open commonFIFO for writing                                     *
*            Write the struct defined above to the commonFIFO                *
*            Open privateFIFO for reading                                    *
*            Read output from server from privateFIFO into input struct      *
*            Display the results from the server to the user nicely          *
*            Close privateFIFO                                               *
*            Close commonFIFO                                                *
*            END CLIENT                                                      *
*****************************************************************************/

#include "c_func.h"

int main(void)
{
	struct client output = {0, 0, ""};
	struct server input = {0, 0};
	char message1[] = "CLIENT:> Enter the burst time\n";
	char message2[] = "CLIENT:> Burst time should be in between 1 and 128 and should be an integer.\n";
	char message3[] = "CLIENT:> Enter the arrival time\n";
	char message4[] = "Arrival Time should be in between 1 and 128 and should be an integer.\n";
	
	int clientID = getpid();
	int fdIn = 0;
	int fdOut = 0;
	
	sprintf(output.privateFIFOName, "F_%d", clientID);
	output.burst = getInput(message1, message2);
	output.arrivalTime = getInput(message3, message4);
	
	openCommonFIFO(&fdOut);
	write(fdOut, &output, sizeof(output));
	sleep(1);
	openPrivateFIFO(&fdIn, output.privateFIFOName);
	read(fdIn, &input, sizeof(input));
	
	printf("Data for Client %s\n", output.privateFIFOName);
	printf("====================================\n");
	printf("Clock Value\tTurnaround Time\n");
	printf("%d\t\t%d", input.clock, input.turnAroundTime);
	
}
