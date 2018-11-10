#include "simple_shell.h"

int main(void)
{
	int i;
	size_t isize = 0;
	char *input = NULL;

	while(1)
	{
		printf("$ ");
		getline(&input, &isize, stdin);
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '\n')
				input[i] = '\0';
		}
		proc(input);
	}
	free(input);
	return (0);
}
