#include "oboshell.h"

/**
 * getline_obo - read user input from stdin
 * Return: buffer of character read from user
 */

char *getline_obo(void)
{
	char *buffer = malloc(sizeof(char) * BUFF_SIZE);
	ssize_t bytes_lgt;
	char ln = 0;
	int ti = 0;

	if (buffer == NULL)
		return (NULL);

	while (1)
	{
		bytes_lgt = read(STDIN_FILENO, &ln, 1);
		if (bytes_lgt == -1)
		{
			perror("read");
			free(buffer);
			return (NULL);
		}
		else if (bytes_lgt == 0)
		{
			free(buffer);
			return (NULL);
		}
		if (ln == '\n')
		{
			break;
		}
		if (ti + 1 >= BUFF_SIZE)
		{
			buffer = realloc(buffer, ti + 1);
			if (buffer == NULL)
			{
				perror("realloc");
				free(buffer);
				return (NULL);
			}
		}
		buffer[ti++] = ln;
	}
	buffer[ti] = '\0';
	return (buffer);
}
