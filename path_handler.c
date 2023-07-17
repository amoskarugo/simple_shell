#include "shell.h"
/**
 *path - function that creates path to an executable.
 *@cmd: vector containing commands and arguments.
 *@envp_vars: evironment variables vector.
 *Return: returns a path to an executable or null if the path does not exist
 */


char *path(char *cmd[], char *envp_vars[])
{
	char *cmd_path = NULL, path_var = NULL, *delim = "PATH=:";
	char **paths, *copy = NULL, *str = "PATH=";
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
