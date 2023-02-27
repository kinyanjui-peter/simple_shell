#include "shell.h"
/**
 * print_list - prints all elements of a roll_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const roll_t *h)
{
        size_t i = 0;

        while (h)
        {
                _puts(convert_number(h->num, 10, 0));
                _putchar(':');
                _putchar(' ');
                _puts(h->str ? h->str : "(nil)");
                _puts("\n");
                h = h->next;
                i++;
        }
        return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
roll_t *node_starts_with(roll_t *node, char *prefix, char c)
{
        char *p = NULL;

        while (node)
        {
                p = starts_with(node->str, prefix);
                if (p && ((c == -1) || (*p == c)))
                        return (node);
                node = node->next;
        }
        return (NULL);
}

