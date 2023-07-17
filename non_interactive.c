#include "shell.h"

int shell_non_interactive(char *args[], char *envp_vars[])
{
	char *line;
	char *delim = "\t\n ";
	int counter = 0;
	line = get_line();

	if (*line == '\n' || *line == ' ' || *line == '\t' || *line == '\0')
	{
		free(line);
		/*write(STDOUT_FILENO, "\n", 1);*/
		exit(EXIT_SUCCESS);
	}
	char **commands = tokenizer(line, delim);

	execute_cmd(counter, commands, args, envp_vars);

	free(commands);


	return (0);
}
