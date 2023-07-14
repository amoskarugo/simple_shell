#include "shell.h"


int main(int ac, char *argv[], char *envp[])
{
	unsigned int i = 7;

	if(isatty(STDIN_FILENO) == 1)
	{
		shell_interactive();
	}else
	{
		shell_non_interactive();
	}
	return (0);
}
