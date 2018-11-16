#include "simple_shell.h"

int (*get_cmd_func(char *s))(char *input, char *envp[])
{
	built_t cmds[] = {
	{"env", sharpie_env},
	{"cd", sharpie_cd},
	{"exit", sharpie_exit},
	{NULL, NULL}
	};
	int i = 0;

	while (i < 3)
	{
		if (_strcmp(s, cmds[i].cmd))
			return (cmds[i].f);
		i++;
	}

	return (NULL);
}
