#include "monty.h"

/**
 * count_stack - Counts a stack_t stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 *
 * Return: count.
 */
int count_stack(stack_t *stack)
{
	int count = 0;

	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}

	return (count);
}
