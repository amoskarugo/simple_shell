#include "shell.h"


char *get_line()
{
	char *lineptr = NULL;
	size_t n = 0;
	if(getline(&lineptr, &n, stdin) != -1)
	{
		return (lineptr);

	}else
	{
		free(lineptr);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
}
