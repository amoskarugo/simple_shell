#include "shell.h"


/**
*tokens_generator - a functions that generates tokens from a string
*@delim: a pointer to a string that specifies a set of characters
*	that delimit the tokens in the parsed string.
*@lineptr: a pointer to the string to generate tokens from.
*Return: returns an array of generated tokens or null if the string was empty
*/

char **tokens_generator(char *lineptr, char *delim)
{
	char *cpy = _duplicate(lineptr), *token = NULL;
	int tok_count = count(cpy, delim);
	char **tokens = NULL;
	unsigned int i = 0;

	token = my_strtok(cpy, delim);
	tokens = malloc(sizeof(char *) * (tok_count + 1));

	if (tokens == NULL)
		return (NULL);

	while (token != NULL)
	{
		tokens[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		make_copy(tokens[i], token);
		/*tokens[i] = _duplicate(token);*/
		token = my_strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	free(cpy);
	free(lineptr);
	if (tokens[0] == NULL)
	{
		free_block(tokens);
		return (NULL);
	}

	return (tokens);
}
/**
 *merge_strings - function to merge two strings
 *@s1: first string.
 *@s2: second string.
 *Return: returns a pointer to merged string
 */

char *merge_strings(char *s1, char *s2)
{
	char *new_string;

	unsigned int s1_len = _strlen(s1);
	unsigned int s2_len = _strlen(s2);
	int i = 0;

	new_string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));

	while (*s1)
	{
		new_string[i] = *s1;
		s1++;
		i++;
	}

	while (*s2)
	{
		new_string[i] = *s2;
		s2++;
		i++;
	}
	new_string[i] = '\0';

	return (new_string);

}
/**
 *make_copy - function to create a copy of a string.
 *@s1: copy of original string.
 *@s2: original string to create a copy from.
 */

void make_copy(char *s1, char *s2)
{
	int i = 0;

	while (*s2)
	{
		s1[i] = *s2;
		s2++;
		i++;
	}
	s1[i] = '\0';
}




/**
*_delim - checks for a delimeter
*@c: character to be checked
*@delim: delimeter
*Return: nothing
*/
unsigned int _delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
*my_strtok - a function for tokenizing a string
*@str: string to be tokenized
*@delim: delimeter
*Return: returns null when it reaches end else returns a string token
*/
char *my_strtok(char *str, char *delim)
{
	static char *bck_str;/* start of the next split */
	char *result;

	if (!str)
	{
		str = bck_str;
	}
	if (!str)
		return (NULL);
	while (1) /*handling start of the string containing delims*/
	{
		if (_delim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);/*reached end of the line*/
		break;
	}
	result = str;
	while (1)
	{
		if (*str == '\0')
		{
			bck_str = str;/*input end next execute returns NULL */
			return (result);
		}
		if (_delim(*str, delim))
		{
			*str = '\0';
			bck_str = str + 1;
			return (result);
		}
		str++;
	}
}


