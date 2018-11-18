#include "simple_shell.h"

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

	arrtok[0] = NULL;
	if (input == NULL)
		return (arrtok);
	token = strtok(input, " ");
	if (token == NULL)
		arrtok[0] = token;
	for (i = 0; token; i++)
	{
		arrtok[i] = token;
		token = strtok(NULL, " ");
	}
	if (i > 0)
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
	if (input == NULL)
		return;
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

/**
 * _strtok - tokenizes a string according to a certain delimiter
 * @str: the string to be tokenized
 * @delim: the delimiter to separate tokens
 * @saveptr: a pointer to keep track of the beginning of the token
 * Return Value: a character pointer to the current delimited token
 */
char *_strtok(char *str, const char *delim, char **saveptr)
{
	int i, j;

	if (str)
		*saveptr = str;
	for (i = 0; delim[i]; i++)
	{
		if (delim[i] = saveptr[0])
		{
			saveptr[0] = '\0';
			(*saveptr)++;
			break;
		}
	}
	for (i = 0; saveptr[i]; i++)
	{
		
	}
}
