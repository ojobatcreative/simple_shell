#include "oboshell.h"

/**
  *strncat_obo - Entry to the code
  *@flat: place where the source string is appended
  *@source: the source
  *@number: number unto the source
  *Return: pointer to flat
  */
char *strncat_obo(char *flat, char *source, int number)
{
	int tx;
	int lgt = strlen_obo(flat);

	for (tx = 0; source[tx] != source[number]; tx++, lgt++)
	{
		flat[lgt] = source[tx];
	}

	return (flat);
}
