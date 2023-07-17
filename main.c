#include "shell.h"
/**
 *main - Entry point.
 *@ac: arguments count.
 *@argv: vector containing pointer to strings of arguments.
 *@envp: vector containing environmnet variables.
 *Return: nothing(0)
 */

int main(int ac, char *argv[], char *envp[])
{
	signal(SIGINT, _sigHandler);

	(void)ac;
	if (isatty(STDIN_FILENO) == 1)
	{
		fflush(stdout);
		shell_interactive(argv, envp);
	} else
	{
		shell_non_interactive(argv, envp);
	}
	return (0);
}
