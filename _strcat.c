#include "awshell.h"

/**
* _strcat - concatenates two strings
* @dest: destiny
* @src: source
* Return: concatenated string
**/
char *_strcat(char *dest, char *src)
{
	int sizedest = 0, sizesrc = 0;

	while (dest[sizedest] != '\0')
	{
		sizedest++;
	}
	while (src[sizesrc] != '\0')
	{
		dest[sizedest] = src[sizesrc];
		sizesrc++;
		sizedest++;
	}
	dest[sizedest] = '\0';
	return (dest);
}
