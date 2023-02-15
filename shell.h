#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int execve(const char *pathname, char *const argv[],char *const envp[]);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif
