#include "shell.h"
/**
 * freeparam - free parameters memory
 * @str: string
 * Return: return 0 if str == null
*/
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
