# THIS IS A REPOSITORY FOR 0X19. C - STACKS, QUEUES - LIFO, FIFO..
## A GROUP PROJECT BY: AUGUST IDIATA AND EMEDO PEACE 


## Requirements

1. Allowed editors: vi, vim, emacs.
2. All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89.
3. All your files should end with a new line.
4. A README.md file, at the root of the folder of the project is mandatory.
5. Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl.
6. You allowed to use a maximum of one global variable.
7. No more than 5 functions per file.
8. You are allowed to use the C standard library.
9. The prototypes of all your functions should be included in your header file called monty.h.
10. All your header files should be include guarded.


<img align="center" alt="Coding" width="400" src="https://miro.medium.com/v2/resize:fit:960/1*b6F92o5lmq5h-YCIaV3r3g.gif">

##The monty program

- Usage: monty file
  - where file is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
  - where <file> is the name of the file
- If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
  - where is the line number where the instruction appears.
  - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
  - an error occured
- If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
- You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
