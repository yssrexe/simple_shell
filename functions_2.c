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

char	*fn_itoa(int nbr)
{
    char	*str;
    long	tmp;
    int		length;
    
    tmp = nbr;
    length = (nbr <= 0 ? 2 : 1);
    while (nbr && ++length)
        nbr /= 10;
    if (!(str = (char *)malloc(sizeof(char) * length)))
        return (NULL);
    str[--length] = '\0';
    if (tmp <= 0)
        str[0] = (tmp < 0 ? '-' : '0');
    while (tmp)
    {
        str[--length] = (tmp < 0 ? -tmp : tmp) % 10 + '0';
        tmp /= 10;
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
