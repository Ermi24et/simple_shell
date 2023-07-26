#include "shell.h"

/**
 * _strlen - returns length of a string
 * @s: the string to count
 * Return: string length
 */

int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: string to compare
 * @s2: string to compare second
 * Return: the difference between the first char that are not the same
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

/**
 * _strncmp - compares n bytes of two strings
 * @str1: first string to compare
 * @str2: second string to compare
 * @n: number of strings to compare
 * Return: 0 if they are equal
 */

int _strncmp(const char *str1, const char *str2, int n)
{
	int i;

	for (i = 0; i < n && str1[i] && str2[i]; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	if (i == n)
	{
		return (0);
	}
	return (str1[i] - str2[i]);
}

/**
 * _strncpy - function that copies a string
 * @dest: the destination of the string
 * @src: source of a string
 * @n: length of a string
 * Return: pointer to the resulting string dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i]; i++)
		des[i] = src[i];
	for (; i < n; i++)
		dest[] = '\0';
	return (dest);
}
