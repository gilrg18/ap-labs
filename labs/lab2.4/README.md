Lab 2.4 - Add syslog support to your Logger
Now it's time to add support for Linux system logging into your logger that you implemented on lab2.2.

A new initLoggerfunction will be added in order to add support for choosing between stdout or syslog logging.

int initLogger(char *logType)
You will handle the following log types:

stdout or empty string for STDOUT logging
syslog for SYSLOG logging
You can use the The Linux Programming Interface book as a reference for your implementation. See 37th chapter on 5th section.

General Requirements and Considerations
Use the testLogger.c file for testing your logger.c library implementation.
Use the Makefile for compilation.
Update README.md with the proper steps for building and running your code.
Don't forget to handle errors properly.
Coding best practices implementation will be also considered.

To run:

gcc -c logger.c -o logger.o
gcc -c testLogger.c -o testLogger.o
gcc logger.o testLogger.o -o main.o
main.o