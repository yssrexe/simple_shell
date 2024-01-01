#include "shell.h"
/**
 * fn_execute - execute function
 * @cmd: commands
 * @arv: argument value
 * Return: executation cmd
 */

int	fn_execute(char **cmd, char **arv, int num)
{
	pid_t	son;
	int	exc;
	char *tst_c;

	tst_c = fn_getpath(cmd[0]);
	if (tst_c == NULL)
	{
		writerror(arv[0], cmd[0], num); 
		freeparam(cmd);
		return(127);
	}
	
	son = fork();
	if (son == 0)
	{
		if (execve(tst_c, cmd, environ) == -1)
		{
			free(tst_c);
			tst_c = NULL;
			freeparam(cmd);
		}
	}
	else
	{
		waitpid(son, &exc, 0);
		freeparam(cmd);
		free(tst_c);
		tst_c = NULL;
	}
	return (WEXITSTATUS(exc));
}

