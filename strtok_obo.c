#include "oboshell.h"

/**
 * check_delim - check for delimiter in the character
 * @c: character
 * @delim: delimiter
 *
 * Return: 0 if it's not a delimiter & 1 if it is
 */
int check_delim(const char *delim, char c)
{
	unsigned int ti;

	for (ti = 0; delim[ti] != '\0'; ti++)
	{
		if (c == delim[ti])
			return (true);
	}
	return (false);
}

/**
 * strtok_obo - split a string into tokens (token = tkn)
 * @str: string
 * @delim: delimiter
 * Return: NULL or pointer to the following token
 */

char *strtok_obo(char *str, const char *delim)
{
	static char *tkn;
	char *tkns = NULL;

	if (str != NULL)
	{
		tkn = str;
	}

	if (tkn == NULL || *tkn == '\0')
	{
		return (NULL);
	}

	while (*tkn != '\0' && check_delim(delim, *tkn))
	{
		tkn++;
	}

	if (*tkn == '\0')
	{
		tkn = NULL;
		return (NULL);
	}

	tkns = tkn;

	while (*tkn != '\0' && !check_delim(delim, *tkn))
	{
		tkn++;
	}

	if (*tkn != '\0')
	{
		*tkn++ = '\0';
	}

	return (tkns);

}
