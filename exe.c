#include "shell.h"
/**
* findexec - fing th executive command
* @args: arguments
* @head: struct
* Return: path of variable
*/
char *findexec(char *args, struct linkp *head)
{
	struct stat st;
	char *paths;
	char *dents;
	struct linkp *tmp = head;

	while (tmp)
	{
		size_t i = 0;

		dents = _strdup(tmp->d);
		if (args[0] == '/')
		{
			paths = _strdup(args);
			return (paths);
		}
		paths = malloc(sizeof(char) * 2 + _strlen(tmp->d) + _strlen(args));
		for (i = 0; i < _strlen(tmp->d); i++)
		{
			paths[i] = dents[i];
		}
		paths[i] = '\0';
		_strcat(paths, "/");
		_strcat(paths, args);
		if (stat(paths, &st) == 0)
		{
			return (paths);
		}
		free(paths);
		tmp = tmp->p;
	}
	return (NULL);
}
