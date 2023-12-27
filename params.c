#include "shell.h"

void freeparam(char **str)
{
    int i = 0;
    if (str == NULL)
        return;
    while (str[i])
    {
        free(str[i]);
        str[i] = NULL;
        i++;
    }
    free(str);
    str = NULL;
}