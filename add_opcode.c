#include "monty.h"

/**
 * _add - add the two elements at the top of the stack.
 * @stack:
 * @line_number:
 *  
*/
void _add(stack_t **stack, unsigned int line_number)
{
stack_t *top;
stack_t *second;

top = *stack;
second = (*stack)->next;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
second->n += top->n;
*stack = second;
second->prev = NULL;
free(top);
}
