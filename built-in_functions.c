#include "shell.h"

/**
 *shell_exit - it function that terminates the shell
 *@args: a vector containing commands passed from the shell prompt
 *Return: nothing
 */

int shell_exit(char *args[])
{
	int exitcode;

	if(args[1] == NULL)
		exit(0);

	exitcode = my_atoi(args[1]);
	free_block(args);
	exit(exitcode);
}

/**
 *print_env - prints all the environment variables.
 *@args: an array of environment variables.
 *Return: nothing
 *
 */

int print_env(char *envp_vars[])
{
	int i = 0;
	envp_vars = environ;

	while (envp_vars[i] != NULL)
	{
		write(STDOUT_FILENO, envp_vars[i], _strlen(envp_vars[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
