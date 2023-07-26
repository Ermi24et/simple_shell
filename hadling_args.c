#include "shell.h"

/**
 * handling_args - handles the arguments entered by the user
 * @line: the input to parse
 *Return: void
 */

void handling_args(char *line)
{
	int ac = 0;
	char *tok = strtok(line, " ");
	char **args = NULL;

	while (tok != NULL)
	{
		args = realloc(args, (ac + 1) * sizeof(char *));
		args[ac++] = tok;
		tok = strtok(NULL, " ");
	}
	if (ac == 0)
	{
		free(args);
		exit(EXIT_FAILURE);
	}
	args = realloc(args, (ac + 1) * sizeof(char *));
	args[ac] = NULL;
	c_execute(args[0], args);
	free(args);
}
