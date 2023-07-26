#include "shell.h"

/**
*read_stdin - reads a line from the standard input
*@line: a pointer to a pointer where the line will be stored
*@bytes: number of bytes to be read
*Return: -1 on failure and 0 on success
*/


ssize_t read_stdin(char **line, size_t *bytes)
{
	static  char *buf;
	ssize_t i, total = 0, buf_sz = 0;
	ssize_t _read = 0;
	size_t BUFF_SIZE = 10240000;

	buf = (char *)malloc(BUFF_SIZE);
	if (line == NULL || bytes == NULL)
		return (-1);
	if (*line == NULL || *bytes == 0)
	{

		*bytes = BUFF_SIZE;
		*line = (char *)malloc(BUFF_SIZE);

		if (*line == NULL)
		{
			perror("memory allocation failed");
			return (-1);
		}
	}
	while ((_read = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
	{
		if (_read == 0)
			return (-1);
		for (i = 0; i < _read; i++)
		{
			(*line)[buf_sz++] = buf[i];
			total++;

		}
		if (buf[_read - 1] == '\n')
			break;

	}
	(*line)[buf_sz] = '\0';
	if (_read == -1)
		perror("read line failed");

	free(buf);
	return ((_read > 0 || buf_sz > 0) ? total : -1);
}

/**
 *get_line - gets the line read from the stdin.
 *Return: returns a pointer to a string read from the stdin stream.
 *
 */


char *get_line()
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t readln = 0;

	readln = read_stdin(&lineptr, &n);
	if (readln != -1)
	{
		return (lineptr);

	} else
	{
		free(lineptr);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
		/*signal(SIGINT, _sigHandler);*/
	}
}


