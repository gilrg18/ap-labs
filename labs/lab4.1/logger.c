#include <stdio.h>
#include <syslog.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "logger.h"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define MAG "\x1B[35m"
#define RESET "\x1B[0m"

char buf[256];
int type = 0;

int initLogger(char *logType)
{
    printf("\nInitializing Logger on: %s\n", logType);
    if (strcmp(logType, "stdout"))
    {
        type = 1;
    }
    else
    {
        type = 0;
    }
    return 0;
}

int infof(const char *format, ...)
{
    if (type == 0)
    {
        printf("<Info>: ");
        va_list list;
        va_start(list, format);
        snprintf(buf, sizeof buf, "%s%s%s\n", GRN, format, RESET);
        vfprintf(stdout, buf, list);
        va_end(list);
    }
    else
    {
        openlog("info", (LOG_CONS | LOG_PERROR | LOG_PID), LOG_USER);
        snprintf(buf, sizeof buf, "%s%s%s", GRN, format, RESET);
        syslog(LOG_INFO, "%s", buf);
        closelog();
    }
    return 0;
}

int warnf(const char *format, ...)
{
    if (type == 0)
    {
        printf("<Warning>: ");
        va_list list;
        va_start(list, format);
        snprintf(buf, sizeof buf, "%s%s%s\n", YEL, format, RESET);
        vfprintf(stdout, buf, list);
        va_end(list);
    }
    else
    {
        openlog("warn", (LOG_CONS | LOG_PERROR | LOG_PID), LOG_USER);
        snprintf(buf, sizeof buf, "%s%s%s", YEL, format, RESET);
        syslog(LOG_WARNING, "%s", buf);
        closelog();
    }
    return 0;
}

int errorf(const char *format, ...)
{
    if (type == 0)
    {
        printf("<Error>: ");
        va_list list;
        va_start(list, format);
        snprintf(buf, sizeof buf, "%s%s%s\n", RED, format, RESET);
        vfprintf(stdout, buf, list);
        va_end(list);
    }
    else
    {
        openlog("error", (LOG_CONS | LOG_PERROR | LOG_PID), LOG_USER);
        snprintf(buf, sizeof buf, "%s%s%s", RED, format, RESET);
        syslog(LOG_ERR, "%s", buf);
        closelog();
    }
    return 0;
}
int panicf(const char *format, ...)
{
    if (type == 0)
    {
        printf("<Panic>: ");
        va_list list;
        va_start(list, format);
        snprintf(buf, sizeof buf, "%s%s%s\n", MAG, format, RESET);
        vfprintf(stdout, buf, list);
        va_end(list);
    }
    else
    {
        openlog("panic", (LOG_CONS | LOG_PERROR | LOG_PID), LOG_USER);
        snprintf(buf, sizeof buf, "%s%s%s", MAG, format, RESET);
        syslog(LOG_EMERG, "%s", buf);
        closelog();
    }
    return 0;
}
 