#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#define BUF_SIZE 6144
extern char **environ;
/**
 *struct builtin_funcs - structure for built in functions
 *@cmd: name of the command
 *@function: function pointer
 *
 */
typedef struct builtin_funcs
{
	char *cmd;
	int (*function)(char **);
} built_in;

/*BUILT IN FUNCTIONS PROTOTYPES*/

int shell_exit(char *args[]);
int print_env(char *envp_vars[]);
int my_cd(char *args[]);
int my_help(char *args[]);
int _setenv(char *args[]);

int shell_interactive(char **args, char **envp_vars);
int shell_non_interactive(char *args[], char *envp_vars[]);
int _execCmd(int count, char **args, char **argv, char **env_vars);
int execute_cmd(int counter, char *args[], char *argv[], char *envp_vars[]);
char *get_line();
char *path(char *cmd[], char *envp_vars[]);
int my_atoi(const char *s);
void _sigHandler(__attribute__((unused))int num);
void error_msg(int counter, char *args[], char *argv[]);
/*STINGS OPERATIONS*/
char *_duplicate(char *str);
void make_copy(char *s1, char *s2);
void free_block(char **args);
char *merge_strings(char *s1, char *s2);
char *my_strtok(char *str, char *delim);
unsigned int _delim(char c, char *delim);
ssize_t read_input(char **line, size_t *bytes);

unsigned int _strlen(char *str);
bool multi(char *args[]);
unsigned int count(char *lineptr, char *delim);
int custom_strncmp(char *s1, char *s2, int sz);
char **tokens_generator(char *lineptr, char *delim);
#endif
