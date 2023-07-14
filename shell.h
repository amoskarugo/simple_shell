#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int shell_interactive(char **args, char **envp_vars);
int shell_non_interactive(void);
int _execCmd(int count, char **args,char **argv, char **env_vars);
char *get_line();

/*STINGS OPERATIONS*/
char *_duplicate(char *str);
void free_block(char **args);

unsigned int _strlen(char *str);
unsigned int count(char *lineptr);
char **tokenizer(char *delim, char *lineptr);
#endif
