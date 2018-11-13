#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char **_strtok(char *str);

int proc(char *input, char *ipname);

char *_strcpy(char *src, char *dest);

unsigned int _strlen(char *str);

int count_tokens(char *input, const char *delim);

#endif
