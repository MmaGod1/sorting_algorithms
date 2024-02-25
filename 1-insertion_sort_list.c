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

    /* Check for NULL list or single node */
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    /* Start sorting from the second node */
    current = (*list)->next;

    /* Iterate through the list */
    while (current != NULL)
    {
        /* Store the previous node */
        tmp = current->prev;
        
        /* Iterate backwards until reaching the head or finding the correct position */
        while (tmp != NULL && tmp->n > current->n)
        {
            /* Adjust pointers to swap nodes */
            if (tmp->prev != NULL)
                tmp->prev->next = current;
            else
                *list = current;

            current->prev = tmp->prev;
            tmp->prev = current;
            tmp->next = current->next;

            if (current->next != NULL)
                current->next->prev = tmp;

            current->next = tmp;
            
            /* Move to the next pair of elements to compare */
            tmp = current->prev;
            
            /* Adjust 'current' pointer if 'tmp' is the head */
            if (tmp != NULL)
                current = tmp->next;
            else
                current = (*list)->next;

            /* Print the list after each swap */
            print_list(*list);
        }
        /* Move to the next element in the list */
        current = current->next;
    }
}
