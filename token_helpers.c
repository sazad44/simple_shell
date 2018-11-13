#include "simple_shell.h"

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

/**
 * _strcpy - copies string from one pointer to another
 * @src: the pointer to copy from
 * @dest: the pointer to copy to
 * Return: the char pointer of the destination pointer
 */
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

/**
 * count_tokens - counts the number of tokens to be copied
 * @input: the input string to analyze for tokens
 * @delim: the delimeter string to base tokenization on
 * Return: the number of tokens in the input string
 */
int count_tokens(char *input, const char *delim)
{
	int count;
	char *token;

	token = strtok(input, delim);

	for (count = 0; token; count++)
		token = strtok(NULL, delim);

	return (count);
}
