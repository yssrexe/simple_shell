#include "shell.h"
/**
 * fn_strlen - lenght of string
 * @str:char
 * Return:int
 */

int	fn_strlen(char *str)
{
	int	i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

/**
 * fn_strdup - Duplicate A String
 * @str:String
 * Return: Duplicate String Failed Null
 */

char	*fn_strdup(const char *str)
{
	char	*n;
	int		i;
	int		s;

	if (str == NULL)
		return (NULL);
	s = 0;
	while (str[s])
		s++;

	n = malloc(sizeof(char) * (s + 1));

	if (n == NULL)
		return (NULL);

	i = 0;
	while (str[i])
	{
		n[i] = str[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}
/**
 * fn_strcmp - Compare Two String
 * @s1:String 1
 * @s2:String 2
 * Return: 0 If Identical Otherwise How Much Diffrent
 */

int	fn_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * fn_strcat - Concat Two String
 * @dest:First String
 * @src:Second String
 * Return:First String + Second String Char *
 */
char	*fn_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * ft_strcpy - Copie Source To Destination Char
 * @dest:Destination
 * @src:Source
 * Return: Copie Of Char *
 */
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
