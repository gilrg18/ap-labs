Gilberto Rogel García 
A01630171

gcc -c logger.c -o logger.o

gcc -c testLogger.c -o testLogger.o

gcc logger.o testLogger.o -o test.o

test.o
