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
//	ssize_t read;	
	char *argv[] = {command, NULL};
	while(1)
	{
		write(1, "$ ", 2);
		getline(&command,&n, stdin);
		int status = system(command);
		{
			if (status == -1)
			{
				printf("command not found.\n");
				exit(0);
			}
		}
		if (argv == 0) 
		{
			exit(0);
		}

		execve(argv[0], argv, NULL);
	}
	free(command);
	return (0);
}
