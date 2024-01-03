#include "shell.h"

int check_builtins(char *cmd)
{
	char *list[] = {"env", "exit", "setenv", "cd", NULL};
	int i = 0;

	while (list[i])
	{
		if (fn_strcmp(cmd, list[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}


void handls_bl(char **cmd, char **arv, int *st, int i)
{

	if (fn_strcmp(cmd[0], "exit") == 0)
	{
		perform_exit(cmd, arv, st, i);
	}
	else if (fn_strcmp(cmd[0], "env") == 0)
	{
		write_env(cmd, st);
	}

}

void write_env(char **cmd, int *set)
{
	int i = 0;

	while (environ[i])
	{
		fn_putstr(environ[i]);
		fn_putstr("\n");
		i++;
	}
	freeparam(cmd);
	(*set) = 0;
}

void perform_exit(char **cmd, char **arv, int *set, int i)
{
	int per_ext = (*set);
	char *str;

	if (cmd[1] != NULL)
	{
		if (check_value(cmd[1]) == 1)
		{
			per_ext = fn_atoi(cmd[1]);
		}
		else
		{
			str = fn_itoa(i);
			fn_putstr(arv[0]);
			fn_putstr(": ");
			fn_putstr(str);
			fn_putstr(": exit: Illegal number: ");
			fn_putstr(cmd[1]);
			fn_putstr("\n");

			free(str);
			freeparam(cmd);

			(*set) = 2;
			return;
		}
	}
	freeparam(cmd);
	exit(per_ext);
}
