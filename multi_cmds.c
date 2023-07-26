#include "shell.h"
/**
 *multi - check whether user input consists of multiple commands
 *@args: a vector containing commands and arguments
 *Return: return true if multiple commands present else false
 */

bool multi(char *args[])
{
	int i = 0;
	char *seperator = ";";

	while (args[i] != NULL)
	{
		if (custom_strncmp(args[i], seperator, _strlen(seperator)) == 0)
		{
			return (true);
		}
		else
		{
			i++;
			continue;
		}

	}

	return (false);
}
