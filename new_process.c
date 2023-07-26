#include "shell.h"
/**
 *_execCmd - function that creates a new process and executes the commands.
 *@count: number of commands executed.
 *@args: a vector of commands and arguments.
 *@argv: a vector containing the program name.
 *@env_vars: environment variables.
 *Return: returns (0) on success
 */

int _execCmd(int count, char **args, char **argv, char **env_vars)
{
	int status;
	char *cmd_path = path(args, env_vars);
	pid_t pid;

	if (cmd_path == NULL)
	{
		error_msg(count, args, argv);
		return (status);
	}

	pid = fork();
	if (pid == 0)
	{

		if (execve(cmd_path, args, env_vars) == -1)
		{
			perror(args[0]);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(cmd_path);
	return (status);
}
