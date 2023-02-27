#include "shell.h"
/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(detail *info, char **av)
{
        ssize_t r = 0;
        int bldin_ret = 0;

        while (r != -1 && bldin_ret != -2)
        {
                clear_info(info);
                if (interactive(info))
                        _puts("$ ");
                _eputchar(BUF_FLUSH);
                r = get_input(info);
                if (r != -1)
                {
                        set_info(info, av);
                        bldin_ret = find_bldin(info);
                        if (bldin_ret == -1)
                                find_cmd(info);
                }
                else if (interactive(info))
                        _putchar('\n');
                free_info(info, 0);
        }
        write_history(info);
        free_info(info, 1);
        if (!interactive(info) && info->status)
                exit(info->status);
        if (bldin_ret == -2)
        {
                if (info->err_num == -1)
                        exit(info->status);
                exit(info->err_num);
        }
        return (bldin_ret);
}
/**
 * find_bldin - finds a bldin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if bldin not found,
 *0 if bldin executed successfully,
 *1 if bldin found but not successful,
 *2 if bldin signals exit()
 */
int find_bldin(detail *info)
{
        int i, built_in_ret = -1;
        bldin_table bldintbl[] = {
                {"exit", _myexit},
                {"env", _myenv},
                {"help", _myhelp},
                {"history", _myhistory},
                {"setenv", _mysetenv},
                {"unsetenv", _myunsetenv},
                {"cd", _mycd},
                {"alias", _myalias},
                {NULL, NULL}
        };

        for (i = 0; bldintbl[i].type; i++)
                if (_strcmp(info->argv[0], bldintbl[i].type) == 0)
                {
                        info->line_count++;
                        built_in_ret = bldintbl[i].func(info);
                        break;
                }
        return (built_in_ret);
}
/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(detail *info)
{
        char *path = NULL;
        int i, k;

        info->path = info->argv[0];
        if (info->linecount_flag == 1)
        {
                info->line_count++;
                info->linecount_flag = 0;
        }
        for (i = 0, k = 0; info->arg[i]; i++)
                if (!is_delim(info->arg[i], " \t\n"))
                        k++;
        if (!k)
                return;

        path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
        if (path)
        {
                info->path = path;
                fork_cmd(info);
        }
        else
        {
                if ((interactive(info) || _getenv(info, "PATH=")
                                        || info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
                        fork_cmd(info);
                else if (*(info->arg) != '\n')
                {
                        info->status = 127;
                        print_error(info, "not found\n");
                }
        }
}
