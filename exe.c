#include "shell.h"

/**
 * main - execute the program
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	size_t n = 0;
        char *buf = NULL;
	char *newargv[] = {"/bin/ls", "-l", NULL };
	printf("myshell$ ");
	

        getline(&buf,&n, stdin);


	int vec = execve(newargv[0], newargv, NULL);

	if (vec = -1)
		perror("Error");
}
