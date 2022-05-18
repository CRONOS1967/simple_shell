#include "awshell.h"

/**
 * split_str - separates strings into count
 * @buff: string to divide
 * @delim: delimiter
 * Return: pointers to each word on the array
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
char **split_str(char *buff, char *delim)
{
	char *token, *token2, *buff_copy;
	int count = 0, i = 0;
	char **wordarray;

	buff_copy = _strdup(buff);
	token = strtok(buff, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		count++;
	}
	token2 = strtok(buff_copy, delim);
	wordarray = malloc(sizeof(char *) * (count + 1));
	while (token2 != NULL)
	{
		wordarray[i] = _strdup(token2);
		token2 = strtok(NULL, delim);
		i++;
	}
	wordarray[i] = NULL;
	free_single(buff_copy);
	return (wordarray);
}
