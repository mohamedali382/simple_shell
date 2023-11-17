#include "shell.h"

/**
*adddir - directory storage
*@head: head of list
*@dir: name of directory
*Return: the address of head
*/
struct linkp *adddir(struct linkp **head, char *dir)
{
	struct linkp *new, *tmp;

	if (!dir)
	{
		return (NULL);
	}
	new = malloc(sizeof(struct linkp));
	if (!new)
	{
		return (NULL);
	}

	new->d = _strdup(dir);
	new->p = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->p)
		{
			tmp = tmp->p;
		}
		tmp->p = new;
	}
	return (*head);
}
/**
* linkpath - store all path var
* @envs: environment variable pass
* Return: address
*/
struct linkp *linkpath(char *envs)
{
	char *token;
	struct linkp *head = NULL;
	char *cpy = _strdup(envs);

	token = strtok(cpy, ":");
	while (token)
	{
		head = adddir(&head, token);
		token = strtok(NULL, ":");
	}
	free(cpy);
	return (head);
}
/**
* freepath - store all path var
* @path: environment variable pass
* Description: store all via linked list
* Return: NULL
*/
struct linkp *freepath(struct linkp *path)
{
	struct linkp *tmp = path;

	while (tmp)
	{
		tmp = tmp->p;
		free(path->d);
		free(path);
		path = tmp;
	}
	free(tmp);
	return (NULL);
}
