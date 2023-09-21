#include "monty.h"

/**
 * _divide - Divides the second top element by the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 */
void _divide(stack_t **stack, unsigned int line_number)
{
stack_t *top = *stack;
unsigned int a = 0, b = 0, length = 0;

length = count_stack(*stack);

if (length < 2)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

a = top->n;
if (a == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
b = top->next->n;
top->next->n = b / a;
*stack = top->next;
free(top);
}
