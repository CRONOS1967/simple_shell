#include "awshell.h"
/**
 * strtok_h - tokenizer
 * @string: source string
 * @delim: delim character
 * @sptr: the remain of the array
 * Return: return a pointer to the first ocur +1
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
char *strtok_h(char *string, char *delim, char **sptr)
{
	char *end;

	if (string == NULL)
		string = *sptr;
	if (*string == '\0')
	{
		*sptr = string;
		return (NULL);
	}
	/* Scan leading delimiters.  */
	string = string + _strspn(string, delim);
	if (*string == '\0')
	{
		*sptr = string;
		return (NULL);
	}
	/* Find the end of the token.  */
	end = string + _strcspn(string, delim);
	if (*end == '\0')
	{
		*sptr = end;
		return (string);
	}
	/* Terminate the token and make *sptr point past it.  */
	*end = '\0';
	*sptr = end + 1;
	return (string);
}

/**
 * _strtok - tokenizer
 * @string: source string
 * @delim: delim character
 * Return: return a pointer to the first character
 */
char *_strtok(char *string, char *delim)
{
	static char *remain;

	return (strtok_h(string, delim, &remain));
}
