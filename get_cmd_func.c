#include "simple_shell.h"

void (*get_cmd_func(char *s))(char *input)
{
	built_t cmds[] = {
	{"env", _env},
	{"cd", _cd},
	{NULL, NULL}
	};

	int i = 0;
	while (i < 2)
	{
		if (_strcmp(s, cmds[i].cmd))
			return (cmds[i].f);
		i++;
	}

	return (NULL);
}
