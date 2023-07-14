#include "shell.h"


/**
*tokenizer - a functions that generates tokens from a string
*@delim: a pointer to a string that specifies a set of characters
*	that delimit the tokens in the parsed string.
*@lineptr: a pointer to the string to generate tokens from.
*Return: returns an array of generated tokens or null if the string was empty
*/

char **tokenizer(char *delim, char *lineptr)
{
	char *str_cpy = _duplicate(lineptr), *token;
	int tok_count = count(str_cpy);
	char **tokens = NULL;
	unsigned int i = 0;

	token = strtok(str_cpy, delim);
	tokens = malloc(sizeof(char *) * (tok_count + 1));

	while (token != NULL)
	{
		tokens[i] = _duplicate(token);
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	free(str_cpy);

	return (tokens);
}
