#include "shell.h"



char *path(char *cmd[], char *envp_vars[])
{
	char *cmd_path = NULL;
	char *path_var = NULL;
	char *delim = "PATH=:";
	char *str = "PATH=";
	char **paths, *copy = NULL;
	char *path = NULL, *full_path = NULL;

	int i = 0, j = 0;

	if (access(cmd[0], X_OK) == 0)
	{
		path_var = _duplicate(cmd[0]);
		return (path_var);
	}

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

	for (j = 0; paths[j] != NULL; j++)
	{
		path = s_concat(paths[j], "/");
		full_path = s_concat(path, cmd[0]);
		if (access(full_path, X_OK) == 0)
		{
			path_var = _duplicate(full_path);
			free(path);
			free(full_path);
			break;
		}
		else
		{
			free(path);
			free(full_path);
		}
	}

	free_block(paths);
	return (path_var);


}
