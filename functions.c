#include "shell.h"

char	*fn_strdup(const char *str)
{
	char	*n;
	int		i;
	int		s;

	s = 0;
	while (str[s])
		s++;

n = malloc(sizeof(char) * (s + 1));

	if (n = NULL)
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

