#include "awshell.h"

/**
* _strlen - calculate lenght of a string
* @s: char vector
* Return: the lenght of @s
**/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
