#include "simple_shell.h"

int sharpie_cd(char *input, char *envp[])
{
	(void)input;
	(void)envp;

	printf("CD\n");
	printf("STUFF\n");
	return (0);
}

int sharpie_env(char *input, char *envp[])
{
	int i, len;

	(void)input;

	for (i = 0; envp[i]; i++)
	{
		len = _strlen(envp[i]);
		write(1, envp[i], len);
		write(1, "\n", 1);
	}
	return (0);
}

int sharpie_exit(char *input, char *envp[])
{
	(void)input;
	(void)envp;
	return (1);
}
