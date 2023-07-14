#include "shell.h"




char **tokenizer(char *delim, char *lineptr)
{
	char *str_cpy = _duplicate(lineptr), *token;
	int tok_count = count(str_cpy);
	char **tokens = NULL;
	unsigned int i = 0;
	token = strtok(str_cpy, delim);

	tokens = malloc(sizeof(char *) * (tok_count + 1));

	while(token != NULL)
	{
		tokens[i] = _duplicate(token);
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	free(str_cpy);

	return (tokens);
}
