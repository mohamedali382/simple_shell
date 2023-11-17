#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <malloc.h>
extern char **environ;
/**
* struct linkp - linkpath
* @d: name of folder
* @p: pointer to the next folder
* Description: link path variables in a linked list
*/
typedef struct linkp
{
	struct linkp *p;
	char *d;
} linkp;

void _CTD(ssize_t len, char *l);
char **_strtok(char *token, const char *delim);
struct linkp *adddir(struct linkp **head, char *dir);
struct linkp *linkpath(char *envs);
void exec(char **ag);
char *_strcat(char *paths, const char *temp);
char *findexec(char *args, struct linkp *head);
struct linkp *free_list(struct linkp *path);
void *_realloc(void *ptrr, size_t size);
void freeArgs(char **ag);
size_t _strlen(const char *ag);
struct linkp *freepath(struct linkp *path);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strcpy(char *path, const char *src);
#endif
