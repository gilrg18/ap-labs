Lab 3.2 - Progress Notifier with Signals
Implement a program for encoding and decoding files by using the Base64 algorithm. You're free to copy from previous link's implementation (don't forget to reference to the author's page), the interesting part will be the implementation of signal handlers for progress status.

Add one or multiple signal handlers to catch the SIGINFO and SIGINT. Once a signal is catched, your program should dislay the current progress of the encoding or deconding tasks.

You will need the proper mechanisms for tracking the progress of any encoding/decoding task. You program must support plain text input files.

To run:

    make

    Encoding
    ./base64 --encode input.txt
    Your program should generate a new encoded.txt file with the result.

    Decoding
    ./base64 --decode encoded.txt
    Your program will generate a decoded.txt file witg the result.
