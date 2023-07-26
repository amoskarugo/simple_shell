#include "shell.h"
/**
 *shell_interactive - function executed when the program is run
 *                    in interactive mode
 *@args: a vector containing pointers to strings passed from the
 *		main function.
 *@envp_vars: environment variables
 *Return: nothing(0)
 *
 *
 */
int shell_interactive(char **args, char **envp_vars)
{
	unsigned int counter = 0; /*tracks the number of commands executed*/
	int  status = 1;
	char *delim = " \t\n";
	char *line;
	char **commands;


	while (status)
	{
		counter++;
		write(STDOUT_FILENO, "$:", _strlen("$:"));
		line = get_line();

		if (*line == '\n' || *line == '\0' || *line == '\t')
		{
			free(line);
			continue;
		}

		commands = tokens_generator(line, delim);
		if (commands == NULL)
		{
			continue;
		}

		execute_cmd(counter, commands, args, envp_vars);
		free_block(commands);
	}
	return (0);
}
