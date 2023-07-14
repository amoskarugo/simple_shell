#include "shell.h"


int _execCmd(int count, char **args, char **env_vars)
{
	int status;
	pid_t pid;

	(void)count;
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, env_vars) == -1)
			perror("Error!");
	}
	else
		wait(&status);
}
