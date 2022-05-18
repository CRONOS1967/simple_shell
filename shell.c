#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "main.h"

/*
 * main - body of the program
 */

extern char **environ;

int main(void)
{
	char *cmd = NULL;
	char *args[] = {NULL, NULL};
	size_t buff_size = 0;
	size_t n_read = 0;
	char *cmd_path = NULL;
	
	while (1)
	{
		printf("cisfun$: ");
		n_read = getline(&cmd, &buff_size,stdin);
		cmd[n_read - 1] = '\0';

		cmd_path = locate(cmd);
		if (cmd_path)
		{
			args[0] = cmd_path;
			if (fork() == 0)
				execve(*args, args, NULL);
			else
			{
				wait(NULL);
				free(cmd_path);
				cmd_path = NULL;
			}
		}
		else
			dprintf(STDERR_FILENO, "%s: command not found\n", cmd);
	}
		return (0);

}
