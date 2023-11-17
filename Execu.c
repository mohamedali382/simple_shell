#include "shell.h"
/**
* exec - execute
* @ag: string have the path and arguments
* Return: void
*/
void exec(char **ag)
{
	int st;
	pid_t id;

	if (!ag || !ag[0])
		return;
	id = fork();
	if (id == 0)
	{
		if (execve(ag[0], ag, environ) == -1)
		{
			perror(getenv("_"));
			exit(EXIT_FAILURE);
		}
	}
	else if (id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&st);
	}
}
