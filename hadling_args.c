#include "shell.h"

/**
 * handling_args - handles the arguments entered by the user
 * @line: the input to parse
 *Return: void
 */

int handling_args(char *line, char *argv, int count)
{
	int ac = 0, exit_code = 0;
	char *tok = strtok(line, " ");
	char **args = NULL;

	while (tok != NULL)
	{
		args = realloc(args, (ac + 1) * sizeof(char *));
		args[ac++] = tok;
		tok = strtok(NULL, " ");
		exit_code = 0;
	}
	if (ac == 0)
	{
		exit_code = 127;
		free(args);
		exit(EXIT_FAILURE);
	}
	args = realloc(args, (ac + 1) * sizeof(char *));
	args[ac] = NULL;
	exit_code = c_execute(args[0], args, argv, count);
	free(args);

	return (exit_code);
}
