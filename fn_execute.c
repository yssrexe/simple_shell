#include "shell.h"
/**
 * fn_execute - execute function
 * @cmd: commands
 * @arv: argument value
 * Return: executation cmd
 */

int	fn_execute(char **cmd, char **arv)
{
	pid_t	son;
	int	exc;

	son = fork();
	if (son == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(arv[0]);
			freeparam(cmd);
			exit(127); /*127*/
		}
	}
	else
	{
		waitpid(son, &exc, 0);
		freeparam(cmd);
	}
	return (WEXITSTATUS(exc));
}

