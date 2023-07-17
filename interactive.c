#include "shell.h"
/**
 *shell_interactive - function executed when the program is run
 *                    in interactive mode
 *Return: nothing(0)
 *
 *
 */
int shell_interactive(char **args, char **envp_vars)
{
	unsigned int counter = 0; /*tracks the number of commands executed*/
	int  status = 1;
	char *delim = "\t\n ";

	while (status)
	{
		counter++;
		write(STDOUT_FILENO, "$:", _strlen("$:"));
		char *line = get_line();
		if (*line == '\n' || *line == '\0' || *line == '\t' || *line == ' ')
		{
			free(line);
			continue;
		}
		char **commands = tokenizer(line, delim);

		execute_cmd(counter, commands, args, envp_vars);
		free_block(commands);
	}
	return (0);
}
