#include "shell.h"

int main(void)
{
	size_t len = 0;
	ssize_t read;
	char *command = NULL;
	char *argv[] = {command, NULL};

	while (read)
	{
		write(1, "$ ", 2);
		read = getline(&command, &len, stdin);
		argv[0] = read;
		printf("%s", command);
		execve(argv[0], argv, NULL);
	
	}
	free(command);
	return (0);
}

