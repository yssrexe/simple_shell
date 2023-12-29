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
        } else {
            vr = strtok(NULL , "\n");
            if (vr)
            {
                evn = fn_strdup(vr);
                free(pms);
                return (evn);
            } else {
                free(pms);
                return NULL;
            }
        }
        i++;
    }
    return NULL;
}

char *fn_getpath(char *cmd)
{
    struct stat str;
    int num = 0;
    char* fcd = NULL, *environ_p = fn_getenv("PATH"), *dst = strtok(environ_p, ":");
    
    if (environ_p == NULL)
        return (NULL);
    
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
    
    while (dst != NULL)
    {
        size_t path_len = fn_strlen(dst), cmd_len = fn_strlen(cmd);
        fcd = malloc(path_len + cmd_len + (1 + 1));
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
            free(fcd), fcd = NULL;
        }
        dst = strtok(NULL, ":");
    }
    free(environ_p);
    return (NULL);
}

int main(int ac, char **av)
{
    char *full_cmd = fn_getpath(av[1]);
    if (full_cmd)
        printf("%s\n", full_cmd);
    else
        printf("does not exist\n");
    
}