/*
SEE server.c FOR PREFACE
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#define FRAMESIZE 256.0f //value is used to calculate how much of a frame is fragmented; should be changed to match the server value if the server FRAMESIZE is different
#define MAX_NUM_FRAMES 256
#define MAX_LENGTH_FIFO_NAME 16
#define MAX_LENGTH_JOB_NAME 32
#define MAX_LENGTH_MESSAGE 256

int main(void)
{
	struct 
	{
		char message[MAX_LENGTH_MESSAGE];
		int fragmentation;
		int totalNumOfFrames;
		int frameNumbers[MAX_NUM_FRAMES];
	} input;
	
	struct
	{
		char jobName[MAX_LENGTH_JOB_NAME];
		char privateFIFOName[MAX_LENGTH_FIFO_NAME];
		int memoryRequest;
	} output;
	
	int clientID = getpid(); //get a unique process ID for private FIFO name
	int fdIn = 0; //file descriptor in (to read from server)
	int fdOut = 0; //file descriptor out (to write to server)
	int i = 0; //loop control variable (for printing the frames allocated to this client)
	
	sprintf(output.privateFIFOName, "F_%d", clientID); //create a unique private FIFO name
	
	//Prompting for job name and memory request. No error checking is needed here because the server handles any errors that could come up
	printf("CLIENT:> Enter the job name (32 characters or less)\n");
	printf("USER:> ");
	scanf("%s", &output.jobName);
	
	printf("CLIENT:> Enter the memory request\n");
	printf("USER:> ");
	scanf("%d", &output.memoryRequest);
	printf("\n");
	
	sleep(0.2);
	if ((fdOut = open("CommonFIFO", O_WRONLY)) < 0) //if the CommonFIFO could not be opened, print an error message
	{
		perror("Can't open common FIFO to write to server!\n");
		exit(-1);
	}
	else //if the CommonFIFO could be opened, write the output struct to the server
	{
		write(fdOut, &output, sizeof(output));
	}
	
	sleep(1); //sleep for 1 second so the server has time to create the privateFIFO before the client tries to open it
	if ((fdIn = open(output.privateFIFOName, O_RDONLY)) < 0) //if the privateFIFO could not be opened, print an error message
	{
		perror("Can't open private FIFO to read from the server!\n");
		exit(-1);
	}
	else
	{
		sleep(0.5); //sleep for 0.5 seconds so the server has time to do the calculations with the input data
		read(fdIn, &input, sizeof(input)); //read the input struct from the server
	}
	
	printf("CLIENT:> Name: %s\n", output.privateFIFOName);

	//if the calculated fragmentation is -1, this means that something went wrong. Print the message recieved from the server to indicate error
	if (input.fragmentation == -1)
	{
		printf("\a");
		printf(input.message);
	}
	else //if nothing went wrong, display to the user the amount of fragmentation and the percentage (to 2 decimal places) of a frame that is fragmented
	{
		printf("CLIENT:> Fragmentation amount: %d memory units (%.2f%% of a frame)\n\n", input.fragmentation, ((input.fragmentation / FRAMESIZE) * 100.0f));
		printf("CLIENT:> The frames that have been allocated for your job are marked with an 'A'.\n\n");
	
		//display the frames that have been allocated to the client's job
		for (i; i < input.totalNumOfFrames; i++)
		{
			printf("%d\t", i);
		}
		
		printf("\n");
		
		i = 0;
		for (i; i < input.totalNumOfFrames; i++)
		{
			if (input.frameNumbers[i] == 1) //if the value at index 'i' is a 1, this means that frame has been allocated for this job
			{
				printf("A\t");
			}
			else
			{
				printf("\t");
			}
		}
		
		printf("\n\n");
		
		i = 0;
		for (i; i < input.totalNumOfFrames; i++)
		{
			if (input.frameNumbers[i] == 1)
			{
				printf("CLIENT:> Allocated Frame: %d\n", i);
			}
		}
	}
	
	printf("\n\n");
	
	close(fdIn);
	close(fdOut);
	unlink("CommonFIFO");
	unlink(output.privateFIFOName);
	return 0;
}
