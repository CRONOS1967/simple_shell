#include "main.h"
#include <stdlib.h>

char *strdup(const char *str)
{
	size_t i = 0;
	size_t len = 0;
	char *_str = NULL;

	while(str[i++])
		;
	len += i;

	_str = malloc(sizeof(*_str) * (len + 1));

	i = 0;
	while (i <= len)
	{
		_str[i] = str[i];
		i++;
	}

	return (_str);
}
