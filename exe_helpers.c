#include "simple_shell.h"

/**
 * _free - function to free as many different things as possible
 * @var_num: number of inputs put into function
 * Return: No Value
 */
void _free(unsigned int num, ...)
{
	unsigned int i;
	va_list v_ls;

	va_start(v_ls, num);
	for (i = 0; i < num; i++)
		free(va_arg(v_ls, char *));
	va_end(v_ls);
}
