#include "simple_shell.h"

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
