#include "c_func.h"

void openPrivateFIFO(int *fdIn, char fifoName[])
{
	if ((*fdIn = open(fifoName, O_RDONLY)) < 0)
	{
		perror("Can't open private FIFO to read from the server!\n");
		exit(-1);
	}
}

void openCommonFIFO(int *fdOut)
{
	if ((*fdOut = open("CommonFIFO", O_WRONLY)) < 0)
	{
		perror("Can't open common FIFO to write to server!\n");
		exit(-1);
	}
}

void getInput(char message1[], char message2[], int *array)
{
	/* struct in a = {{0, 0, 0, 0, 0}};
	memset(a.c_bursts, 0, sizeof(a.c_bursts)); */
	
	printf("%s", message1);
	printf("USER:> ");
	
	int i;
	for (i = 0; i < MAX_LENGTH_BURSTS; i++)
	{
		array[i] = getInteger(message2);
	}
}

int getInteger(char message[])
{
	char buffer[MAX_LENGTH_BUFFER];
	int *p_valid;
	p_valid = (int *)malloc(sizeof(int));
	do
	{
		memset(buffer, 0, sizeof(buffer)); //clear the input buffer
		fgets(buffer, sizeof(buffer), stdin); //read burst time and store in buffer
		
		*p_valid = (checkInput(buffer, MIN_BURST, MAX_BURST) == 0) ? 0 : 1;

		if (!(*p_valid))
		{
			clrscr();
			printf("\a\n");
			printf("%s\n", message);
			printf("CLIENT:> Please try again.\n\n");
		}
		
	} while (*p_valid == 0); //continue this loop while the input is invalid
	free(p_valid);
	return atoi(buffer);
}

int checkInput(char *a, int min, int max)
{
	int b = atoi(a); //convert string to integer
	float c = atof(a); //convert string to float
	
	if ((b >= min) && (b <= max) && (fmod(c, 1) == 0))
	{
		return 1;
	}
	return 0;
}

void arrcpy(int *source, int srcLength, int *dest)
{
	int i;
	for (i = 0; i < srcLength; i++)
	{
		dest[i] = source[i];
	}
}

void clrscr()
{
	if (PLATFORM_NAME == "windows")
	{
		const char *CLEAR_SCREEN_ANSI = "\e[2J";
		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
	}
	else if (PLATFORM_NAME == "unix")
	{
		printf("\e[1;1H\e[2J");
	}
	else if (PLATFORM_NAME == "linux")
	{
		system("clear");
	}
	else
	{
		int *i;
		i = (int *)malloc(sizeof(int));
		for (*i = 0; *i <= 10; *i++)
		{
			printf("\n\n\n\n\n\n\n\n\n\n");
		}
		free(i);
	}
}
