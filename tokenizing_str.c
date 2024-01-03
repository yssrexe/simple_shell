#include "shell.h"

/**
 * fn_tokenizing - tokenizes a string based on delimiters
 * @str: string
 * Return: return null
 */

char **fn_tokenizing(char *str)
{
	int loop = 0, i = 0;
	char *tkn, **cmd = NULL, *lst = NULL;

	if (str == NULL)
		return (NULL);
	lst = fn_strdup(str);
	tkn = strtok(lst, MNTS);
	if (tkn == NULL)
	{
		free(str), str = NULL;
		free(lst), lst = NULL;
		return (NULL);
	}

	while (tkn)
	{
		loop++;
		tkn = strtok(NULL, MNTS);
	}
	free(lst);
	lst = NULL;

	cmd = malloc(sizeof(char *) * (loop + 1));
	if (cmd == NULL)
	{
		free(str);
		cmd = NULL;
		return (NULL);
	}

	tkn = strtok(str, MNTS);
	while (tkn)
	{
		cmd[i++] = fn_strdup(tkn);
		tkn = strtok(NULL, MNTS);
	}
	free(str);
	str = NULL;
	cmd[i] = NULL;
	return (cmd);
}
