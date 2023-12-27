#include "shell.h"

int fn_execute(char **cmd, char **arv)
{
    pid_t son;
    int exc;

    son = fork();
    if (son == 0)
    {
        if (execve(cmd[0], cmd, environ) == -1)
        {
            perror(arv[0]);
            freeparam(cmd);
            exit(0);
        }
    }
    else
    {
        waitpid(son, &exc, 0);
        freeparam(cmd);
    }
    return (WEXITSTATUS(exc));
}