#include "simple_shell.h"

void sharpie_cd(char *input)
{
	(void)input;

	printf("CD\n");
	printf("STUFF\n");
}

void sharpie_env(char *input)
{
	int i, len;

	(void)input;

	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(1, "\n", 1);
	}
}

void sharpie_exit(char *input)
{
	_exit(98);
}
