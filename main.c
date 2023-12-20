#include "shell.h"

int main(int arc, char **arv)
{
    
    char *l = NULL;
    char **cmd = NULL;
    int exc = 0;
    (void)arc;
    (void)arv;
    while (true)
    {
        l = read_cmd();
        if (l == NULL)
        {
            if (isatty(0))
                write(1, "\n", 1);
            return exc;
        }
        
        free(l);
        cmd = fn_split(l);
       /* exc = fn_execute(cmd, arv); */ 
    }
}