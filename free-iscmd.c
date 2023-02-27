#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
        if (ptr && *ptr)
        {
                free(*ptr);
                *ptr = NULL;
                return (1);
        }
        return (0);
}
/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(detail *info, char *path)
{
        struct stat st;

        (void)info;
        if (!path || stat(path, &st))
                return (0);

        if (st.st_mode & S_IFREG)
        {
                return (1);
        }
        return (0);
}

