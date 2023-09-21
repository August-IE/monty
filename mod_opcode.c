#include "monty.h"

/**
 * _mod - computes the rest of division of second top element by top element
 * @stack: pointer to top of stack
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
int top;

if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
free_stack(&(*stack));
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
free_stack(&(*stack));
exit(EXIT_FAILURE);
}
top = (*stack)->n;
_pop(stack, line_number);
(*stack)->n %= top;
}
