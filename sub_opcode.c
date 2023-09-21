#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _sub - subtracts the top element of the stack from second
 *	top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	_pop(stack, line_number);

	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->n -= n;
}
