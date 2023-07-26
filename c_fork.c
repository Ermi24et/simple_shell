#include "shell.h"

/**
 * c_fork - creates a proccess and call arguments
 * @comm: a command user entered
 * @argv: name of the program
 * @count: number of executions
 * Return: void
 */

int c_fork(char *comm, char *argv, int count)
{
	pid_t c_pid;
	int status = 0;

	c_pid = fork();
	if (c_pid == -1)
	{
		perror("Error");
		return (0);
	}
	if (c_pid == 0)
	{
		handling_args(comm, argv, count);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);

			if (isatty(STDIN_FILENO) == 1)
				return (status);
		}
	}

	return (status);
}
