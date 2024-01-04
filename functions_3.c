#include "shell.h"

/**
 * check_value - check the string if have a positive numbers
 * @str: string
 * Return: return 0 if false or 1 if true
*/
int check_value(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

/**
 * fn_putstr - print string
 * @str: string
 * Return: ret 0 if false
*/
void fn_putstr(char *str)
{
	int i = 0;

	if (str == NULL)
		return;

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
