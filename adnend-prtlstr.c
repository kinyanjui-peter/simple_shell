#include "shell.h"
/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
roll_t *add_node_end(roll_t **head, const char *str, int num)
{
        roll_t *new_node, *node;

        if (!head)
                return (NULL);

        node = *head;
        new_node = malloc(sizeof(roll_t));
        if (!new_node)
                return (NULL);
        _memset((void *)new_node, 0, sizeof(roll_t));
        new_node->num = num;
        if (str)
        {
                new_node->str = _strdup(str);
                if (!new_node->str)
                {
                        free(new_node);
                        return (NULL);
                }
        }
        if (node)
        {
                while (node->next)
 node = node->next;
                node->next = new_node;
        }
        else
                *head = new_node;
        return (new_node);
}

/**
 * print_list_str - prints only the str element of a roll_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const roll_t *h)
{
        size_t i = 0;

        while (h)
        {
                _puts(h->str ? h->str : "(nil)");
                _puts("\n");
                h = h->next;
                i++;
        }
        return (i);
}

