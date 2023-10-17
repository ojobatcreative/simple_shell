#include "oboshell.h"

/**
 * tokenize_line - split line of arguments
 * @read: The input string to be split into tokens.
 *
 * Return: An array of split arguments (tokens)
 */

char **tokenize_line(char *read)
{
	char *tkn, *read_copy;
	char **tkns = NULL;
	char delim[] = "\t\r\n\a";
	int ti = 0;

	read_copy = strdup(read);

	tkn = strtok(read_copy, delim);
	while (tkn != NULL)
	{
		ti++;
		tkn = strtok(NULL, delim);
	}

	tkns = (char **)malloc((ti + 1) * sizeof(char *));
	if (tkns == NULL)
	{
		perror("malloc");
		exit(1);
	}

	tkn = strtok_obo(read_copy, delim);
	while (tkn != NULL)
	{
		tkns[ti] = strdup(tkn);
		tkn = strtok_obo(NULL, delim);
		ti++;
	}
	tkns[ti] = NULL;

	free(read_copy);

	return (tkns);
}
