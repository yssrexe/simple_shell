#include "shell.h"

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

