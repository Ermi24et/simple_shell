#include "shell.h"

/**
 * _getenv - retrieves the value of an environment variable
 * @name: name of the variable
 * Return: returns a pointer, otherwise NULL
 */

char *_getenv(const char *name)
{
	int i;
	char *e_var;
	int n_len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		e_var = environ[i];
		if (_strncmp(name, e_var, n_len) == 0 && e_var[n_len] == '=')
		{
			return (e_var + n_len + 1);
		}
	}
	return (NULL);
}
