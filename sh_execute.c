#include "simple_shell.h"

/**
 * proc - a function to execute processes and tokenize a string input
 * @input: the input string to be tokenized and executed
 * @ipname: the name of the program being run
 * Return: an integer to indicate success (1) or failure (0)
 */
int proc(char *input, char *ipname)
{
	pid_t child_pid;
	int status, i;
	char **arrtok, *token, *inputcpy, *inputcpy2;

	i = _strlen(input);
	inputcpy = malloc(sizeof(char) * (i + 1));
	inputcpy2 = malloc(sizeof(char) * (i + 1));
	if (inputcpy == NULL)
	{
		_free(1, inputcpy2);
		return (1);
	}
	if (inputcpy2 == NULL)
	{
		_free(1, inputcpy);
		return (1);
	}
	inputcpy = _strcpy(input, inputcpy);
	inputcpy2 = _strcpy(inputcpy, inputcpy2);
	i = count_tokens(inputcpy, " ");
	_free(1, inputcpy);
	arrtok = malloc(sizeof(token) * (i + 1));
	if (arrtok == NULL)
		return (1);
	arrtok = create_arrtok(inputcpy2, arrtok);
	arrtok[0] = transform_tok(arrtok[0]);

	/* Built in time */
	if (get_cmd_func(arrtok[0]))
	{
		if (get_cmd_func(arrtok[0])(""))
		{
			_free(2, inputcpy2, arrtok);
			return (1);
		}
		_free(2, inputcpy2, arrtok);
		return (0);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		_free(2, inputcpy2, arrtok);
		perror("Error:");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (arrtok[0] == NULL || *(arrtok[0]) == '\0')
		{
			_free(2, inputcpy2, arrtok);
			return (1);
		}
		if (execve(arrtok[0], arrtok, environ) == -1)
		{
			_free(2, inputcpy2, arrtok);
			perror(ipname);
			return (1);
		}
	}
	else if (child_pid != 0)
	{
		wait(&status);
		_free(2, inputcpy2, arrtok);
	}
	return (0);
}

int niproc(char *av[])
{
	pid_t child_pid;
	char *prname = av[0];
	int status;

	av++;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork Error");
		return (0);
	}
	else if (child_pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			perror(prname);
			return (0);
		}
	}
	else if (child_pid != 0)
		wait(&status);
	return (1);
}
