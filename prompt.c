#include "shell.h"

/**
 * main - it reads input from the user, executes commands and exits
 *
 * Return: Success(0)
 */

int main(void)
{
	char *prompt = "$ ";
	char *glptr = NULL;
	size_t len = 0;
	ssize_t gl_result;
	int check_term = 1;

	while (check_term)
	{
		{
			check_term = isatty(STDIN_FILENO);
			if (check_term == 1)
				write(STDOUT_FILENO, prompt, _strlen(prompt));
		}
		gl_result = getline(&glptr, &len, stdin);
		if (gl_result == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		glptr[_strlen(glptr) - 1] = '\0';
		if (_strcmp(glptr, "exit") == 0)
		{
			break;
		}
		else if (_strcmp(glptr, "env") == 0)
		{
			print_environment();
			continue;
		}
		c_fork(glptr);
	}
	free(glptr);
	return (0);
}
