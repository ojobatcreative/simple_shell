#include "oboshell.h"
/**
  *get_obo_func - Entry to the function
  *@s: a pointer to the string
  *Return: Always 0 (success)
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

	if (s == NULL || strlen_obo(s) == 0)
		return (NULL);

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
	return (1);
}


/**
 * cd_obo - command use for changing directory
 * @args: arguments comprises of command and directory
 *
 * Return: 0 to indicate successful execution
 */
int cd_obo(char **args)
{
	char *prvDir;
	const char *path;
	char crntDir[PATH_MAX_LENGTH];
	int rVal;

	if (args[1] == NULL)
	{
		rVal = chdir(getenv("HOME"));
	}
	else if (args[1] != NULL)
	{
		path = args[1];
		rVal = chdir(path);

		if (strcmp_obo(args[1], "-") == 0)
		{
			prvDir = getenv("OLDPWD");
			rVal = chdir(prvDir);
		}
	}
	else
	{
		perror("cd error");
		return (1);
	}

	if (rVal != -1)
	{
		getcwd(crntDir, sizeof(crntDir));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", crntDir, 1);
	}
	else if (rVal == -1)
	{
		perror("hsh");
		return (1);
	}

	return (0);

}
