#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

#define MNTS " \t\n"
extern char **environ;

/*main functions*/
char *read_cmd(void);
char **fn_tokenizing(char *str);
void freeparam(char **str);
int fn_execute(char **cmd, char **arv);

/*functions1 file*/
char *fn_strdup(const char *src);
int fn_strcmp(char *s1, char *s2);
char *fn_strcat(char *dest, char *src);
char *fn_strcpy(char *dest, char *src);
int fn_strlen(char *str);

/* function_2 file*/
int	fn_atoi(const char *str);
char *fn_strncpy(char *dest, char *src, unsigned int n);
void fn_putchar(char *c);

/*get path and env*/
char *fn_getenv(char *str);

#endif
