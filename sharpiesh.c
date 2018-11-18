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

	if (argc > 1)
	{
		if (niproc(argv))
			return (0);
		return (1);
	}
	if (!isatty(STDIN_FILENO))
	{
		i = _getline(&input);
		vet_input(i, input);
		if (proc(input, argv[0]) == 1)
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
			if (proc(input, argv[0]) == 1)
				break;
			if (input)
				_free(1, input);
		}
		_free(1, input);
		return (0);
	}
	return (0);
}
