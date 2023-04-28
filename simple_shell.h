#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int myprintenv(void);
char *mystrdup(char *string);
int cmdmyread(char *s, size_t __attribute__((unused))file_stream);
char *getpath(char *cmd);
char *mystrcat(char *dest, char *src);
int mystrcmp(char *str1, char *str2);
char *mystrcpy(char *dest, char *src);
int mystrlen(char *s);
void print_not_found(char *cmd);
int call_command(char *cmd_arr[]);
char *mygetenv(char *var);
int mystr_n_cmp(char *s1, char *s2, int n);
#endif
