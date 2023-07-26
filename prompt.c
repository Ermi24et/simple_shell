#include "shell.h"

/**
 * signal_handler - controls ctrl + c
 * @signal: signal parameter
 * Return: void
 */

void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDERR_FILENO, "\n$ ", 4);
		fflush(stdout);
	}
}

/**
 * main - it reads input from the user, executes commands and exits
 *
 * Return: Success(0)
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	char *prompt = "$ ";
	char *glptr = NULL;
	size_t len = 0;
	ssize_t gl_result;
	int check_term = 1, exit_status = 0, count = 1;

	while (check_term)
	{

		check_term = isatty(STDIN_FILENO);
		if (check_term == 1)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		gl_result = getline(&glptr, &len, stdin);
		if (gl_result == -1)
		{
			exit_status = 127;
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
		signal(SIGINT, signal_handler);
		exit_status = c_fork(glptr, argv[0], count);
		count++;
	}
	free(glptr);
	return (exit_status);
}
