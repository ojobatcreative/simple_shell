#include "oboshell.h"

/**
  *strdup_obo - Entry to the function
  *@s: a points to a cosnt. string
  *Return: new copied string
  */

char *strdup_obo(char *s)
{
	size_t lgt = strlen_obo(s) + 1;
	char *n_s = malloc(lgt);

	if (n_s == NULL)
	{
		perror("malloc error");
		return (NULL);
	}

		strcpy_obo(n_s, s);

		return (n_s);
}
