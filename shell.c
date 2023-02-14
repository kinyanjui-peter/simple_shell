#include "shell.h"

/**
 * main - Display prompt
 *
 * Return: On Success 0
 */

int main(void)
{
	size_t n = 0;
	char *buf = NULL;

	printf("$ ");
	
	getline(&buf,&n, stdin);

	return 0;
}
