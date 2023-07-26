#include "shell.h"

/**
 *shell_exit - it function that terminates the shell
 *@args: a vector containing commands passed from the shell prompt
 *Return: nothing
 */

int shell_exit(char *args[])
{
	int exitcode;

	if (args[1] == NULL)
	{
		free_block(args);
		exit(0);
	}

	exitcode = my_atoi(args[1]);
	free_block(args);
	exit(exitcode);
}

/**
 *print_env - prints all the environment variables.
 *@envp_vars: an array of environment variables.
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

/**
 *_setenv - function to create a new environment variable
 *@args: commands and arguments passed from the command line
 *Return: 0
 */
int _setenv(char *args[])
{
	int j = 0, i = 0, k = 0;
	char var_name[30] =  "", *copy = NULL;
	char *var = "USER", *assign_op = "=";

	if (args[1] == NULL)
		return (0);
	copy = _duplicate(args[1]);
	while (copy[k] != '\0')
	{
		var_name[i] = copy[k];
		i++;
		k++;
	}
	free(copy);
	var_name[i] = *assign_op;
	while (environ[j] != NULL)
	{
		if (_strncmp(var, environ[j], _strlen(var)) == 0)
		{
			str_cpy(environ[j], var_name);
		}

		j++;
	}

	return (0);
}
