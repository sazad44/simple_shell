#include "simple_shell.h"

int proc(char *input, char *ipname)
{
	pid_t child_pid;
	int status, i;
	char **arrtok, *token, *inputcpy;

	i = _strlen(input);
	inputcpy = malloc(sizeof(char) * (i + 1));
	if (inputcpy == NULL)
		return (0);
	inputcpy = _strcpy(input, inputcpy);
	i = count_tokens(inputcpy, " ");
	arrtok = malloc(sizeof(token) * (i + 1));
	if (arrtok == NULL)
		return (0);
	token = strtok(input, " ");
	for (i = 0; token; i++)
	{
		arrtok[i] = token;
		token = strtok(NULL, " ");
	}
	arrtok[i] = NULL;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (0);
	}
	else if (child_pid == 0)
	{
		if (*inputcpy == '\0' || arrtok[0] == NULL)
			exit(98);
		if (execve(arrtok[0], arrtok, NULL) == -1)
		{
			perror(ipname);
			return (1);
		}
	}
	else if (child_pid != 0)
	{
		free(inputcpy);
		free(arrtok);
		wait(&status);
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
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			perror(prname);
			return (1);
		}
	}
	else if (child_pid != 0)
		wait(&status);
	return (0);
}
