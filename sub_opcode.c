#include "monty.h"

/**
 * _sub - subtracts the top element of the stack from second top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
stack_t *top;
stack_t *second;

top = *stack;
second = (*stack)->next;
int n;
 /* check if the stack has at least two elements */
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
/* pop the top element and store its value */
n = (*stack)->n;
pop(stack, line_number);
/* pop the second top element and subtract n from it */
(*stack)->n = (*stack)->n - n;
}
