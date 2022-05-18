#include "awshell.h"

/**
 * main - prints "aw$ ", wait for the user to enter a command,
 * to execute different programs.
 * @ac: number of arguments.
 * @av: arguments
 * Return: Always 0
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
int main(int ac, char *av[])
{
	char *buff = NULL, *buff_w = NULL, **buff_split = NULL;
	char *cmd = NULL;
	size_t len = 0, counter = 0;
	int x = 0, check_b, error_code = 0;

	(void)ac, (void)av;
	if (isatty(STDIN) != 0)
		write(STDOUT, "$ ", 2);
	signal(SIGINT, ctrap);
	while ((x = getline(&buff, &len, stdin)) != -1)
	{
		counter++;
		buff[x - 1] = '\0';
		buff_split = split_str(buff, " ");
		buff_w = buff_split[0];
		check_b = get_builtins(buff, buff_split, error_code);
		cmd = _which(buff_w);
		if ((cmd != NULL) && (_strcmp(cmd, buff_w) != 0))
		{
			free_single(buff_split[0]);
			if (buff_split[0])
				buff_split[0] = _strdup(cmd);
		}
		if (check_b != 0 && buff_w != NULL)
			error_code = exec(buff_split, counter, av[0]);
		if (check_b == 0)
			error_code = 0;
		free_double(buff_split);
		free_single(cmd);
		if (isatty(STDIN) != 0)
			write(STDOUT, "$ ", 2);
	}
	if (isatty(STDIN) != 0)
	{
		write(STDOUT, "\n", 1);
	}
	free_single(buff);
	return (error_code);
}
