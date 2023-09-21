#include "monty.h"

/**
 * _pop - removes the top element of the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: line number of opcode.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
stack_t *top;

if (*stack == NULL) /* check if stack is empty */
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
free_stack(&(*stack));
exit(EXIT_FAILURE);
}
top = *stack; /* store the top element in a temporary variable */
*stack = (*stack)->next; /* moves stack pointer to the next element */
if (*stack != NULL) /* if the stack is not empty after popping */
{
(*stack)->prev = NULL; /* set the previous pointer of the new top to NULL */
}
free(top); /* free the memory of the popped element */
}
