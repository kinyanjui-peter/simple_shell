#include "shell.h"
/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(detail *info, char *buf, size_t *i)
{
        ssize_t r = 0;

        if (*i)
                return (0);
        r = read(info->readfd, buf, READ_BUF_SIZE);
        if (r >= 0)
                *i = r;
        return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(detail *info, char **ptr, size_t *length)
{
        static char buf[READ_BUF_SIZE];
        static size_t i, len;
        size_t k;
        ssize_t r = 0, s = 0;
        char *p = NULL, *new_p = NULL, *c;

        p = *ptr;
        if (p && length)
                s = *length;
        if (i == len)
                i = len = 0;

        r = read_buf(info, buf, &len);
        if (r == -1 || (r == 0 && len == 0))
                return (-1);

        c = _strchr(buf + i, '\n');
        k = c ? 1 + (unsigned int)(c - buf) : len;
        new_p = _realloc(p, s, s ? s + k : k + 1);
        if (!new_p) /* MALLOC FAILURE! */
                return (p ? free(p), -1 : -1);
	if (s)
                _strncat(new_p, buf + i, k - i);
        else
                _strncpy(new_p, buf + i, k - i + 1);

        s += k - i;
        i = k;
        p = new_p;

        if (length)
                *length = s;
        *ptr = p;
        return (s);
}

