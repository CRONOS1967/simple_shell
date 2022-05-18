#include "awshell.h"

/**
* _strspn - gets the length of a prefix substring
* @s: source
* @accept: string to find
* Return: bytes
**/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0, j = 0, cont = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0 ; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				cont++;
				break;
			}
		}
		if (s[i] != accept[j])
		{
			break;
		}
	}
	return (cont);
}
