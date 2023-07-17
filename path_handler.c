#include "shell.h"



char *path(char *cmd, char *envp_vars[])
{
	char *cmd_path = NULL;
	char *path_var = NULL;
	char *delim = "PATH=:";
	char *str = "PATH=";
	char **paths, *copy = NULL;


	int i = 0;

	while (envp_vars[i] != NULL)
	{

		if (_strncmp(str, envp_vars[i], _strlen(str)) == 0)
		{
			cmd_path = envp_vars[i];
		}
		i++;
	}

	copy = _duplicate(cmd_path);
	paths = tokenizer(copy, delim);

	free_block(paths);
	return (path_var);


}
