#include "shell.h"
/**
 * _getenv - gets env variable
 * @env: env variable
 * Return: value of env variable
 */

char *_getenv(char *env)
{
	int i = 0;
	int j = 0;
	int sit;

	while (environ[i])
	{
		sit = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != env[j])
				sit = 0;
		}
		if (sit == 1)
			break;
		i++;
	}
	return (&environ[i][j + 1]);
}

/**
 * printe - prints environment variables
 */
void printe(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
