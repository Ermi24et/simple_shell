#ifndef SHELL_H
#define SHELL_H

/* standard headers for our shell */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* declaring an external environment variable */
extern char **environ;

/* function prototypes for utility functions */
char *_strncpy(char *dest, char *src, int n);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, int n);

/* constant for the maximum length of full path */
#define MAX_PATH_LEN 4096

/* function prototypes for our shell */
void c_execute(char *command, char **args);
void handling_args(char *line);
char *_getenv(const char *name);
void print_environment(void);
void c_fork(char *comm);
void handle_error(char *command);
void signal_handler(int signal);

#endif
