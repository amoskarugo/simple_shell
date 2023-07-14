#include "shell.h"

int shell_interactive()
{
	unsigned int counter = 0, status = 1;
	char *delim = " \t\n";
	while (status)
	{
		write(STDOUT_FILENO, "simple_shell-$:", _strlen("simple_shell-$:"));
		char *line = get_line();
		int i = 0;
		char **commands = tokenizer(delim, line);

		while(commands[i] != NULL)
		{
			printf("%s\n", commands[i]);
			i++;
		}
	}
	return (0);
}
