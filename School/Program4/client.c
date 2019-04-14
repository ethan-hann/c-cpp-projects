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
* Files Included: client.c, c_func.h, c_func.c                               *
*                                                                            *
* Purpose: To simulate a short-term round robin CPU and IO scheduler using   *
*          a server and multiple clients                                     *
*/

#include "c_func.h"

int main(void)
{
	struct client output;
	struct server input;
	char message1[] = "CLIENT:> Enter alternating CPU and IO bursts (MAX OF 5).\nInput must start and end with a CPU burst.\n";
	char message2[] = "CLIENT:> The burst should be a positive integer between 1 and 128.\n";
	
	int clientID = getpid();
	int fdIn = 0;
	int fdOut = 0;
	
	sprintf(output.privateFIFOName, "F_%d", clientID);
	getInput(message1, message2, output.bursts); //get bursts from user and store in output struct
	
	openCommonFIFO(&fdOut);
	write(fdOut, &output, sizeof(output));
	sleep(1);
	openPrivateFIFO(&fdIn, output.privateFIFOName);
	read(fdIn, &input, sizeof(input));
	
	printf("Data for Client %s\n", output.privateFIFOName);
	printf("====================================\n");
	printf("Finished at Clock Value: %d", input.clock);
}
