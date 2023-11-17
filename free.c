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

/**
 * _strcat - concatenate two srtings
 * @dest: string 1
 * @src: string 2
 * Return: the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - calculate the length of a string
 * @s: string we want to calculate its length
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0';)
	{
		i++;
	}
	return (i);
}
