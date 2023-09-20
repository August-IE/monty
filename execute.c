#include "monty.h"
#include <string.h>

/**
 * execute - Execute Monty byte code instructions
 * @line: The line containing the Monty instruction
 * @stack: Pointer to the stack
 * @line_number: Line number in the input file
 * @file: Pointer to the input file
 */
void execute(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
    char *opcode;
    (void)**stack;
    (void)*file;
    opcode = strtok(line, " \t\n");

    if (opcode == NULL)
        return;
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}


/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
