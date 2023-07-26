#include "shell.h"

/**
 * handle_error - handles error
 * @command: command entered by the user
 * @argv: name of the program
 * @count: number of executions
 * Return: void
 */

void handle_error(char *command, char *argv, int count)
{
	char *loop_count = int_to_str(count);
	char *not_found = "not found\n";
	char *separator = ": ";

	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, separator, _strlen(separator));
	write(STDERR_FILENO, loop_count, _strlen(loop_count));
	write(STDERR_FILENO, separator, _strlen(separator));
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, separator, _strlen(separator));
	write(STDERR_FILENO, not_found, _strlen(not_found));

	free(loop_count);
}

/**
 * int_to_str - converts integer to string
 * @val: number to convert
 * Return: converted char
 */

char *int_to_str(int val)
{
	int num_digits = 1;
	int temp = val;
	char *num = NULL;

	while (temp /= 10)
	{
		num_digits++;
	}
	num = malloc((num_digits + 1) * sizeof(char));

	if (!num)
		return (NULL);
	num[num_digits] = '\0';

	while (num_digits--)
	{
		num[num_digits] = (val % 10) + '0';
		val /= 10;
	}
	return (num);
}
