#include "awshell.h"

/**
 * path_list - builds the environment list
 * Return: pointer to the head list
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
p_list *path_list(void)
{
	char *env_value;
	char **entries;
	char *temp;
	int i = 0, size_path;
	p_list *head = NULL;

	env_value = get_env(PATH);
	if (env_value[0] == ':')
	{
		size_path = _strlen(env_value);
		temp = malloc(sizeof(char) * (size_path + 2));
		temp[0] = '.';
		for (; env_value[i]; i++)
		{
			temp[i + 1] = env_value[i];
		}
		temp[i] = '\0';
		entries = split_str(temp, ":");
	}
	else
	{
		entries = split_str(env_value, ":");
	}
	i = 0;
	while (entries[i] != NULL)
	{
		add_list(&head, entries[i]);
		i++;
	}
	free_single(env_value);
	free_double(entries);
	return (head);
}
