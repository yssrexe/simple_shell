#include "shell.h"

/**
 * writerror - handling error
 * @sm: custom error message
 * @command: error occurred
 * @ind: identifier
 */

void writerror(char *sm, char *command, int ind)
{
	char *ken = fn_itoa(ind);

	fn_putstr(sm);
	fn_putstr(": ");
	fn_putstr(ken);
	fn_putstr(": ");
	fn_putstr(command);
	fn_putstr(": not found\n");
	free(ken);
}

