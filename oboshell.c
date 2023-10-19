#include "oboshell.h"

/**
 * handle_multiString - it handle string with muilti-line
 * @args: arguments
 * @argv: first argument from stdin
 */
void handle_multiString(char **args, char *argv)
{
	int status, numTokens, ti;

	numTokens = 0;
	while (args[numTokens] != NULL)
		numTokens++;

	for (ti = 0; ti < numTokens; ti++)
	{
		status = process_mode(args, argv);
		if (status == 0)
		{
			execute_mode(args, argv);
		}
	}
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments passed
 *
 * Return: 0 always on success
 */
int main(int argc, char **argv)
{
	char *read = NULL;
	char **args;
	int status, ti;
	size_t len = 0;
	ssize_t nread;

	(void)argc;

	if (isatty(STDIN_FILENO) == 1)
	{
		interact_mode();
	}
	else
	{
		while ((nread = getline(&read, &len, stdin)) != -1)
		{
			args = tokenize_line(read, nread);
			for (ti = 0; argv[ti] != NULL; ti++)
			{
				if (strchr(read, '\n') != NULL)
					handle_multiString(args, argv[0]);
				else
				{
					status = process_mode(args, argv[0]);
					if (status == 0)
						execute_mode(args, argv[0]);
				}
			}
			free(args);
		}

		free(read);
	}

	return (0);
}
