#include "shell.h"
/**
* _strlen - count the string length
* @ag: arguments
* Return: number of characters
*/
size_t _strlen(const char *ag)
{
	size_t i = 0;

	while (ag[i])
	{
		i++;
	}
	return (i);
}
/**
* _strcat - concatenates two strings
* @paths: 1st string
* @temp: 2nd string
* Return: 1st string
*/
char *_strcat(char *paths, const char *temp)
{
	size_t length = _strlen(paths);
	size_t i;

	for (i = 0; temp[i] != '\0'; i++)
	{
		paths[length + i] = temp[i];
	}

	paths[length + i] = '\0';
	return (paths);
}
/**
* _strdup - dup
* @str: string
* Return: new string
*/
char *_strdup(const char *str)
{
	size_t length = _strlen(str), i = 0;
	char *new_str = malloc((length + 1) * sizeof(char));

	if (!new_str)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i <= length; i++)
	{
		new_str[i] = str[i];
	}

	return (new_str);
}
