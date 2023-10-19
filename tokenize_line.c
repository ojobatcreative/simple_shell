#include "oboshell.h"

/**
 * tokenize_line - splits arguments
 * @read: length of the arguments
 * @nread: read count
 *
 * Return: split arguments in tokens
 */

char **tokenize_line(char *read, ssize_t nread)
{
	char *tkn;
	char **tkns = malloc(sizeof(char *) * (nread / 2 + 1));
	char *delim = "\n\t\r\a ";
	int ti = 0;

	if (tkns == NULL)
	{
		perror("malloc");
		exit(1);
	}

	tkn = strtok(read, delim);

	while (tkn != NULL)
	{
		tkns[ti] = tkn;
		tkn = strtok(NULL, delim);
		ti++;
	}
	tkns[ti] = NULL;

	return (tkns);
}
