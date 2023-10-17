#include "oboshell.h"

/**
 * process_obo - processes the built-in and the executable commands
 * @args: arguments passed
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
