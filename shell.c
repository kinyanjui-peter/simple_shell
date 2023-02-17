#include "shell.h"

/**
 * main - Display prompt
 *
 * Return: On Success 0
 */

int main()
{
	size_t n = 0;
	char *command = NULL;
	char *argv[] = {"/bin/ls", NULL};
	pid_t pid;
	int step;

	while(1)
	{
		printf("$ ");
		getline(&command,&n, stdin);
		printf("%s, ",command);
		pid = fork();
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
//		if (pid == -1)
//		{
//			perror("error");
//		}
		else
		{
			wait(&step);
		}
	}
	if (pid == -1)
	{
		perror("error");
	}
	free(command);
	return (0);
}
