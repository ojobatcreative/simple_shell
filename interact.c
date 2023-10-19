#include "oboshell.h"

/**
 * signal_handle - handles signals
 * @sig: signal to be handled
 */

void signal_handle(int sig)
{
	if (sig == SIGINT)
		write(1, "\n(OBOshell)$: ", 14);
}
/**
 * interact_mode - Enter the shell
 *
 * Return: always 0 (success)
  */

void interact_mode(void)
{
	char *read = NULL;
	size_t len = 0;
	ssize_t nread;
	int process = 1;
	char **args;

	signal(SIGINT, signal_handle);
	while (process == 1)
	{
		printf("(OBOshell) $: ");
		nread = getline(&read, &len, stdin);

		if (nread == -1)
		{
			write(1, "Exiting...\n", 12);
			exit(0);
		}
		args = tokenize_line(read, nread);
		process_obo(args);

		free(args);
	}
	free(read);
}
