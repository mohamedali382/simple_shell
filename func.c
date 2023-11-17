#include "shell.h"
/**
* _strtok - strtok for string
* @tok: first string
* @delim: second string
* Return: address of new string
*/
char **_strtok(char *tok, const char *delim)
{
	char **args = NULL;
	char *token;
	int i = 0;

	token = strtok(tok, delim);
	while (token)
	{
		args = _realloc(args, (i + 1) * sizeof(char *));
		if (!args)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}

		args[i] = _strdup(token);
		if (!args[i])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, delim);
		i++;
	}

	args = _realloc(args, (i + 1) * sizeof(char *));
	if (!args)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	args[i] = NULL;

	return (args);
}
/**
* _realloc - resize the array
* @ptrr: pointer
* @size: size
* Return: pointer
*/

void *_realloc(void *ptrr, size_t size)
{
	void *new_ptr;
	size_t i;

	if (size == 0)
	{
		free(ptrr);
		return (NULL);
	}

	if (ptrr == NULL)
		return (malloc(size));

	new_ptr = malloc(size);

	if (new_ptr != NULL)
	{
		char *old_ptr = (char *)ptrr;
		char *new_ptr_char = (char *)new_ptr;
		size_t copy_size = size;
		size_t old_size = 0;

		while (old_ptr[old_size] != '\0')
		{
			old_size++;
		}

		if (old_size < size)
		{
			copy_size = old_size;
		}

		for (i = 0; i < copy_size; i++)
		{
			new_ptr_char[i] = old_ptr[i];
		}

		free(ptrr);
	}

	return (new_ptr);
}
/**
* freeArgs - free the memory lack
* @ag: arguments
* Return: void
*/
void freeArgs(char **ag)
{
	size_t i = 0;

	for (i = 0; ag[i] != NULL; i++)
	{
		free(ag[i]);
	}
	free(ag);
}
