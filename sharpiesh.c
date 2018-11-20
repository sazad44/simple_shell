#include "simple_shell.h"

/**
 * main - Entry point
 * @argc: the number of arguments made to the program
 * @argv: an array of pointers to the arguments to the program
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i;
	char *input = NULL;
	exit_t *estat, estat_real;

	estat = &estat_real;
	estat->message = "Error", estat->code = 0, estat->exit = 0;
	if (argc > 1)
	{
		if (niproc(argv))
			return (0);
		return (1);
	}
	if (!isatty(STDIN_FILENO))
	{
		i = _getline(&input), vet_input(i, input);
		estat = proc(input, argv[0], estat);
		if (estat->exit == 1)
		{
			_free(1, input);
			return (1);
		}
		_free(1, input);
	}
	else
	{
		while (1)
		{
			write(1, "$ ", 2);
			i = _getline(&input);
			vet_input(i, input);
			estat = proc(input, argv[0], estat);
			if (estat->exit == 1)
				break;
			if (input)
				_free(1, input);
		}
		_free(1, input);
		exit(estat->code);
	}
	return (0);
}
