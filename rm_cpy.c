#include "shell.h"

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
        int i;
for (i = 0; buf[i] != '\0'; i++)
                if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
                {
                        buf[i] = '\0';
                        break;
                }
}
/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
        int i, j;
        char *s = dest;

        i = 0;
        while (src[i] != '\0' && i < n - 1)
        {
                dest[i] = src[i];
                i++;
        }
        if (i < n)
        {
                j = i;
                while (j < n)
                {
                        dest[j] = '\0';
                        j++;
                }
        }
        return (s);
}

