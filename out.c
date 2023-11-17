#include "shell.h"

/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 * Return: value of comparison
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
/**
 * _strcpy - function that copies the string pointed to by src
 * @dest: pointer
 * @src: ponter
 * Return: @dest
 */
char *_strcpy(char *dest, char *src)
{
	char *c = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (c);
}
/**
 * _split - split string
 * @str: string to be splitted
 * @separator: separator
 * Return: splitted string
 */

char **_split(char *str, char *separator)
{
	char *token, **split_str;
	int i = 0;

	token = strtok(str, separator);
	split_str = (char **)_realloc(100, sizeof(char *));

	if (!split_str)
	{
		free(split_str);
		return (NULL);
	}

	while (token)
	{
		split_str[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	return (split_str);
}
