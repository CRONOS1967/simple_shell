#include "awshell.h"

/**
* exec - executes applications
* @buffer: arguments to execute
* @counter: counting of every command typed
* @shellav: name of the first argument non interactive
* Return: 0 on success
*                     _
*     /\             | |
*    /  \   _ __   __| |_   _
*   / /\ \ | '_ \ / _` | | | |
*  / ____ \| | | | (_| | |_| |
* /_/    \_\_|_|_|\__, |\__, | _   _
* \ \        / (_)   | | __/ || \ | |
*  \ \  /\  / / _ ___| ||___/ |  \| |
*   \ \/  \/ / | / __| __/ _ \| . ` |
*    \  /\  /  | \__ \ || (_) | |\  |
*     \/  \/   |_|___/\__\___/|_| \_| |- Nov 2020 -|
*
*/
int exec(char **buffer, unsigned int counter, char *shellav)
{
	pid_t child_pid;
	int child_status, error_code;
	char *path = NULL;
	char *c_counter = NULL;

	path = _which(buffer[0]);
	if ((path == NULL) && buffer[0] != NULL)
	{
		free_single(path);
		c_counter = itos(counter);
		print_error2(c_counter, buffer[0], shellav);
		free_single(c_counter);
		return (127);
	}
	free_single(path);
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(buffer[0], buffer, environ) == -1)
		{
			c_counter = itos(counter);
/*			execve(buffer[0], buffer, environ);*/
			print_error2(c_counter, buffer[0], shellav);
			free_single(c_counter), exit(errno);
		}
		else
		{
			exit(errno);
		}
	}
	else if (child_pid < 0)
		return (errno);
	wait(&child_status);
	if (WIFEXITED(child_status))
		error_code = WEXITSTATUS(child_status);
	return (error_code);
}
