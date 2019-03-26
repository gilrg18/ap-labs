#include <stdio.h>
#include <string.h>
#include <signal.h> 
#include <unistd.h>
#include <time.h>
#include "logger.h"

#define SIGINT  2

const char* base64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char encodedMsg[1024];
char binaryMsg[1024];
char decodedMsg[1024];

int progressCounter = 0;

int base64encode(char* str);
char bytesB6ToChar(char* str);
int base64decode(char* str);
char bytesB6ToChar(char* str);


void nsleep(long us)
{
    struct timespec wait;
    
    wait.tv_sec = us / (1000 * 1000);
    wait.tv_nsec = (us % (1000 * 1000)) * 1000;
    nanosleep(&wait, NULL);
}

void handle_sigint(int sig) 
{ 
    printf("Characters processed: %d\n", progressCounter);
} 

char bytesB6ToChar(char* str)
{
	int bitsMax = 32;
	int charValue = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		char tmp = str[i];
		char one = '1';
		if(tmp == one)
		{
			charValue += bitsMax;
		}
		bitsMax /= 2;
	}
	return base64chars[charValue];
}

char bytesB8ToChar(char* str)
{
	int bitsMax = 128;
	int charValue = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		char tmp = str[i];
		char one = '1';
		if(tmp == one)
		{
			charValue += bitsMax;
		}
		bitsMax /= 2;
	}
	char val = charValue;
	return val;
}


int base64encode(char* str)
{
	int c = 0;
	char* bits;
	int counter = 3;

	memset(encodedMsg, 0, sizeof encodedMsg);
	memset(binaryMsg, 0, sizeof binaryMsg);

	for(int i = 0; i < strlen(str); i++)
	{
		int bitsMax = 128;

		if(counter == 0)
		{
			counter = 3;
		}

		c = str[i];
		while(bitsMax > 0)
		{
			if((c / bitsMax) >= 1)
			{
				strcat(binaryMsg, "1");
				c = c - bitsMax;
			}
			else
			{
				strcat(binaryMsg, "0");
			}
			bitsMax = bitsMax / 2;
		}
		counter--;
		progressCounter++;
	}

	if(counter == 1)
	{
		strcat(binaryMsg, "0000q");
	}
	else if(counter  == 2)
	{
		strcat(binaryMsg, "0000q");
	}

	char byteB6[6] = "";
	counter = 0;
	int tcounter = 0;
	for(int i = 0; i < strlen(binaryMsg); i++)
	{
		char letter = binaryMsg[i];
		char q = 'q';
		if(letter == q)
		{
			break;
		}
		char tmp = binaryMsg[i];
		byteB6[counter] = tmp;
		counter++;
		if(counter == 6)
		{
			encodedMsg[tcounter] = bytesB6ToChar(byteB6);
			tcounter++;
			counter = 0;
		}
	}

	return 0;
}


int base64decode(char* str)
{

	memset(decodedMsg, 0, sizeof decodedMsg);
	memset(binaryMsg, 0, sizeof binaryMsg);

	for(int i = 0; i < strlen(str); i++)
	{
		int k = 0;
		while(str[i] != base64chars[k])
		{
			k++;
		}

		int bitsMax = 32;
		while(bitsMax > 0)
		{
			if(k / bitsMax >= 1)
			{
				strcat(binaryMsg, "1");
				k = k - bitsMax;
			}
			else
			{
				strcat(binaryMsg, "0");
			}
			bitsMax = bitsMax / 2;
		}
		progressCounter++;
	}

	char byteB8[8] = "";
	int counter = 0;
	int pos = 0;
	for(int i = 0; i < strlen(binaryMsg); i++)
	{
		byteB8[counter] = binaryMsg[i];
		counter++;

		if(counter == 8)
		{
			decodedMsg[pos] = bytesB8ToChar(byteB8);
			counter = 0;
			pos++;
		}
	}

	return 0;
}




FILE *fd, *fdOut;

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Invalid number of arguments.\n");
		return -1;
	}

	int c;
	char line[256];
	int linePos = 0;

	if(strcmp(argv[1], "--encode") == 0){

		fd = fopen(argv[2], "r+");
		fdOut = fopen("encoded.txt", "w");

		if(fd)
		{
			c = getc(fd);
			while(c != EOF)
			{
				if(c == '\n')
				{
					base64encode(line);
					char* encodedLine = encodedMsg;
					fprintf(fdOut, "%s\n", encodedLine);
					memset(line, 0, sizeof line);
					linePos = 0;

					signal(SIGINT, handle_sigint); 
				    nsleep(5000);
				}
				else
				{
					line[linePos] = c;
					linePos++;
				}
				c = getc(fd);
			}
			infof("INFO", "Succesfully encoded file, output file: encoded.txt.\n");
		}
		
	}
	else if(strcmp(argv[1], "--decode") == 0)
	{
		fd = fopen(argv[2], "r+");
		fdOut = fopen("decoded.txt", "w");

		if(fd)
		{
			c = getc(fd);
			while(c != EOF)
			{
				if(c == '\n')
				{
					base64decode(line);
					char* decodedLine = decodedMsg;
					fprintf(fdOut, "%s\n", decodedLine);
					memset(line, 0, sizeof line);
					linePos = 0;

					signal(SIGINT, handle_sigint); 
				    nsleep(5000);
				}
				else
				{
					line[linePos] = c;
					linePos++;
				}
				c = getc(fd);
			}
			infof("INFO", "Succesfully decoded file, output file: decoded.txt.\n");
		}
	}
	else
	{
		printf("Invalid flag.\n");
	}
	
	return 0;
}