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
    char *opcode, *value;
    int arg;
    (void)*file;

    opcode = strtok(line, " \t\n");

    if (opcode == NULL)
        return;

    if (strcmp(opcode, "push") == 0)
    {
        value = strtok(NULL, " \t\n");
        if (value == NULL || !is_integer(value))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        arg = atoi(value);
        push(stack, arg);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(*stack);
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

/**
 * push - Push an integer onto the stack
 * @stack: Pointer to the stack
 * @arg: Integer to push
 */
void push(stack_t **stack, int arg)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = arg;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Print all elements of the stack
 * @stack: Pointer to the stack
 */
void pall(stack_t *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}

/**
 * is_integer - Check if a string is a valid integer
 * @str: String to check
 * Return: 1 if it's an integer, 0 otherwise
 */
int is_integer(char *str)
{
    int i = 0;

    if (str == NULL)
        return 0;

    if (str[0] == '-')
        i = 1;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
