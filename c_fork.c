#include "shell.h"

/**
 * c_fork - creates a proccess and call arguments
 * @comm: a command user entered
 * Return: void
 */

void c_fork(char *comm)
{
	pid_t c_pid;

	c_pid = fork();
	if (c_pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == 0)
	{
		handling_args(comm);
	}
	else
	{
		wait(NULL);
	}
}
