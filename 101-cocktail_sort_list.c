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
	right->prev = left->prev;
	left->next = right->next;
	right->next = left;
	left->prev = right;
}

/**
 * forward_pass - Perform forward pass of cocktail sort
 * @list: pointer to the head of the list
 * @start: starting node for the pass
 * @end: ending node for the pass
 * Return: 1 if swap occurred, 0 otherwise
 */
int forward_pass(listint_t **list, listint_t *start, listint_t *end)
{
	int swapped = 0;
	listint_t *current = start;

	while (current && current->next && current->next != end)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			swapped = 1;
			print_list(*list);
		}
		else
			current = current->next;
	}
	return (swapped);
}

/**
 * backward_pass - Perform backward pass of cocktail sort
 * @list: pointer to the head of the list
 * @start: starting node for the pass
 * @end: ending node for the pass
 * Return: 1 if swap occurred, 0 otherwise
 */
int backward_pass(listint_t **list, listint_t *start, listint_t *end)
{
	int swapped = 0;
	listint_t *current = end;

	while (current && current->prev && current->prev != start->prev)
	{
		if (current->prev->n > current->n)
		{
			swap_nodes(list, current->prev, current);
			swapped = 1;
			print_list(*list);
		}
		else
			current = current->prev;
	}
	return (swapped);
}

/**
 * cocktail_sort_list - Sort a doubly linked list using cocktail sort
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int forward_swapped, backward_swapped;
	listint_t *start, *end, *current;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;

	do {
		/* Forward pass: move largest to end */
		forward_swapped = forward_pass(list, start, end);

		/* Find the new end (last unsorted element) */
		current = start;
		while (current && current->next && current->next != end)
			current = current->next;
		end = current->next;

		if (!forward_swapped)
			break;

		/* Backward pass: move smallest to start */
		backward_swapped = backward_pass(list, start, end);

		/* Advance start to next unsorted element */
		if (start)
			start = start->next;

	} while (forward_swapped || backward_swapped);
}
