#include "oboshell.h"

/**
 * main - entry point
 *
 * Return: 0 always on success
 */

int main(void)
{
	char *read = NULL;
	char **args;

	if (isatty(STDIN_FILENO) == 1)
	{
		interact_mode();
	}
	else
	{
		while ((read = getline_obo()) != NULL)
		{
			args = tokenize_line(read);
			process_obo(args);
			free(args);
		}
		free(read);
	}
	return (0);
}
