#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        tmp = current->prev;
        while (tmp != NULL && tmp->n > current->n)
        {
            tmp->next->prev = tmp->prev;
            if (tmp->prev != NULL)
                tmp->prev->next = tmp->next;
            else
                *list = tmp->next;

            tmp->next = tmp->prev;
            tmp->prev = tmp->next->prev;
            tmp->next->prev = tmp;

            if (tmp->prev != NULL)
                tmp->prev->next = tmp;
            else
                *list = tmp;

            print_list(*list);
            tmp = tmp->prev;
        }
        current = current->next;
    }
}
