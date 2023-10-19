#include "oboshell.h"

/**
 * handle_path - handling the PATH
 * @obo: command to be handled
 *
 * Return: full path om success & NULL if
 * there is error
 */
char *handle_path(char *obo)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char *full_path = malloc(sizeof(char) * PATH_MAX_LENGTH);
	char *obo_cpy;

	if (access(obo, X_OK) == 0)
	{
		obo_cpy = strdup_obo(obo);
		return (obo_cpy);
	}

	while (dir != NULL)
	{
		strcpy_obo(full_path, dir);
		strcat_obo(full_path, "/");
		strcat_obo(full_path, obo);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		dir = strtok(NULL, ":");
	}

	free(full_path);
	return (NULL);
}
