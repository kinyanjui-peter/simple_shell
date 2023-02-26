#include "shell.h"
/**
 * fork_cmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(detail *info)
{
        pid_t child_pid;

        child_pid = fork();
        if (child_pid == -1)
        {
                /* TODO: PUT ERROR FUNCTION */
                perror("Error:");
                return;
        }
        if (child_pid == 0)
        {
                if (execve(info->path, info->argv, get_environ(info)) == -1)
                {
                        free_info(info, 1);
                        if (errno == EACCES)
                                exit(126);
                        exit(1);
                }
                /* TODO: PUT ERROR FUNCTION */
        }
        else
        {
                wait(&(info->status));
                if (WIFEXITED(info->status))
                {
                        info->status = WEXITSTATUS(info->status);
                        if (info->status == 126)
                                print_error(info, "Permission denied\n");
                }
        }
}
/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
        int i = 0;

        if (!s)
                return (0);

        while (*s++)
                i++;
        return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
        while (*s1 && *s2)
        {
                if (*s1 != *s2)
                        return (*s1 - *s2);
                s1++;
                s2++;
        }
        if (*s1 == *s2)
                return (0);
        else
                return (*s1 < *s2 ? -1 : 1);
}

