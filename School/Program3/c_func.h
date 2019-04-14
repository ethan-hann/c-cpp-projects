#ifndef C_FUNC_H_
#define C_FUNC_H_

//Figuring out what platform this client is running on
#if defined(_WIN32)
	#define PLATFORM_NAME "windows" //Windows platform
#elif defined(_WIN64)
	#define PLATFORM_NAME "windows" //Windows platform
#elif defined(__CYGWIN__) && !defined(_WIN32)
	#define PLATFORM_NAME "windows" //Windows platform using Cygwin POSIX
#elif defined(__linux__)
	#define PLATFORM_NAME "linux" //any linux platform
#elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
	#define PLATFORM_NAME "unix" //unix platform
#endif

#define MAX_LENGTH_FIFO_NAME 32
#define MIN_BURST 1
#define MAX_BURST 128
#define MAX_LENGTH_BUFFER 10

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>

typedef struct client //define the client struct (for client TO server)
{
	int burst;
	int arrivalTime;
	char privateFIFOName[MAX_LENGTH_FIFO_NAME];
} PCB;

typedef struct server //define the server struct (for server TO client)
{
	int clock;
	int turnAroundTime;
} S_PCB;

/*Function to open privateFIFO*/
void openPrivateFIFO(int *fdIn, char fifoName[]);

/*Function to open commonFIFO*/
void openCommonFIFO(int *fdOut);

/*Function to check that certain input is valid; i.e. in between the min and max values and is an integer
returns 1 for true, valid input - returns 0 for false, invalid input
*/
int checkInput(char *a, int min, int max);

/*A function to get integer input from user.*/
int getInput(char message1[], char message2[]);

/*A function to clear the screen based on the platform this server is running on.
The platform is determined in the preprocessor directives.*/
void clrscr();

#endif
