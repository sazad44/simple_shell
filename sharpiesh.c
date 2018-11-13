#include "simple_shell.h"

int main(int argc, char *argv[])
{
	int i;
	size_t isize = 0;
	char *input = NULL;

	if (argc > 1)
	{
		if (!niproc(argv))
			return (0);
		return (1);
	}
	if (!isatty(STDIN_FILENO))
	{
		i = getline(&input, &isize, stdin);
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
		if (proc(input, argv[0]) == 1)
			exit(98);
	}
	else
	{
		while (1)
		{
			write(1, "$ ", 2);
			i = getline(&input, &isize, stdin);
			if (i < 0)
			{
				write(1, "\n", 3);
				free(input);
				exit(98);
			}
			for (i = 0; input[i]; i++)
			{
				if (input[i] == '\n')
					input[i] = '\0';
			}
			if (proc(input, argv[0]) == 1)
				break;
		}
		free(input);
		return (0);
	}
	return (0);
}
