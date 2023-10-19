#include "oboshell.h"

/**
  *strcmp_obo - Entry point
  *@strg1: pointer to the first string
  *@strg2: pointer to the second sting
  *Return: differnece
  */

int strcmp_obo(char *strg1, char *strg2)
{
	while (*strg1 == *strg2 && (*strg1 != '\0' && *strg2 != '\0'))
	{
		strg1++;
		strg2++;
	}
	return (*strg1 - *strg2);
}
