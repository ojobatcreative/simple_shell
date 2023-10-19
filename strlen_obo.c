#include "oboshell.h"

/**
  *strlen_obo - Entry to the function
  *@strg: pointer to a strg
  *Return: the initial counter
  */

int strlen_obo(char *strg)
{
	int begin = 0;

	while (strg[begin] != '\0')
		begin++;

	return (begin);
}
