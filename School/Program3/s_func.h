#ifndef FUNC_H_
#define FUNC_H_

//Figuring out what platform this server is running on
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

#define MIN_NUM_CLIENTS 3
#define MAX_NUM_CLIENTS 32
#define MAX_LENGTH_BUFFER 10
#define MIN_TIMEQUANT 1
#define MAX_TIMEQUANT 64

#include "queue.h"
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

/*Function to create a struct for each client; used in the enqueue function*/
struct client generateStruct(int b, int a, char name[]);

/*Function to display the contents of a client's struct*/
void printStruct(struct client a);

/*Function to create the commonFIFO that can be written to by clients*/
void createCommonFIFO();

/*Function to open the commonFIFO for reading*/
void openCommonFIFO(int *fdIn);

/*Function to close and unlink commonFIFO*/
void closeCommonFIFO(int *fdIn);

/*Function to create the private FIFO that can be read from by the client*/
void createPrivateFIFO(struct client input);

/*Function to open the privateFIFO for writing*/
void openPrivateFIFO(int *fdOut, struct client input);

/*Function to close and unlink privateFIFO*/
void closePrivateFIFO(int *fdOut, struct client input);

/*Function to check that certain input is valid; i.e. in between the min and max values and is an integer
returns 1 for true, valid input - returns 0 for false, invalid input
*/
int checkInput(char *a, int min, int max);

/*A function to get integer input from user.
'option' determines which input we are getting; number of clients or the timeQuant*/
int getInput(char message1[], char message2[], int option);

/*A function to clear the screen based on the platform this server is running on.
The platform is determined in the preprocessor directives.*/
void clrscr();

#endif
