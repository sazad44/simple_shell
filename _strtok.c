#include "simple_shell.h"

int swim_delim(char *str, const char *delim, int index, int set_null);

char **_strtok(char *str, const char *delim)
{
	char **sentance = NULL;
	int i, word = 0, count = 1;

	/* Count the number of tokens */
	for (i = 0; str[i]; i++)
	{
		if (str[i] == *delim)
		{
			count++;
			i = swim_delim(str, delim, i, 0);
		}
	}

	/* Allocate memory for tokens and NULL pointer */
	sentance = malloc(sizeof(char *) * (count + 1));
	if (!sentance)
		return (NULL);

	i = 0;
	while (word < count)
	{
		i = swim_delim(str, delim, i, 1);
		sentance[word] = str + i;
		while (str[i] && str[i] != *delim)
			i++;
		word++;
	}

	return (sentance);
}

int swim_delim(char *str, const char *delim, int index, int set_null)
{
	while (str[index] == *delim)
	{
		if (set_null)
			str[index] = '\0';
		index++;
	}

	return (index);
}
