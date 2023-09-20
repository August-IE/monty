#include "monty.h"
#include <stdio.h>

/**
* main - Monty interpreter entry point
* @argc: Argument counter
* @argv: Argument Vector
*
* Return: Always 0
*/

int main(int argc, char **argv)
{
char *line = NULL;
FILE *file;
size_t size = 0;
ssize_t nread;
stack_t *stack = NULL;
unsigned int line_number = 0;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while (nread != -1)
{
line = NULL;
nread = getline(&line, &size, file);
line_number++;
if (nread > 0)
{
execute(line, &stack, line_number, file);
}
free(line);
}
fclose(file);
free_stack(&stack);
return (0);
}
