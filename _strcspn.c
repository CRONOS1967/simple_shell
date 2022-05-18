#include "awshell.h"

/**
* _strcspn - gets the length of a prefix substring
* @string: source
* @accept: string to find
* Return: bytes
**/
unsigned int _strcspn(char *string, char *accept)
{
	unsigned int i = 0, j = 0, sw = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		for (j = 0 ; accept[j] != '\0'; j++)
		{
			if (string[i] == accept[j])
			{
				return (i);
			}
		}
	}
	return (sw);
}
