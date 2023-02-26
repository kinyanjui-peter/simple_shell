#include "shell.h"
/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(detail *info)
{
        print_list_str(info->env);
        return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(detail *info, const char *name)
{
        roll_t *node = info->env;
        char *p;

        while (node)
        {
                p = starts_with(node->str, name);
                if (p && *p)
                        return (p);
                node = node->next;
        }
        return (NULL);
}
/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(detail *info)
{
        if (info->argc != 3)
        {
                _eputs("Incorrect number of arguements\n");
                return (1);
        }
        if (_setenv(info, info->argv[1], info->argv[2]))
                return (0);
        return (1);
}
