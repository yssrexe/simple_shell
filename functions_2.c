#include "shell.h"

/**
 * fn_atoi - convert to a int
 * @str:string
 * Return:int
 */

int	fn_atoi(const char *str)
{
	int	i = 0;
	int	sign = 1;
	int	result = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;

	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/**
 * fn_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */


void	fn_putchar(char *c)
{
	write(1, &c, 1);
}

/**
 * fn_strncpy - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */
char	*fn_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
