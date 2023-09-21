#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - Entry point for Monty Interpreter
 *
 * @argc: The number of arguments passed to the program
 * @argv: Pointer to an array of char pointers representing arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	int exit_code = EXIT_SUCCESS;
	FILE *script_fd;

	if (argc != 2)
	{
	usage_error();
	return (EXIT_FAILURE);
	}

	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
	{
	f_open_error(argv[1]);
	return (EXIT_FAILURE);
	}

	exit_code = run_monty(script_fd);
	fclose(script_fd);

	return (exit_code);
}
