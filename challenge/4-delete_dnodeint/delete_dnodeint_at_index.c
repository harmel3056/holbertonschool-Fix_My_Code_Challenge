#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head, *tmp;
    unsigned int p = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    saved_head = *head;

    /* move to the node at index */
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;
        p++;
    }

    if (*head == NULL)  /* index out of range */
    {
        *head = saved_head;
        return (-1);
    }

    /* delete head */
    if (index == 0)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;

        if (tmp)
            tmp->prev = NULL;

        return (1);
    }

    /* delete middle or tail node */
    tmp = *head;

    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;

    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    free(tmp);

    *head = saved_head;
    return (1);
}
