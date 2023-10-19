#include "oboshell.h"

/**
  *strcpy_obo - Entry to the program
  *@flat: where the source string is to be copied
  *@source: the source of string
  *Return: a cpoied string
  */

char *strcpy_obo(char *flat, char *source)
{
	int lgt = 0;
	int tx;

	while (source[lgt] != '\0')
		lgt++;

	for (tx = 0; tx <= lgt; tx++)
		flat[tx] = source[tx];

	return (flat);
}
