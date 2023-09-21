#include "monty.h"

/**
 * _mul - multiplies the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void _mul(stack_t **stack, unsigned int line_number)
{
int product;

/* check if there are at least two elements in the stack */
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

/* multiply the top two elements and store the result in the second element */
product = (*stack)->n * (*stack)->next->n;
(*stack)->next->n = product;

/* remove the top element from the stack */
pop(stack, line_number);
}
