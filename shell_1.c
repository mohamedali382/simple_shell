#include "shell.h"
/**
* _CTD - check for errors
* @len: length of string
* @l: the line from user
* Return: void
*/
void _CTD(ssize_t len, char *l)
{
	(void) l;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_putchar('\n');
			free(l);
			exit(0);
		}
	}

}
/**
* main - execute commands
*
* Return: 0
*/
int main(void)
{
	ssize_t len;
	char *line = '\0', *fullpath, **ag, *envirs;
	size_t size = 0;
	struct linkp *dir;

	while (len != EOF)
	{
		ag = NULL;
		envirs = NULL;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		len = getline(&line, &size, stdin);
		if (len == -1 || _strcmp("exit\n", line) == 0)
		{
			free(line);
			break;
		}
		line[len - 1] = '\0';
		_CTD(len, line);
		ag = _strtok(line, " ");
		envirs = getenv("PATH");
		dir = linkpath(envirs);
		fullpath = findexec(ag[0], dir);
		if (!fullpath)
		{
			perror("hsh");
		}
		if (fullpath)
		{
			free(ag[0]);
			ag[0] = fullpath;
			exec(ag);
		}
		freeArgs(ag);
		freepath(dir);
	}
	free(line);
	free(fullpath);
	return (0);
}
