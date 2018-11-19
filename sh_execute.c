#include "simple_shell.h"

/**
 * check_builtins - checks for built-in commands
 * @token: the string to check if matches known built-ins
 * @inputcpy2: the buffer to be freed if exit is triggered
 * @arrtok: the array of strings to be freed if exit is triggered
 * Return: an integer to indicate success (0) or failure (1)
 */
int check_builtins(char *token, char *inputcpy2, char **arrtok)
{
	if (get_cmd_func(token))
	{
		if (get_cmd_func(token)(arrtok))
		{
			_free(3, token, inputcpy2, arrtok);
			return (1);
		}
		/* _free(3, token, inputcpy2, arrtok); */
		return (0);
	}

	return (0);
}

/**
 * proc - a function to execute processes and tokenize a string input
 * @input: the input string to be tokenized and executed
 * @ipname: the name of the program being run
 * Return: an integer to indicate success (1) or failure (0)
 */
int proc(char *input, char *ipname, char *envp[])
{
	pid_t child_pid;
	int status, i;
	char **arrtok, *inputcpy, *inputcpy2;

	i = _strlen(input);
	mem_init(4, &inputcpy, i, &inputcpy2, i);
	inputcpy = _strcpy(input, inputcpy), inputcpy2 = _strcpy(inputcpy, inputcpy2);
	i = count_tokens(inputcpy, " ");
	_free(1, inputcpy), mem_init_two(2, &arrtok, i);
	arrtok = create_arrtok(inputcpy2, arrtok);
	/* Built in time */
	if (get_cmd_func(arrtok[0]))
	{
		if (get_cmd_func(arrtok[0])("", envp))
		{
			_free(2, inputcpy2, arrtok);
			return (1);
		}
		_free(2, inputcpy2, arrtok);
		return (0);
	}
	if (check_builtins(arrtok[0], inputcpy2, arrtok))
		return (1);
	arrtok[0] = transform_tok(arrtok[0]);
	child_pid = fork();
	if (child_pid == -1)
	{
		_free(3, arrtok[0], inputcpy2, arrtok);
		perror("Error:");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (arrtok[0] == NULL || *(arrtok[0]) == '\0')
		{
			_free(3, arrtok[0], inputcpy2, arrtok);
			return (1);
		}
		if (execve(arrtok[0], arrtok, envp) == -1)
		{
			_free(3, arrtok[0], inputcpy2, arrtok);
			perror(ipname);
			return (1);
		}
	}
	else if (child_pid != 0)
	{
		wait(&status);
		_free(3, arrtok[0], inputcpy2, arrtok);
	}
	return (0);
}

/**
 * niproc - handles execution of commands in non-interactive mode
 * @av: the commands passed into non-interactive shell
 *
 * Return: An integer to indicate success (1) or failure (0).
 */
int niproc(char *av[])
{
	pid_t child_pid;
	char *prname = av[0];
	int status;

	av++;
	if (get_cmd_func(av[0]))
	{
		if (get_cmd_func(av[0])(av))
			return (1);
	}
	else
	{
		av[0] = transform_tok(av[0]);
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
	return (0);
}
