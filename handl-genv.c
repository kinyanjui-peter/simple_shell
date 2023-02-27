#include "shell.h"
/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
        _puts("\n");
        _puts("$ ");
        _putchar(BUF_FLUSH);
}
/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(detail *info)
{
        if (!info->environ || info->env_changed)
        {
                info->environ = roll_to_strings(info->env);
                info->env_changed = 0;
        }

        return (info->environ);
}

