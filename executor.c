#include "shell.h"



/**
 *execute_cmd - function that receives an argument of commands, and determine
*		whether the command is a built in or non-bultin and directs it
*		to the respective function for exxecution.
 *@args: a vector containing commands
 *
 *Return: returns a value returned from the function that executed the passed command.
 */


int execute_cmd(int counter, char *args[], char *argv[], char *envp_vars[])
{
	int j;

	built_in cmds[] = {

		{"exit", &shell_exit},
		{"env", &print_env},
		{NULL, NULL}
	};

	for (j = 0; cmds[j].cmd != NULL; j++)
	{
		if (_strncmp(cmds[j].cmd, args[0], _strlen(args[0])) == 0)
		{
			return ((cmds[j].function(args)));
		}
	}

	return (_execCmd(counter, args, argv, envp_vars));
}
