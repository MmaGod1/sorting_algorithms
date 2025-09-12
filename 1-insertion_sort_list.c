#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			listint_t *ptr = temp->prev;

			if (temp->next != NULL)
				temp->next->prev = ptr;
			ptr->next = temp->next;

			temp->prev = ptr->prev;
			temp->next = ptr;
			if (ptr->prev != NULL)
				ptr->prev->next = temp;
			ptr->prev = temp;

			/* Update head if needed */
			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}
	}
}
