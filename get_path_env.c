#include "shell.h"

char *fn_getenv(char *str)
{
	char *vr, *open, *pms, *evn;
	int i = 0;

	if (environ == NULL)
	{
		return (NULL);
	}

	while (environ[i])
	{
		pms = fn_strdup(environ[i]);
		open = strtok(pms, "=");
		if (fn_strcmp(open, str) != 0)
		{
			free(pms);
			pms = NULL;
		}
		else
		{
			vr = strtok(NULL, "\n");
			if (vr)
			{
				evn = fn_strdup(vr);
				free(pms);
				return (evn);
			}
			else
			{
				free(pms);
				return (NULL);
			}
		}
		i++;
	}
	return (NULL);
}

char *fn_getpath(char *cmd)
{
	struct stat str;
	int num = 0;
	char* fcd = NULL, *dst, *environ_p;

	while (cmd[num])
	{
		if (cmd[num] == '/')
		{
			if (stat(cmd, &str) == 0)
				return (fn_strdup(cmd));
			return (NULL);
		}
		num++;
	}

	environ_p = fn_getenv("PATH");
	if (environ_p == NULL)
		return (NULL);
	dst = strtok(environ_p, ":");

	while (dst != NULL)
	{
		size_t path_len = fn_strlen(dst), cmd_len = fn_strlen(cmd);

		fcd = malloc(path_len + cmd_len + 2);
		if (fcd != NULL)
		{
			fn_strcpy(fcd, dst);
			fn_strcat(fcd, "/");
			fn_strcat(fcd, cmd);
			if (stat(fcd, &str) == 0)
			{
				free(environ_p);
				return (fcd);
			}
			else
				free(fcd), fcd = NULL;
		}

		dst = strtok(NULL, ":");
	}
	free(environ_p);
	return (NULL);
}
