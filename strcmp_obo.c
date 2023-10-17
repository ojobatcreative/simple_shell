#include "oboshell.h"

/**
  *strcmp_obo - Entry point
  *@string1: pointer to the first string
  *@string2: pointer to the second sting
  *Return: differnece
  */

int strcmp_obo(const char *string1, const char *string2)
{
	while (*string1 == *string2 && (*string1 != '\0' && *string2 != '\0'))
	{
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}
