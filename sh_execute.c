#include "holberton.h"

void proc(char *input)
{
	pid_t child_pid;
	int status, i;
	char **arrtok, *token, *inputcpy;

	for (i = 0; input[i]; i++)
		;
	inputcpy = malloc(sizeof(char) * (i + 1));
	if (inputcpy == NULL)
		return;
	for (i = 0; input[i]; i++)
		inputcpy[i] = input[i];
	inputcpy[i] = '\0';
	token = strtok(inputcpy, " ");
	for (i = 0; token; i++)
		token = strtok(NULL, " ");
	arrtok = malloc(sizeof(token) * (i + 1));
	if (arrtok == NULL)
		return;
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
		return;
	}
	else if (child_pid == 0)
	{
		if (execve(arrtok[0], arrtok, NULL) == -1)
			perror("Error");
	}
	else if (child_pid != 0)
	{
		free(inputcpy);
		free(arrtok);
		wait(&status);
	}
}
