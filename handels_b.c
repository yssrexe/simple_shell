#include "shell.h"

int check_builtins(char *cmd)
{
	char *list[] = {"env", "exit", "setenv","cd", NULL};
	int i = 0;

	while (list[i])
    {
        if (fn_strcmp(cmd, list[i]) == 0)
            return 1;
		i++;
    }
	return (0);
}


void handls_bl(char **cmd, char **arv ,int *st ,int i)
{
	(void)arv;
	(void)i;

    if (fn_strcmp(cmd[0], "env") == 0)
    {
        write_env(cmd, st);
    }
    else if (fn_strcmp(cmd[0], "exit") == 0)
    {
        perform_exit(cmd, st);
    }
    
}

void write_env(char **cmd, int *set)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], fn_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
        i++;
	}
	freeparam(cmd);
	(*set) = 0;
}

void perform_exit(char **cmd, int *set)
{
    freeparam(cmd);
	exit(*set);
}