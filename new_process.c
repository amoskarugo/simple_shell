#include "shell.h"


int _execCmd(int count, char **args,char **argv, char **env_vars)
{
	int status;
	char *cmd_path = path(args[0], env_vars);
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{

		if (execve(args[0], args, env_vars) == -1)
			error_msg(count, args, argv);
	}
	else
		wait(&status);

	return (0);
}
