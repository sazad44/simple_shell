#include "simple_shell.h"

/**
 * _free - function to free as many different things as possible
 * @num: number of inputs put into function
 * Return: No Value
 */
void _free(unsigned int num, ...)
{
	unsigned int i;
	va_list v_ls;
	char *temp;

	va_start(v_ls, num);
	for (i = 0; i < num; i++)
	{
		temp = va_arg(v_ls, char *);
		if (temp)
			free(temp);
	}
	va_end(v_ls);
}

/**
 * _getenv - gets the specified environment variable
 * @name: the name of the environironment variable to be got
 * Return: Pointer to the matching environironment variable,
 * otherwise NULL.
 */
char *_getenv(const char *name, char *envp[])
{
	const char *namecpy = name;
	char *environcpy = envp[0];
	int i, j;

	for (i = 0; environcpy; i++, environcpy++)
	{
		for (j = 0; environcpy[j] == *namecpy; j++, namecpy++)
			;
		if (*namecpy == '\0')
			return (environcpy);
	}
	return (NULL);
}

/**
 * transform_tok - converts a token to its full path if it can be found in PATH
 * @command: the command token to be transformed to its full path if applicable
 * Return: a char pointer to the command either modified or not
 */
char *transform_tok(char *command, char *envp[])
{
	int i, j, k;
	char *buf, *path, *token, *pathcpy;
	struct stat *bufstat = NULL;

	path = _getenv("PATH", envp);
	bufstat = malloc(sizeof(struct stat));
	if (bufstat == NULL || command == NULL)
	{
		_free(1, bufstat);
		return (NULL);
	}
	i = _strlen(path);
	pathcpy = malloc(sizeof(char) * (i + 1));
	if (pathcpy == NULL)
	{
		_free(1, bufstat);
		return (NULL);
	}
	pathcpy = _strcpy(path, pathcpy);
	token = strtok(pathcpy, ":");
	while (token)
	{
		i = _strlen(command), j = _strlen(token);
		buf = malloc(sizeof(char) * (i + j + 3));
		if (buf == NULL)
			return (NULL);
		for (k = 0; k < (i + j); k++)
			buf[k] = '\0';
		buf = _strcat(buf, token, NULL);
		buf = _strcat(buf, command, "/");
		if (stat(buf, bufstat) == 0)
		{
			_free(2, pathcpy, bufstat);
			return (buf);
		}
		token = strtok(NULL, ":");
		_free(1, buf);
	}
	_free(2, pathcpy, bufstat);
	return (command);
}
