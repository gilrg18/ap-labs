#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <stdarg.h>


const char* TAG_INFO = "INFO";
const char* TAG_WARNING = "WARNING";
const char* TAG_ERROR = "ERROR";
const char* TAG_PANIC = "PANIC";

int loggerMode = 0;

int initLogger(char* logType)
{
	if(strcmp("stdout", logType))
	{
		loggerMode = 0;
	}
	else if(strcmp("syslog", logType))
	{
		loggerMode = 1;
	}
	else
	{
		printf("Invalid input\n");
		return -1;
	}
	return 0;
}


int infof(const char* tag, const char* message)
{
	if(loggerMode == 0)
	{
		printf("\033[1;32m");
		printf(" [%s]: %s\n", tag, message);
		printf("\033[0m");
	}
	else
	{
		syslog(LOG_USER | LOG_INFO, message, message);
	}

	return 0;
}


int warnf(const char* tag, const char* message)
{
	if(loggerMode == 0)
	{
		printf("\033[1;33m");
		printf(" [%s]: %s\n", tag, message);
		printf("\033[0m");
	}
	else
	{
		syslog(LOG_USER | LOG_WARNING, message, message);
	}

	return 1;
}


int errorf(const char* tag, const char* message)
{
	if(loggerMode == 0)
	{
		printf("\033[1;31m");
		printf(" [%s]: %s\n", tag, message);
		printf("\033[0m");
	}
	else
	{
		syslog(LOG_USER | LOG_ERR, message, message);
	}

	return -1;
}


int panicf(const char* tag, const char* message)
{
	if(loggerMode == 0)
	{
		printf("\033[1;35m");
		printf(" [%s]: %s\n", tag, message);
		printf("\033[0m");
	}
	else
	{
		syslog(LOG_USER | LOG_EMERG, message, message);
	}

	return -2;
}