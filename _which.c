#include "awshell.h"

/**
 * _which - creates a full path for a command
 * @buff: arguments
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
char *_which(char *buff)
{
	struct stat st;
	p_list *head = NULL, *copyhead = NULL;
	unsigned int totalsize = 0, size1 = 0, size2 = 0;
	char *fullpath = NULL;

	if (buff == NULL || stat(buff, &st) == 0 || buff[0] == '/')
		return (_strdup(buff));
	head = path_list();
	copyhead = head;
	size1 = _strlen(buff);
	while (copyhead != NULL)
	{
		size2 = _strlen((*copyhead).str);
		totalsize = size1 + size2;

		fullpath = malloc(sizeof(char) * (totalsize + 3));
		if (fullpath == NULL)
		{
			return (NULL);
		}
		_memcpy(fullpath, (*copyhead).str, size2);
		_memcpy(fullpath + size2, "/", 1);
		_memcpy(fullpath + size2 + 1, buff, size1 + 1);
		fullpath[totalsize + 2] = '\0';

		if (stat(fullpath, &st) == 0)
		{
			free_list(head);
			return (fullpath);
		}
		free_single(fullpath);
		copyhead = (*copyhead).next;
	}
	free_list(head);
	return (NULL);
}
