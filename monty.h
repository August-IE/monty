#ifndef _MONTY_H
#define _MONTY_H

#define STACK 0
#define QUEUE 1

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>


/******DATA_STRUCTURES*****/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/******FUNCTION PROTOTYPES*****/
void execute(char *line, stack_t **stack, unsigned int line_number, FILE *file);
void free_stack(stack_t **stack);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* OPCODE FUNCTIONS */
int is_integer(char *str);
void push(stack_t **stack, int arg);
void pall(stack_t *stack);
void _pop(stack_t **stack, unsigned int line_number);

/*MATH OPCODE FUNCTIONS*/
void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _divide(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H */
