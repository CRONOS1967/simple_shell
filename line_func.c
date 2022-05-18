#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#include "main.h"

/**
 * *execute_line - Parses the command line looking for commands and arguments.
 *
 * Return: 0 on success
 */

char *execute_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t n_bytes;

	printf("#cisfun$:");

	n_bytes = getline(&line, &bufsize, stdin);
	line[n_bytes - 1] = '\0';
	/*printf("%s\n", line);*/
	return (line);
}

/**
 * **to_args - recieves strings and turn it into array of args
 * cmdstr - parameter holding the value
 * Return: array of string
 *
 */
char **to_args(char *cmdstr)
{
	char *str = NULL;
	char **args = NULL;
	size_t max_args = 7;
	size_t args_count = 0;
	char *delim = " ";

	args = malloc(sizeof(*args) * max_args);

	str = strtok(cmdstr, delim);

	while (str && args_count < max_args - 1)
	{
		args[args_count++] = str;
		str = strtok(NULL, delim);
	}

	args[args_count] = NULL;
	return (args);
}

char *locate(const char *name)
{
	char *path = getenv("PATH");
	char *dir_path = NULL;
	char *file_path = NULL;

	if(file_exists(name))
		return (strdup(name));

	strtok(path, "=");
	dir_path = strtok(NULL, ":");
	while(dir_path)
	{
		file_path = join_paths('/', dir_path, name);
		if (file_exists(file_path))
		{
			break;
			free(path);
			return (file_path);
		}
		free(file_path);
		file_path = NULL;

		dir_path = strtok(NULL, ":");
	}
	free(path);
	return (file_path);
}

char *join_paths(const char sep, const char *path1, const char *path2)
{
	size_t i = 0, k = 0;
	size_t len = 0;
	char *joined = NULL;

	while(path1[i++] != '\0')
	;
	len += i;

	i = 0;
	while(path2[i++] != '\0')
		;
	len += i;
	len += 1;

	joined = malloc(sizeof(*joined) * (len + 1));

	i = 0;
	while(path1[k])
	{
		joined[i] = path1[k];
		i++;
		k++;
	}

	joined[i++] = sep;
	k = 0;
        while(path2[k])
        {
                joined[i] = path2[k];
                i++;
                k++;
	}

	joined[i] = '\0';
	return (joined);
}

int file_exists(const char *filepath)
{
	struct stat buffer;

	if (stat(filepath, &buffer) == 0)
		return (1);

	return (0);
}
