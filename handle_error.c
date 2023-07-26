#include "shell.h"

/**
 * handle_error - handles error
 * @command: command entered by the user
 * Return: void
 */

void handle_error(char *command)
{
	char *error_msg = ": not found";

	write(STDERR_FILENO, "/hsh: ", 6);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, error_msg, _strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
