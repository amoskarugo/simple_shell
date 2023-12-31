#include "shell.h"
/**
 *shell_non_interactive - function executed when the program is executed in
 *			  non_interactive mode.
 *@args: vector containing pointers to strings passed along the program.
 *@envp_vars: environment variables.
 *Return: returns (0) on success.
 */
int shell_non_interactive(char *args[], char *envp_vars[])
{
	char *line;
	char *delim = "\t\n ";
	int counter = 1;
	char **commands;

	line = get_line();
	if (*line == '\n' || *line == '\t' || *line == '\0')
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	commands = tokens_generator(line, delim);
	if (commands == NULL)
	{
		exit(EXIT_SUCCESS);
	}

	execute_cmd(counter, commands, args, envp_vars);

	free_block(commands);


	exit(EXIT_SUCCESS);
}
