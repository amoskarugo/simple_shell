#include "shell.h"

/**
 *free_block - fuction that handles memory deallocation.
 *@args: memory to free.
 */
void free_block(char **args)
{

	int i = 0;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}

/**
 *my_atoi - convers a number that is passed as a string into an integer.
 *@s: number string
 *Return: returns the converted number
 */

int my_atoi(const char *s)
{
	int sign = 1;
	int res = 0;

	while (*s == ' ' || *s == '\t')
	{
		s++;
	}
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}

	res *= sign;

	return (res);
}
/**
 *error_msg - function to print error messages on the console.
 *@args: array of string pointers.
 *@counter: number of command executed
 *@argv: array of string pointers
 */

void error_msg(int counter, char *args[], char *argv[])
{
	int count = counter;
	char digit = count + '0';

	write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
	write(STDOUT_FILENO, ":", 1);
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, &digit, 1);
	write(STDOUT_FILENO, ":", 1);
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, args[0], _strlen(args[0]));
	write(STDOUT_FILENO, ":", 1);
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, "not found", _strlen("not found"));
	write(STDOUT_FILENO, "\n", 1);

}
/**
 *_sigHandler - handles signals
 *@num: signal code.
 */
void _sigHandler(__attribute__((unused))int num)
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$:", 2);

}
