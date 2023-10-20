#include "oboshell.h"

/**
 * setenv_obo - executing the tokenized arguments
 * @name: call
 * @value: from value
 *
 * Return: void
 */

void setenv_obo(char *name, char *value)
{
	if (setenv(name, value, 1) == -1)
	{
		fprintf(stderr, "Failed to set environment variable.\n");
	}
}
