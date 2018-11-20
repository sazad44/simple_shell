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
 * struct exit_status - Struct built
 *
 * @message: The exit message
 * @code: The exit code
 * @exit: 1 if should exit shell, 0 if not.
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
	int (*f)(char **arrtok);
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
exit_t *child_proc(exit_t *estat, char **arrtok, char *cpy2, char *ipname);
exit_t *pipex(char **argv);

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
void minit2(int num, ...);

/* String helper functions */
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src, const char *delim);
char *_strcpy(char *src, char *dest);
unsigned int _strlen(char *str);
int colon_check(char *path, char *command, char **buf, struct stat **bufstat);

/* Token helper functions */
char **create_arrtok(char *input, char **arrtok);
int count_tokens(char *input, const char *delim);
char *transform_tok(char *command);
char **tokenize_cmds(char *input, char **cmdtok);

/* Signal helper functions */
int _atoi(char *s);
void check_signal(int sig_num);

/* Other helper functions */
void get_input(char **input, exit_t *estat);
void vet_input(int i, char *input, exit_t *estat);
void _free(unsigned int num, ...);

#endif
