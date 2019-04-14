#include "s_func.h"
#include "queue.h"

struct client generateStruct(int b, int a, char name[])
{
	struct client result;
	result.burst = b;
	result.arrivalTime = a;
	strcpy(result.privateFIFOName, name);
	printStruct(result);
	return result;
}

void printStruct(struct client a)
{
	printf("%d\t%d\t%s\n", a.burst, a.arrivalTime, a.privateFIFOName);
}

void createCommonFIFO()
{
	if ((mkfifo("CommonFIFO", 0666) < 0 && errno != EEXIST)) //if the CommonFIFO could not be created, print error message
	{
		perror("SERVER:> Can't create common FIFO!\n\n");
		exit(-1);
	}

}

void openCommonFIFO(int *fdIn)
{	
	if ((*fdIn = open("CommonFIFO", O_RDONLY)) < 0)
	{
		perror("SERVER:> Can't open common FIFO to read from!\n\n");
		exit(-1);
	}
}

void closeCommonFIFO(int *fdIn)
{
	unlink("CommonFIFO");
	close(*fdIn);
}


void createPrivateFIFO(struct client input)
{
	if ((mkfifo(input.privateFIFOName, 0666)) < 0 && errno != EEXIST)
	{
		perror("SERVER:> Can't create private FIFO to client!\n\n");
		exit(-1);
	}
}

void openPrivateFIFO(int *fdOut, struct client input)
{
	if ((*fdOut = open(input.privateFIFOName, O_WRONLY)) < 0)
	{
		perror("SERVER:> Can't open private FIFO to client!\n\n");
		exit(-1);
	}
}

void closePrivateFIFO(int *fdOut, struct client input)
{
	unlink(input.privateFIFOName);
	close(*fdOut);
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

int getInput(char message1[], char message2[], int option)
{
	char buffer[MAX_LENGTH_BUFFER];
	int *p_valid;
	p_valid = (int *)malloc(sizeof(int));
	int *op;
	op = (int *)malloc(sizeof(int));
	switch (option)
	{
		case 0:
		{
			*op = 0;
			break;
		}
		case 1:
		{
			*op = 1;
			break;
		}
		default:
		{
			printf("Invalid Option!\n"); //should never be seen by the user!
			break;
		}
	}
	do
	{
		memset(buffer, 0, sizeof(buffer)); //clear the input buffer
		printf("%s", message1);
		printf("USER:> ");
		fgets(buffer, sizeof(buffer), stdin); //read the number of clients as a string and store in the character buffer
		if (*op == 0)
		{
			*p_valid = (checkInput(buffer, MIN_NUM_CLIENTS, MAX_NUM_CLIENTS) == 0) ? 0 : 1;
		}
		else
		{
			*p_valid = (checkInput(buffer, MIN_TIMEQUANT, MAX_TIMEQUANT) == 0) ? 0 : 1;
		}
		
		if (!(*p_valid))
		{
			clrscr();
			printf("\a\n");
			printf("%s", message2);
			printf("SERVER:> Please try again.\n\n");
		}
		
	} while (*p_valid == 0); //continue this loop while the input is invalid
	free(p_valid);
	free(op);
	return atoi(buffer);
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
