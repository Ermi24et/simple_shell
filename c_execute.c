#include "shell.h"

/**
 * c_execute - executes a given command
 * @command: command to be executed
 * @args: arguments to be executed
 * Return: void
 */

void c_execute(char *command, char **args)
{
	char path[MAX_PATH_LEN];
	char full_path[MAX_PATH_LEN];
	char *path_env = _getenv("PATH");
	char *dir;
	int dir_len, total_len, comd_len;

	if (strcmp(command, "/bin/ls") == 0)
	{
		execve(command, args, environ);
	}
	if (path_env == NULL)
	{
		handle_error(command);
	}

	_strncpy(path, path_env, MAX_PATH_LEN - 1);
	path[MAX_PATH_LEN - 1] = '\0';
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		dir_len = _strlen(dir);
		cmd_len = _strlen(command);
		total_len = dir_len + cmd_len + 2;

		if (total_len <= MAX_PATH_LEN)
		{
			_strncpy(full_path, dir, dir_len);
			full_path[dir_len] = '/';
			_strncpy(full_path + dir_len + 1, command, cmd_len);
			full_path[total_len - 1] = '\0';
			execve(full_path, args, NULL);
		}
		dir = strtok(NULL, ":");
	}
	handle_error(command);
}
