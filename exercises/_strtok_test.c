#include "simple_shell.h"

int main(void)
{
	int i;
	char arr[] = "Hello Holberton School";
	char *token, char *saveptr;

	for (i = 0; token; i++)
	{
		token = _strtok(&arr, " ", &saveptr);
		printf("%s\n", token);
	}
	return (0);
}
