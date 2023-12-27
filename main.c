#include "shell.h"
/**
 * main - main function hsh
 * @arc: argument count
 * @arv: argument value
 * Return: exit by value
 */

int	main(int arc, char **arv)
{

	char	*l = NULL;
	char	**cmd = NULL;
	int		exc = 0;
	(void)arc;

	while (true)
	{
		l = read_cmd();
		if (l == NULL)
		{
			if (isatty(0))
				write(1, "\n", 1);
			return (exc);
		}

		cmd = fn_tokenizing(l);
		if (cmd == NULL)
			continue;

		exc = fn_execute(cmd, arv);
	}
}
