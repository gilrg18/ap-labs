Gilberto Rogel García a01630171
To compile in c 
In the command prompt, Go to the address  where all your files are located and copy the following commands
gcc -c str-main.c -o str-main.o
gcc -c strlib.c -o strlib.o
gcc str-main.o strlib.o -o str-final.o