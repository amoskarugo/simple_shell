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
	int counter = 0;
	char **commands;

	line = get_line();
	if (*line == '\n' || *line == ' ' || *line == '\t' || *line == '\0')
	{
		free(line);
		/*write(STDOUT_FILENO, "\n", 1);*/
		exit(EXIT_SUCCESS);
	}
	commands = tokenizer(line, delim);

	execute_cmd(counter, commands, args, envp_vars);

	free(commands);


	return (0);
}
