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

char **_strtok(char *str);

int proc(char *input, char *ipname);

char *_strcpy(char *src, char *dest);

unsigned int _strlen(char *str);

int count_tokens(char *input, const char *delim);

int niproc(char *av[]);

char **create_arrtok(char *input, char **arrtok);

void vet_input(int i, char *input);

void _free(unsigned int num, ...);
#endif
