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
	int i, fd;
	ssize_t read;
	char *newenviron[] = { NULL };
//	int status = system("command");
	

	while(1)
	{
//		printf("$ ");
		write(1, "$ ", 2);
		read = getline(&command,&n, stdin);
//		printf("check -3\n");
		tkn = strtok(command, " \n");

//		printf("check -4");
		arr = malloc(sizeof(char *) * 32);
//		printf("check -2");
		arr[0] = tkn;
		int status = system(command);
		{
			if (status == -1)
			{
				printf("command not found.\n");
				exit(0);
			}
//			printf("check -1");
		}		
			if (strcmp(arr[0], "exit") == 0)
		{
			exit(0);
		}
		i = 1;
		while (tkn != NULL)
		{
			tkn = strtok(NULL, " \n");
//			printf("second check1\n");
			arr[i] = tkn;
			i++;	
		}
		pid = fork();
		if (pid == 0)
		{
			execve(arr[0], arr, newenviron);
		}
		if (pid == -1)
		{
			perror("error");
		}
	else
		{
			wait(&step);
		}
	}
	if (pid == -1)
	{
		perror("error");
	}
	free(arr);
	free(command);
	return (0);
}
