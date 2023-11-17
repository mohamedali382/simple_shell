#include "shell.h"

/**
 * main - entry point
 * Return: 0 on success
 */

int main(void)
{
	char *line = NULL, **ags;
	int ex = 0;
	size_t size = 0;
	ssize_t buffer = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		buffer = getline(&line, &size, stdin);
		if (buffer == -1 || _strcmp("exit\n", line) == 0)
		{
			free(line);
			break;
		}
		line[buffer - 1] = '\0';

		if (_strcmp("env", line) == 0)
		{
			print_env();
			continue;
		}

		if (empty_line(line) == 1)
		{
			ex = 0;
			continue;
		}

		ags = _split(line, " ");
		ags[0] = search_path(ags[0]);

		if (ags[0] != NULL)
			ex = exec(ags);
		else
			perror("Error");
		free(ags);
	}
	return (ex);
}
