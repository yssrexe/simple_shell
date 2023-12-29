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
    char* fcd;  
    char* environ_p = fn_getenv("PATH");
    char* dest = strtok(environ_p, ":");

    
}