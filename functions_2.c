#include "shell.h"

/**
 * fn_atoi - convert string to integer
 * @str: string
 * Return: numbers
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
 * fn_putchar - write the char
 * @c: character
 */


void	fn_putchar(char *c)
{
	write(1, &c, 1);
}

/**
 * fn_strncpy - copie a string
 * @dest: destination
 *  @src: source
 * @n: num
 * Return: return the destination
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

int	len(long nb)
{
	int	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return(len);
}
char	*fn_itoa(int nb)
{
	char	*str;
	long	n;
	int	i;

	n = nb;
	i = len(n);
	if(!(str = (char *)malloc(i + 1)))
		return(0);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return(str);
	}
	if(n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

void fn_putstr(char *str)
{
	int i = 0;
	if (str == NULL)
		return;
	
	while(str[i] != '\0')
	{
		write(1 , &str[i] , 1);
		i++;
	}
}
