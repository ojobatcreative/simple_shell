#include "oboshell.h"

/**
 *strdup_obo - Entry to the function
 *@s: a pointer to a cosntant string
 *Return: new copied string
 */

char *strdup_obo(char *s)
{
	size_t lgt = strlen_obo(s) + 1;
	char *fresh_s = malloc(lgt);

	if (fresh_s == NULL)
	{
		perror("malloc error");
		return (NULL);
	}

	strcpy_obo(fresh_s, s);

	return (fresh_s);
}
