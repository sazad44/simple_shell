#include "simple_shell.h"

int sharpie_cd(char *input)
{
	(void)input;

	printf("CD\n");
	printf("STUFF\n");
	return (0);
}

int sharpie_env(char *input)
{
	int i, len;

	(void)input;

	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(1, "\n", 1);
	}
	return (0);
}

int sharpie_exit(char *input)
{
	(void)input;
	return (1);
}
