#include "shell.h"


unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	while(*str)
	{
		len++;
		str++;
	}
	return (len);
}

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

unsigned int count(char *lineptr)
{
	int tokens = 0;
	char *token = NULL;
	char *cpy = _duplicate(lineptr);
	char delim[] = " ";
	token = strtok(cpy, delim);

	while(token != NULL)
	{
		tokens++;
		token = strtok(NULL, delim);
	}

	free(cpy);
	return (tokens);
}
