#include "shell.h"

/**
 * search_path - search file between the path
 * @cmd: the command
 * Return: command path
 */

char *search_path(char *cmd)
{
	int j = 0, len = 0;
	char *path = _getenv("PATH");
	char *copy, *conc = NULL;
	char **path_strtok;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (cmd);

	copy = malloc(_strlen(path) + 1);

	copy = _strcpy(copy, path);
	path_strtok = _split(copy, ":");

	while (path_strtok[j])
	{
		len = _strlen(path_strtok[j]);

		if (path_strtok[j][len - 1] != '/')
			conc = _strcat(path_strtok[j], "/");

		conc = _strcat(path_strtok[j], cmd);

		if (stat(conc, &st) == 0)
			break;

		j++;
	}

	free(copy);

	if (!path_strtok[j])
	{
		free(path_strtok);
		return (NULL);
	}

	free(path_strtok);
	return (conc);
}
