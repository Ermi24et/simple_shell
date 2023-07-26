#include "shell.h"

/**
 * print_environment - printing environment variables to std ouptput
 * Return: void
 */

void print_environment(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, envirin[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
