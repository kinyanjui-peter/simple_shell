#include "shell.h"
/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(detail *info)
{
        roll_t *node = info->history;
        int i = 0;

        while (node)
        {
                node->num = i++;
                node = node->next;
        }
        return (info->histcount = i);
}
/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
roll_t *add_node(roll_t **head, const char *str, int num)
{
        roll_t *new_head;

        if (!head)
                return (NULL);
        new_head = malloc(sizeof(roll_t));
        if (!new_head)
                return (NULL);
        _memset((void *)new_head, 0, sizeof(roll_t));
        new_head->num = num;
        if (str)
        {
                new_head->str = _strdup(str);
 if (!new_head->str)
                {
                        free(new_head);
                        return (NULL);
                }
        }
        new_head->next = *head;
        *head = new_head;
        return (new_head);
}

