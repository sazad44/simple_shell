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

	if (!str)
		return (0);
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
 * _strcmp - checks if two strings are equivalent
 * @s1: the first string
 * @s2: the second string
 * Return: 1 if they are equal, else 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}

	return (1);
}

/**
 * _strcat - appends delimeter character and additional string
 * onto the end of destination string
 * @dest: the string to be appended to
 * @src: the additional string to append
 * @delim: a delimeter character that goes between dest and src
 * Return: Nothing..
 */
char *_strcat(char *dest, const char *src, const char *delim)
{
	unsigned int i, len;

	if (!dest || !src)
		return (NULL);

	len = _strlen(dest);

	if (delim)
		dest[len++] = *delim;

	for (i = 0; src[i]; len++, i++)
		dest[len] = src[i];
	dest[len] = src[i];

	return (dest);
}
