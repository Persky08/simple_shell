#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include<fcntl.h>

#define MAX_TOKENS 50

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(const char *str);
char **tokenization(char *input);
char *get_line(void);
void free_tokens(char **tokens);
int execute_command(char **command);

#endif
