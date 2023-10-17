#include "oboshell.h"

/**
 * strcat_obo - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: pointer to the destination string.
 */
char *strcat_obo(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (original_dest);
}
