#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>

/**
 * struct built - Struct built
 *
 * @cmd: The command
 * @f: The function associated
 */
typedef struct built
{
	char *cmd;
	void (*f)(char *input);
} built_t;

char **_strtok(char *str, const char *delim);

int _strcmp(char *s1, char *s2);

char *_strcat(char *dest, const char *src, const char *delim);

char *_getenv(const char *name);

int proc(char *input, char *ipname, char **env);

char *_strcpy(char *src, char *dest);

unsigned int _strlen(char *str);

int count_tokens(char *input, const char *delim);

int niproc(char *av[]);

char **create_arrtok(char *input, char **arrtok);

void vet_input(int i, char *input);

void _free(unsigned int num, ...);

char *transform_tok(char *command, char **env);
#endif
