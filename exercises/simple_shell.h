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
	int (*f)(char *input, char *envp[]);
} built_t;

/* Declaration of global variables */
/*extern char **environ;*/

/* Integral function prototypes */
int proc(char *input, char *ipname, char *envp[]);
int niproc(char *av[]);
char *_getenv(const char *name, char *envp[]);

/* Builtin prototypes */
int (*get_cmd_func(char *s))(char *input, char *envp[]);
int sharpie_cd(char *input, char *envp[]);
int sharpie_env(char *input, char *envp[]);
int sharpie_exit(char *input, char *envp[]);

/* String helper function prototypes */
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src, const char *delim);
char *_strcpy(char *src, char *dest);
unsigned int _strlen(char *str);
char *_strtok(char *str, const char *delim, char **saveptr)

/* Token helper functions */
char **create_arrtok(char *input, char **arrtok);
int count_tokens(char *input, const char *delim);
char *transform_tok(char *command, char *envp[]);

/* Other helper functions */
void vet_input(int i, char *input);
void _free(unsigned int num, ...);

#endif
