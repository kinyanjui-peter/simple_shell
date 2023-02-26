#include "shell.h"
/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(detail *info)
{
        int i;

        if (info->argc == 1)
        {
                _eputs("Too few arguements.\n");
                return (1);
        }
        for (i = 1; i <= info->argc; i++)
                _unsetenv(info, info->argv[i]);

        return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(detail *info)
{
        roll_t *node = NULL;
        size_t i;

        for (i = 0; environ[i]; i++)
                add_node_end(&node, environ[i], 0);
        info->env = node;
        return (0);
}
