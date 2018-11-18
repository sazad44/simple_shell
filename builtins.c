#include "simple_shell.h"

/**
 * sharpie_cd - Changes the user's current directory.
 * @input: the directory to be changed to
 *
 * Return: 0 on success, 1 on failure.
 */
int sharpie_cd(char *input)
{
	(void)input;
	return (1);
}

/**
 * sharpie_env - Prints the user's global environment variable.
 * @input: An unused string.
 *
 * Return: 0 on success, 1 on failure.
 */
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

/**
 * sharpie_exit - Exits the user's shell.
 * @input: An unused string.
 *
 * Return: 0 on success, 1 on failure.
 */
int sharpie_exit(char *input)
{
	(void)input;
	return (1);
}
