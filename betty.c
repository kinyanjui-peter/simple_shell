#include <stdio.h>
#include <unistd.h>

/**
 * main - prints proces id and ppid
 *Return: 0
 */
int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("child pid is%d\n", pid);
	return (0);
}
