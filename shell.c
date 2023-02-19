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
	char **arr;//[];// = {command, NULL};
	pid_t pid;
	int step;
	char *tkn;
	int i;
//	int status = system("command");
	

	while(1)
	{
		printf("$ ");
		getline(&command,&n, stdin);
		tkn = strtok(command, "\n"); 
		arr = malloc(sizeof(char *) * 32);
		arr[0] = tkn;
		int status = system(command);
		{
			if (status == -1)
			{
				printf("command not found.\n");
			}
		}		
		if (strcmp(arr[0], "exit") == 0)
		{
			exit(0);
		}
		i = 1;
		while (tkn != NULL)
		{
			tkn = strtok(NULL, "\n");
			arr[i] = tkn;
			i++;	
		}
		pid = fork();
		if (pid == 0)
		{
			execve(arr[0], arr, NULL);
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
