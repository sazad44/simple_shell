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
typedef struct exit_status
{
	char *message;
	int code;
	int exit;
} exit_t;

/**
 * struct built - Struct built
 *
 * @cmd: The command
 * @f: The function associated
 */
typedef struct built
{
	char *cmd;
	int (*f)(char *input);
} built_t;

/* Declaration of global variables */
extern char **environ;

/* Integral functions */
exit_t *proc(char *input, char *ipname, exit_t *estat);
exit_t *change_status(exit_t *estat, char *msg, int cd, int flag);
int niproc(char *av[]);
char *_getenv(const char *name);
ssize_t _getline(char **lineptr);
int check_builtins(char *token, char *inputcpy2, char **arrtok);

/* Builtin functions */
int (*get_cmd_func(char *s))(char *input);
int sharpie_cd(char *input);
int sharpie_env(char *input);
int sharpie_exit(char *input);

/* Memory helper functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *null_init(char *buffer, int bufsize);
void mem_init(int num, ...);
void mem_init_two(int num, ...);

/* String helper functions */
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src, const char *delim);
char *_strcpy(char *src, char *dest);
unsigned int _strlen(char *str);

/* Token helper functions */
char **create_arrtok(char *input, char **arrtok);
int count_tokens(char *input, const char *delim);
char *transform_tok(char *command);

/* Other helper functions */
void vet_input(int i, char *input, exit_t *estat);
void _free(unsigned int num, ...);

#endif
