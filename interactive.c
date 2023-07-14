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
	char *delim = " \t\n";

	while (status)
	{
		counter++;
		write(STDOUT_FILENO, "simple_shell-$:", _strlen("simple_shell-$:"));
		char *line = get_line();
		int i = 0;
		char **commands = tokenizer(delim, line);

		_execCmd(counter, commands, args, envp_vars);
		free(line);
		free_block(commands);
	}
	return (0);
}
