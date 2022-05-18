#include "awshell.h"

/**
 * _env - prints the environment
 * @env: environment
 * Return: Always 0.
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
int _env(char **ptr)
{
	unsigned int i = 0, size = 0;

	(void)ptr;
	while (environ[i])
	{
		size = _strlen(environ[i]);
		write(STDOUT, environ[i], size);
		write(STDOUT, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * exitshell - exits the shell
 * @buff: name of the environment var to free
 * @error_code: error code from previuos execution
 * @buff_split: buffer tokenized to free
 * Return: Always 0.
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
int exitshell(char **buff_split, char *buff, int error_code)
{
	(void)buff_split;
	(void)buff;

	free_double(buff_split);
	free_single(buff);
	/*
*	free_single(buff);
*	free_double(buff_split);
*/
	exit(error_code);
}

/**
 * _setenv - exits the shell
 * @ptr: buffer tokenized to free
 * Return: Always 0.
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
int _setenv(char **ptr)
{
	(void)ptr;
	return (0);
}

/**
 * _unsetenv - exits the shell
 * @ptr: buffer tokenized to free
 * Return: Always 0.
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
int _unsetenv(char **ptr)
{
	(void)ptr;
	return (0);
}

/**
 * _help - exits the shell
 * @ptr: buffer tokenized to free
 * Return: Always 0.
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
int _help(char **ptr)
{
	(void)ptr;
	return (0);
}
