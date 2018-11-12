nclude "simple_shell.h"

/**
 * _strlen - Returns the number of characters in a string.
 * @str: the string to find the length of
 *
 * Return: Length of the string.
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	while (str[len])
		len++;

	return (len);
}

char *_strcpy(char *src, char *dest)
{
	int i;

	if (src == NULL || dest == NULL)
		return (NULL);
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}

