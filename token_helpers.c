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

/**
 * create_arrtok - create an array of pointers to tokens of the input string
 * @input: a string to tokenize and have the pointers point to those tokens
 * @arrtok: the pointer array to have point to tokens
 * Return: a poiinter array to the tokens of the input string
 */
char **create_arrtok(char *input, char **arrtok)
{
	int i;
	char *token;

	token = strtok(input, " ");
	for (i = 0; token; i++)
	{
		arrtok[i] = token;
		token = strtok(NULL, " ");
	}
	arrtok[i] = NULL;
	return (arrtok);
}

/**
 * vet_input - gets input from command line or standard input
 * @input: a pointer to a pointer to the input
 * @i: the result of getline to vet the input
 * Return: No value
 */
void vet_input(int i, char *input)
{
	if (i < 0)
	{
		write(1, "\n", 1);
		free(input);
		exit(98);
	}
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '\n')
			input[i] = '\0';
	}
}
