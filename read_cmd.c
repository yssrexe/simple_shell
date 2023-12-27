#include "shell.h"
/**
 * read_cmd - read commands
 * Return: return cmd
 */
char	*read_cmd(void)
{
	size_t	len = 0;
	char	*l = NULL;
	ssize_t	n;

	if (isatty(0))
		write(1, "$ ", 2);

	n = getline(&l, &len, stdin);
	if (n == -1)
	{
		free(l);
		return (NULL);
	}
	return (l);
}
