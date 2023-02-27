#include "shell.h"
/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(roll_t **head, unsigned int index)
{
        roll_t *node, *prev_node;
        unsigned int i = 0;

        if (!head || !*head)
                return (0);

        if (!index)
 {
                node = *head;
                *head = (*head)->next;
                free(node->str);
                free(node);
                return (1);
        }
        node = *head;
        while (node)
        {
                if (i == index)
                {
                        prev_node->next = node->next;
                        free(node->str);
                        free(node);
                        return (1);
                }
                i++;
                prev_node = node;
                node = node->next;
        }
        return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(roll_t **head_ptr)
{
        roll_t *node, *next_node, *head;

        if (!head_ptr || !*head_ptr)
                return;
        head = *head_ptr;
        node = head;
        while (node)
        {
                next_node = node->next;
                free(node->str);
                free(node);
                node = next_node;
}
        *head_ptr = NULL;
}

