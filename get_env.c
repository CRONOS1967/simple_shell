#include "awshell.h"

/**
 * get_env - get the environment
 * @str: string where the enviroment is
 * Return: Result
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
char *get_env(char *str)
{

	int i = 0;
	char *copy1 = NULL;
	char **temp = NULL, *res = NULL;
	char *copy2 = NULL;

	(void)str;
	while (environ[i] != NULL)
	{
		copy1 = _strdup(environ[i]);
		temp = split_str(copy1, "=");
		if (_strcmp(temp[0], str) == 0)
		{	copy2 = _strdup(environ[i]);
			res = _strdup(_strchr(copy2, '='));
			free_single(copy2);
		}
		free_single(copy1);
		free_double(temp);
		i++;
	}
	return (res);
}
