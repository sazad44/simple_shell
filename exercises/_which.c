#include "simple_shell.h"

int main(int argc, char *argv[])
{
	int i, j, k, n, m = 0, flag = 0;
	char *buf, *path, *token, *pathcpy;
	struct stat *bufstat = NULL;

	if (argc < 2)
		exit(98);
	path = getenv("PATH");
	bufstat = malloc(sizeof(struct stat));
	if (bufstat == NULL)
		return (1);
	for (k = 1; k < argc; k++)
	{
		i = _strlen(path), flag = 0;
		pathcpy = malloc(sizeof(char) * (i + 1));
		if (pathcpy == NULL)
			return (1);
		pathcpy = _strcpy(path, pathcpy);
		token = strtok(pathcpy, ":");
		while (token)
		{
			m = 0, i = _strlen(argv[k]), j = _strlen(token);
			buf = malloc(sizeof(char) * (i + j + 4));
			if (buf == NULL)
				return (1);
			for (n = 0; n < j; n++)
				buf[n] = token[n];
			buf[n++] = '/';
			for (; n < (i + j + 2); n++)
				buf[n] = argv[k][m++];
			buf[n++] = '\n', buf[n] = '\0';
			if (stat(buf, bufstat) == 0)
			{
				write(1, buf, (i + j + 3));
				flag = 1;
				break;
			}
			token = strtok(NULL, ":");
			_free(1, buf);
		}
		if (flag == 1)
			_free(2, pathcpy, buf);
		else
			_free(1, pathcpy);
	}
	_free(1, bufstat);
	return (0);
}
