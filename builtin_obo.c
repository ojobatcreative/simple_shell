#include "oboshell.h"

/**
 * get_obo_func - Entry to the function
 * @s: a pointer to the string
i * Return: Always 0 (success)
 */

int (*get_obo_func(char *s))(char **)
{
	builtinobo built[] = {
		{"exit", exit_obo},
		{"env", env_obo},
		{"cd", cd_obo},
		{NULL, NULL}
	};
	int ti = 0;

	while (built[ti].obo != NULL && strcmp_obo(built[ti].obo, s) != 0)
		ti++;

	return (built[ti].f);
}

/**
 * exit_obo - exits the shell
 * @args: parameter argument
 * Return: 0 to exit
 */

int exit_obo(char **args)
{
	int status;

	if (args[1] != NULL)
	{
		status = atoi_obo(args[1]);
		exit(status);
	}
	else
	{
		exit(0);
	}
}

/**
 * env_obo - prints the current environment
 * @args: parameter argument
 *
 * Return: always 0
 */
int env_obo(char **args)
{
	int ti;

	(void)**args;

	for (ti = 0; environ[ti] != NULL; ti++)
	{
		printf("%s\n", environ[ti]);
	}
	return (0);
}


/**
 * cd_obo - this is used for changing directory
 * @args: arguments comprises of command and directory
 *
 * Return: 0 to indicate successful execution
 */
int cd_obo(char **args)
{
	char *prvDir;
	const char *path;
	char crntDir[PATH_MAX_LENGTH];
	int rtrn_val;

	if (args[1] == NULL)
	{
		rtrn_val = chdir(getenv("HOME"));
	}
	else if (args[1] != NULL)
	{
		path = args[1];
		rtrn_val = chdir(path);

		if (strcmp_obo(args[1], "-") == 0)
		{
			prvDir = getenv("OLDPWD");
			rtrn_val = chdir(prvDir);
		}
	}
	else
	{
		perror("cd error");
		return (1);
	}

	if (rtrn_val != -1)
	{
		getcwd(crntDir, sizeof(crntDir));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", crntDir, 1);
	}
	else if (rtrn_val == -1)
	{
		perror("hsh");
		return (1);
	}

	return (0);
}
