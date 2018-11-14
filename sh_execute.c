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
	char **arrtok, *token, *inputcpy;

	i = _strlen(input);
	inputcpy = malloc(sizeof(char) * (i + 1));
	if (inputcpy == NULL)
		return (1);
	inputcpy = _strcpy(input, inputcpy);
	i = count_tokens(inputcpy, " ");
	arrtok = malloc(sizeof(token) * (i + 1));
	if (arrtok == NULL)
		return (1);
	arrtok = create_arrtok(input, arrtok);
	arrtok[0] = transform_tok(arrtok[0], env);
	child_pid = fork();
	if (child_pid == -1)
	{
		_free(2, inputcpy, arrtok);
		perror("Error:");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (*inputcpy == '\0' || arrtok[0] == NULL)
		{
			_free(2, inputcpy, arrtok);
			return (1);
		}
		if (execve(arrtok[0], arrtok, NULL) == -1)
		{
			_free(2, inputcpy, arrtok);
			perror(ipname);
			return (1);
		}
	}
	else if (child_pid != 0)
	{
		wait(&status);
		_free(2, inputcpy, arrtok);
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
