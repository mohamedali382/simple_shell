#include "shell.h"

/**
 * _realloc - allocates memory for an array, using malloc
 * @xim: array to which memory will be allocated
 * @size: size of array
 * Return: pointer or NULL
 */

void *_realloc(unsigned int xim, unsigned int size)
{
	char *ptr = NULL;
	unsigned int i = 0;

	if (xim == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(xim * size);
	if (ptr == NULL)
		return (NULL);

	while (i < (xim * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
