#include "shell.h"
/**
 *_strlen - fuction to count the length of a string.
 *@str: pointer to a string to count the length
 *
 *Return: returns the length of the string.
 */

unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
/**
 *_duplicate - function to create a string duplicate.
 *@str: pointer to a string to create its duplicate.
 *
 *Return: a pointer to a duplicated string.
 */
char *_duplicate(char *str)
{
	char *duplicate;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	duplicate = (char *)malloc(sizeof(char) * (_strlen(str) + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		duplicate[i] = str[i];
	}
	duplicate[i] = '\0';

	return (duplicate);

}
/**
 *count - a function that receives a pointer to a string and determines the
 *	the number of tokens that can be deduced from it.
 *@lineptr: a pointer to a string to counter possible number of tokens to be
 *	extrcted.
 *Return: possible number of tokens to be created.
 */
unsigned int count(char *lineptr)
{
	int tokens = 0;
	char *token = NULL;
	char *cpy = _duplicate(lineptr);
	char delim[] = " ";

	token = strtok(cpy, delim);
	while (token != NULL)
	{
		tokens++;
		token = strtok(NULL, delim);
	}

	free(cpy);
	return (tokens);
}
