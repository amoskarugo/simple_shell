#include "shell.h"


int _execCmd(int count, char **args,char **argv, char **env_vars)
{
	int status;
	char *cmd_path = path(args, env_vars);
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{

		if (execve(cmd_path, args, env_vars) == -1)
			error_msg(count, args, argv);
	}
	else
		wait(&status);

	free(cmd_path);
	return (0);
}
