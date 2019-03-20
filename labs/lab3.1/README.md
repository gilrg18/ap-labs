Lab 3.1 - File/Directory Monitor
================================

Write a program that logs all file creations, deletions, and renames under the directory named in its command-line argument.
The program should monitor events in all of the subdirectories under the specified directory.
To obtain a list of all of these subdirectories, you will need to make use of [nftw()](https://linux.die.net/man/3/nftw).
When a new subdirectory is added under the tree or a directory is deleted, the set of monitored subdirectories should be updated accordingly.

General Requirements and Considerations
---------------------------------------
- Use the logger that was done on [lab2.4](https://github.com/CodersSquad/ap-labs/tree/master/labs/lab2.4).
- Use the `inotify` [API](http://man7.org/linux/man-pages/man7/inotify.7.html).
- Use the `monitor.c` file for implementing the lab's general flow.
- Use the `Makefile` for compilation.
- Update `README.md` with the proper steps for building and running your code.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.

To Compile
---------------------------------------
 gcc -c logger.c -o logger.o

 gcc -c monitor.c -o monitor.o

 gcc logger.o monitor.o -o main.o

 ./main.o .
