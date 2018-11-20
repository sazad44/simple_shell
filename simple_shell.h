#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
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
	int (*f)(char **arrtok);
} built_t;

/* Declaration of global variables */
extern char **environ;

/* Integral functions */
int proc(char *input, char *ipname);
int niproc(char *av[]);
char *_getenv(const char *name);
ssize_t _getline(char **lineptr);
int check_builtins(char *token, char *inputcpy2, char **arrtok);

/* Builtin functions */
int (*get_cmd_func(char *s))(char **arrtok);
int sharpie_cd(char **arrtok);
int sharpie_env(char **arrtok);
int sharpie_exit(char **arrtok);
int sharpie_setenv(char **arrtok);

/* Environment modification functions */
char *_getrealenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

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
char **tokenize_cmds(char *input, char **cmdtok);

/* Signal helper functions */
int _atoi(char *s);
void check_signal(int sig_num);

/* Other helper functions */
void get_input(char **input);
void _free(unsigned int num, ...);

#endif
