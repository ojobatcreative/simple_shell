#include "oboshell.h"

/**
 * unsetenv_obo - executing the tokenized arguments
 * @name: environment name
 *
 * Return: void
 */

void unsetenv_obo(char *name)
{
	if (unsetenv(name) == -1)
	{
		fprintf(stderr, "Failed to unset environment variable.\n");
	}
}
