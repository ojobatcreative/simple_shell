#include "oboshell.h"

/**
 * inputDefiner - Entry to the program
 * @read_len: length of the text
 * @text_cpy: copy of text
 *
 * Return: always 0 (success)
 */

char **inputDefiner(char *text_cpy, ssize_t read_len)
{
	char *delim = " \n";
	char *tkn;
	char **args;
	int ti;

	args = malloc(sizeof(char *) * read_len);
	ti = 0;

	tkn = strtok(text_cpy, delim);

	while (tkn != NULL)
	{
		args[ti] = tkn;
		tkn = strtok(NULL, delim);
		ti++;
	}
	args[ti] = NULL;

	return (args);
}
