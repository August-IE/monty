#include "monty.h"

/**
 * pall_opcode - A function that prints the values on the stack from the top
 * @stack: A pointer to the top node of a stack.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
