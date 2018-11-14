#include "simple_shell.h"

/**
 * _free - function to free as many different things as possible
 * @var_num: number of inputs put into function
 * Return: No Value
 */
void _free(unsigned int num, ...)
{
	unsigned int i;
	va_list v_ls;

	va_start(v_ls, num);
	for (i = 0; i < num; i++)
		free(va_arg(v_ls, char *));
	va_end(v_ls);
}

/**
 * _getenv - gets the specified environment variable
 * @env: the user's environment
 * @name: the name of the environment variable to be got
 * Return: Pointer to the matching environment variable,
 * otherwise NULL.
 */
char *_getenv(char **env, const char *name)
{
	extern char **environ;
	const char *namecpy;
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
		{
			namecpy = name;
			while (environ[i][j] == *namecpy)
			{
				j++;
				namecpy++;
			}
			if (*namecpy == '\0')
			{
				environ[i] += j + 1;
				return (environ[i]);
			}
		}
	}

	return (NULL);
}
