#include "main.h"

extern char **environ;

char *getenv(const char *name)
{
	size_t i = 0, k= 0;
	char *en_var = NULL;

	while (environ[i] != NULL)
	{
		en_var = environ[i];
		k = 0;
		while (en_var[k] == name[k] && en_var[k] != '=' && name[k] != '\0')
			k++;
		if (name[k] == '\0')
			return (strdup(en_var));

		i++;
	}
}
