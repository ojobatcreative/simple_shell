#include "oboshell.h"

/**
  *strlen_obo - Entry to the function
  *@string: points to a string
  *Return: the initial counter
  */

int strlen_obo(char *string)
{
	int start = 0;

	while (string[start] != '\0')
		start++;

	return (start);
}
