/*****************************************************************************
* Programmer: Ethan Hann                                                     *
*                                                                            *
* Course: CSCI 4534                                                          *
*                                                                            *
* Date: October 15, 2017                                                     *
*                                                                            *
* Assignment: Programming Assignment #2: Client/Server Memory Manager        *
*                                                                            *
* Environment: Notepad++ & Sapphire UNIX Server                              *
*                                                                            *
* Files Included: server.c & client.c                                        *
*                                                                            *
* Purpose: To simulate a memory manager on a server that uses paging as its  *
*          memory allocation scheme                                          *
*                                                                            *
* Input: From 'x' number of clients: the name of one job and its memory      *
*        request size; From server: the number of clients and the initial    *
*        size of memory in terms of frames                                   *
*                                                                            *
* Preconditions: All pages and frames are of size 256; main memory consists  *
*                of at least 12 frames; there are at least 3 clients         *
*                                                                            *
* Output: To each client -> the frame number(s) that the client was assigned *
*         and the amount of fragmentation generated from assignment; or an   *
*         error message if couldn't assign any memory                        *
*         Server output -> a 'map' showing the allocated memory              *
*                                                                            *
* Postconditions: None                                                       *
*                                                                            *
* Algorithm: For server ->                                                   *
*            Define a struct for output                                      *
*            Create commonFIFO                                               *
*            Open commonFIFO for reading                                     *
*            Ask user for number of clients and initial size of memory       *
*            For (each client):                                              *
*                Read from the commonFIFO                                    *
*                Create clientFIFO                                           *
*                Open clientFIFO for writing                                 *
*                Calculate number of frames needed                           *
*                Calculate fragmentation                                     *
*                Mark allocated frames busy                                  *
*            End For.                                                        *
*            Output map of allocated memory                                  *
*            END SERVER                                                      *
*                                                                            *
*            For client ->                                                   *
*            Define struct for output to server                              *
*            Define struct for input from server                             *
*            Get job name and memory request from user                       *
*            Assign struct values to input values from user                  *
*            Open commonFIFO for writing                                     *
*            Write the struct defined above to the commonFIFO                *
*            Open privateFIFO for reading                                    *
*            Read output from server from privateFIFO into input struct      *
*            Display the results from the server to the user nicely          *
*            Close privateFIFO                                               *
*            END CLIENT                                                      *
*****************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>

#define FRAMESIZE 256
#define MIN_NUM_FRAMES 12
#define MAX_NUM_FRAMES 256
#define MIN_NUM_CLIENTS 3
#define MAX_NUM_CLIENTS 64
#define MAX_LENGTH_FIFO_NAME 16
#define MAX_LENGTH_JOB_NAME 32
#define MAX_LENGTH_MESSAGE 256
#define MAX_LENGTH_BUFFER 32

int checkInput(char *a, int min, int max); //function prototype

int main(void)
{
	int fdIn = 0; //file descriptor in (to read from client)
	int fdOut = 0; //file descriptor out (to write to client)
	int numOfClients = 0; //total number of clients this server will process
	int totalNumOfFrames = 0; //total number of frames in memory
	int numOfFrames = 0; //used in the frames calculation to keep track of how many allocated frames there are
	int remainder = 0; //used to calculate the fragmentation
	int framesLeft = 0; //number of frames left to be allocated
	int memoryLeft = 0; //number of memory units left that can be allocated
	int frames = 0; //copy of numOfFrames used to allocate frames for client
	int valid = 0;
	char buffer[MAX_LENGTH_BUFFER]; //buffer for 'fgets' input - used to check for valid input
	
	//Struct to recieve from client
	struct
	{
		char jobName[MAX_LENGTH_JOB_NAME];
		char privateFIFOName[MAX_LENGTH_FIFO_NAME];
		int memoryRequest;
	}input;
	
	//********************************************************************
	//Error checking for number of clients and total frames in memory
	do
	{
		memset(buffer, 0, sizeof(buffer)); //clear the input buffer
		printf("SERVER:> Enter number of clients\n");
		printf("USER:> ");
		fgets(buffer, sizeof(buffer), stdin); //read the number of clients as a string and store in the character buffer
		if (checkInput(buffer, MIN_NUM_CLIENTS, MAX_NUM_CLIENTS) == 0)
		{
			printf("\a\n");
			printf("SERVER:> The number of clients should be in between 3 and 64 and should be an integer value.\n");
			printf("SERVER:> Please try again.\n\n");
			valid = 0;
		}
		else
		{
			valid = 1;
		}
		
	} while (valid == 0); //continue this loop while the input is invalid
	
	numOfClients = atoi(buffer); //if the input was valid, assign the integer value to 'numOfClients'
	
	do
	{
		memset(buffer, 0, sizeof(buffer)); //clear the input buffer
		printf("SERVER:> Enter number of frames in memory\n");
		printf("USER:> ");
		fgets(buffer, sizeof(buffer), stdin); //read the number of frames as a string and store in the character buffer
		if (checkInput(buffer, MIN_NUM_FRAMES, MAX_NUM_FRAMES) == 0)
		{
			printf("\a\n");
			printf("SERVER:> The number of frames should be in between 12 and 256 and should be an integer value.\n");
			printf("SERVER:> Please try again.\n\n");
			valid = 0;
		}
		else
		{
			valid = 1;
		}
		
	} while (valid == 0); //continue this loop while the input is invalid
	
	totalNumOfFrames = atoi(buffer); //if the input was valid, assign the integer value to 'totalNumOfFrames'
	//********************************************************************
	
	framesLeft = totalNumOfFrames; //the frames left to be allocated; is equal to the totalNumOfFrames at start
	memoryLeft = framesLeft * FRAMESIZE; //the amount of memory units left that can be allocated
	
	//an array of "flags" that will keep track
	//whether a frame is allocated or not
	int allocatedFrames[totalNumOfFrames];
	char clientsAllocation[totalNumOfFrames][MAX_LENGTH_FIFO_NAME]; //an array of strings to keep track of what frames are allocated to what client
	
	memset(allocatedFrames, 0, sizeof(allocatedFrames)); //make sure all values in the array are set to 0 to prevent random values
	memset(clientsAllocation, 0, sizeof(clientsAllocation));
	
	//Struct to send to client containing the calculated frames and the fragmentation
	struct
	{
		char message[MAX_LENGTH_MESSAGE];
		int fragmentation;
		int totalNumOfFrames;
		int frameNumbers[totalNumOfFrames];
	}output;
	
	//Initializing struct values
	output.fragmentation = 0;
	output.totalNumOfFrames = totalNumOfFrames;
	
	//loop control variables
	int i = 0;
	int j = 0;
	
	//Main loop which processes each client
	for (i; i < numOfClients; i++)
	{
		printf("\n");
		printf("SERVER:> Waiting on client . . .\n\n");
		if ((mkfifo("CommonFIFO", 0666) < 0 && errno != EEXIST)) //if the CommonFIFO could not be created, print error message
		{
			perror("SERVER:> Can't create common FIFO!\n\n");
			exit(-1);
		}

		if ((fdIn = open("CommonFIFO", O_RDONLY)) < 0) //if the CommonFIFO could not be opened, print error message
		{
			perror("SERVER:> Can't open common FIFO to read from!\n\n");
			exit(-1);
		}
		else //if the CommonFIFO was opened successfully, wait for a client to connect to server and then read into the input struct
		{
			read(fdIn, &input, sizeof(input));
		}
		
		if ((mkfifo(input.privateFIFOName, 0666)) < 0 && errno != EEXIST) //if the privateFIFO could not be created, print error message
		{
			perror("SERVER:> Can't create private FIFO to client!\n\n");
			exit(-1);
		}
		
		if ((fdOut = open(input.privateFIFOName, O_WRONLY)) < 0) //if the privateFIFO could not be opened, print error message
		{
			perror("SERVER:> Can't open private FIFO to client!\n\n");
			exit(-1);
		}
		
		printf("SERVER:> Private FIFO: %s\n", input.privateFIFOName);
		printf("SERVER:> Job Name: %s\n", input.jobName); //print the clients job name
		printf("SERVER:> Memory Request: %d\n", input.memoryRequest); //print the clients memory request
		
		memset(output.frameNumbers, 0, sizeof(output.frameNumbers)); //make sure all values in the array are set to 0 to prevent random values
		
		//********************************************************************
		//Calculate the Frames
		//first check if the memory request is greater than the FrameSize, and less than the memory left
		//i.e. in between 256 and 3072 (for a framesize of 256 and 12 frames)
		if (input.memoryRequest >= FRAMESIZE && input.memoryRequest <= memoryLeft)
		{
			frames = 0; //resets the 'frames' variable for each client
			numOfFrames = input.memoryRequest / FRAMESIZE; //i.e. if FrameSize = 256 and memory request is 400: numOfFrames = 400 / 256 = 1
			remainder = input.memoryRequest % FRAMESIZE; //i.e. if FrameSize = 256 and memory request is 400: remainder = 144
			
			if (remainder != 0)
			{
				numOfFrames += 1; //if the remainder is not 0, we have to add another frame for the client
				output.fragmentation = FRAMESIZE - remainder; //in the case above: 256 - 144=112				
			}
			else
			{
				output.fragmentation = remainder; //if the remainder is 0, this means the requested memory fit perfectly into our frames.
			}
			
			//if the number frames left to be allocated is greater than or equal to the number of frames allocated for this client, it is a valid request
			if (framesLeft >= numOfFrames)
			{
				j = 0;
				while (frames < numOfFrames)
				{
					for (j; j < totalNumOfFrames; j++)
					{
						if (allocatedFrames[j] == 0) //if the value at j is 0, then this is an empty frame and can be allocated
						{
							allocatedFrames[j] = 1; //switch the value to 1 in both arrays
							output.frameNumbers[j] = 1;
							strcpy(clientsAllocation[j], input.privateFIFOName); //keep track of what frames this client was allocated
							break; //this breaks out of this 'for' loop which should only be run as many times as there are frames to be allocated
						}
					}
					frames++; //increment the temporary frames variable to keep track of how many times to run the for loop
				}
				
				framesLeft -= numOfFrames; //decrement the number of frames left according to the number of frames allocated to client
				memoryLeft = (framesLeft * FRAMESIZE); //decrement the amount of memory left according to the number of frames left
			}
			//if it is not a valid request, (i.e. requesting more frames than are available)
			else
			{
				printf("\a");
				fprintf(stderr, "SERVER:> Not enough available frames to allocate memory.\n\n");
				printf("SERVER:> Frames left in memory: %d\n\n", framesLeft);
				output.fragmentation = -1;
				sprintf(output.message, "CLIENT:> There was not enough memory available to satisfy your request.\n\n");
			}
		}
		
		//if it is not in between the above range, check if the requested memory is less than the framesize but greater than 0
		//i.e. in between 1 and 255 (for a framesize of 256)
		else if (input.memoryRequest < FRAMESIZE && input.memoryRequest > 0)
		{
			frames = 0;
			numOfFrames = 1; //only 1 frame is needed
			
			if (framesLeft >= numOfFrames)
			{
				j = 0;
				while (frames < numOfFrames)
				{
					for (j; j < totalNumOfFrames; j++)
					{
						if (allocatedFrames[j] == 0)
						{
							allocatedFrames[j] = 1;
							output.frameNumbers[j] = 1;
							strcpy(clientsAllocation[j], input.privateFIFOName);
							break;
						}
					}
					frames++;
				}
				output.fragmentation = FRAMESIZE - input.memoryRequest;
				
				framesLeft -= numOfFrames; //decrement the number of frames left according to the number of frames allocated to client
				memoryLeft = (framesLeft * FRAMESIZE); //decrement the amount of memory left according to the number of frames left
			}
			else
			{
				printf("\a");
				fprintf(stderr, "SERVER:> Not enough available frames to allocate memory.\n");
				printf("SERVER:> Frames left in memory: %d\n", framesLeft);
				output.fragmentation = -1;
				sprintf(output.message, "CLIENT:> There was not enough memory available to satisfy your request.\n\n");
			}
		}
		//if it is not in between either of the above ranges, it is an invalid request
		else
		{
			memoryLeft = (framesLeft * FRAMESIZE);
			printf("\a");
			fprintf(stderr, "SERVER:> The requested memory was outside of the available space.\n");
			printf("SERVER:> There are %d memory units left to be allocated.\n\n", memoryLeft);
			output.fragmentation = -1;
			sprintf(output.message, "CLIENT:> The requested memory was outside of the available space! Make sure the request is not negative or 0!\n");
		}
		//********************************************************************
		write(fdOut, &output, sizeof(output)); //write the output struct to the client's private FIFO
		
		unlink(input.privateFIFOName); //unlink and close this clients privateFIFO
		close(fdIn);
		
		unlink("CommonFIFO"); //unlink and close the CommonFIFO so as to prepare for the next client
		close(fdOut);
	}
	
	//Printing a map of allocated memory
	i = 0;
	j = 0;
	printf("%s\t\t%s\n", "Frame", "Client");
	for (i; i < numOfClients; i++)
	{
		for (j; j < totalNumOfFrames; j++)
		{
			printf("%3d\t\t%s\n", j, clientsAllocation[j]);
		}
	}
	printf("\n\n");
	
	return 0;
}

/*
A simple function to check that certain input is valid; i.e. in between the min and max values and is a digit
returns 1 for true, valid input - returns 0 for false, invalid input
*/
int checkInput(char *a, int min, int max)
{
	int b = atoi(a); //convert string to integer
	float c = atof(a); //convert string to float
	
	/*checks if b (the integer representation of the input) is withing MIN and MAX
	and if the remainder of c (the floating point representation of the input) divided by 1 is 0 (i.e. it is an integer)
	*/
	if ((b >= min) && (b <= max) && (fmod(c, 1) == 0))
	{
		return 1;
	}
	return 0;
}
