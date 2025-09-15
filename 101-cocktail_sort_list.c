#include "sort.h"

/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @left: pointer to the first node
 * @right: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list - Sort a doubly linked list in ascending order
 *                     using the cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start, *end, *current;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;

	while (swapped)
	{
		swapped = 0;
		for (current = start; current->next != end; current = current->next)
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
				current = current->prev;
			}
		end = current;
		if (!swapped)
			break;

		swapped = 0;
		for (current = end->prev; current != start->prev; current = current->prev)
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
				current = current->next;
			}
		start = current->next;
	}
}
