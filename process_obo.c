#include "oboshell.h"

/**
 * process_obo - processes the built-in and the executable cmds
 * @args: arguments passed through
 *
 * Return: 0 if argument is empty and result on success
 */
int process_obo(char **args)
{
	int result = 1;
	int (*f)(char **);


	if (args[0] == NULL)
	{
		return (result);
	}
	f = get_obo_func(args[0]);

	if (f == NULL)
	{
		return (execute_obo(args));
	}

	return (f(args));
}

/**
 * process_mode - processes the built-in and the executables cmds
 * in non-interactive mode
 * @args: arguments passed
 * @read: read from standard input (stdin)
 *
 * Return: 0 if argument is empty and result on success
 */
int process_mode(char **args, char *read)
{
	int (*f)(char **);

	if (args[0] == NULL)
		exit(0);
	f = get_obo_func(args[0]);
	if (f == NULL)
		return (execute_mode(args, read));

	return (f(args));
}
