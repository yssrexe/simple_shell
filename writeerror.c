#include "shell.h"

void writerror(char *sm, char *command ,int ind)
{
    char *ken = fn_itoa(ind);

    write(2, sm, fn_strlen(sm));
    write(2, ": ", 2);
    write(2, ken, fn_strlen(ken));
    write(2, ": ", 2);
    write(2,  command, fn_strlen(command));
    write(2, ": not found\n" , 13);
    free(ken);
}