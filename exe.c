#include "shell.h"

/**
 * exec - execute command path
 * @ag: array of arguments
 * Return: st
 */

int exec(char **ag)
{
	int id = fork();
	int st;

	if (id == 0)
	{
		/*execute the command*/
		if (execve(ag[0], ag, environ) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		/*parent process wait for the child*/
		wait(&st);
		if (WIFEXITED(st))
			st = WEXITSTATUS(st);
	}

	return (st);
}
