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
#include <sys/types.h>
#include <stdbool.h>

char    *read_cmd(void);
char	*fn_strdup(const char *src);
int	    fn_strcmp(char *s1, char *s2);
char	*fn_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);

#endif