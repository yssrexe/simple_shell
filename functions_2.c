#include "shell.h"

/**
 * ft_atoi - convert to a int
 * @str:string
 * Return:int
 */

int	ft_atoi(char *str)
{
	int	i;
	int	sub;
	int	nb;

	sub = 1;
	nb = 0;
	i = 0;
	while (str[i] && (str[i] == ' '
			|| str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sub *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sub);
}
/**
 * ft_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */


void	ft_putchar(char *c)
{
	write(1, &c, 1);
}

/**
 * ft_strncpy - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
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
	return (dest)
}
