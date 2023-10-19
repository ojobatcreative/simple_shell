:#include "oboshell.h"

/**
 * execute_obo - execute commands
 * @args: arguments
 *
 * Return: 0 always success
 */

int execute_obo(char **args)
{
	pid_t pid = fork();
	int stats;

	if (pid == 0)
	{
		if (args[0][0] != '/')
		{
			char *full_path = handle_path(args[0]);

			if (full_path != NULL)
			{
				if (execve(full_path, args, environ) != -1)
				{
					fprintf(stderr, "%s: command not found\n", args[0]);
					exit(127);
				}
			}
			else
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				exit(127);
			}
		}
		else
		{
			if (execve(args[0], args, environ) == -1)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				return (0);
			}
		}
	}
	else if (pid < 0)
		perror("fork");
	else
		waitpid(pid, &stats, 0);
	return (127);
}
