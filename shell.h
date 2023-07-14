#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int shell_interactive();
int shell_non_interactive();

char *get_line();

/*STINGS OPERATIONS*/
char *_duplicate(char *str);
void free_block(char **args);

unsigned int _strlen(char *str);
unsigned int count(char *lineptr);
char **tokenizer(char *delim, char *lineptr);
#endif
