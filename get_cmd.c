#include "shell.h"


char *get_line()
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t readln = 0;

	readln = getline(&lineptr, &n, stdin);
	if(readln != -1)
	{
		return (lineptr);

	}else
	{
		free(lineptr);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
		/*signal(SIGINT, _sigHandler);*/
	}
}
