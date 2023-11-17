#include "shell.h"

/**
 * empty_line - checks if there is an empty line
 * @l: line to be checked
 * Return: 0 or 1
 */

int empty_line(char *l)
{
	int i = 0;

	while (l[i] != '\0')
	{
		if (l[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
