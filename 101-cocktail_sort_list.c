
#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **ptr);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **ptr);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @ptr: A pointer to the current swapping node of the cocktail ptr algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **ptr)
{
	listint_t *tmp = (*ptr)->next;

	if ((*ptr)->prev != NULL)
		(*ptr)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*ptr)->prev;
	(*ptr)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *ptr;
	else
		*tail = *ptr;
	(*ptr)->prev = tmp;
	tmp->next = *ptr;
	*ptr = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @ptr: A pointer to the current swapping node of the cocktail ptr algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **ptr)
{
	listint_t *tmp = (*ptr)->prev;

	if ((*ptr)->next != NULL)
		(*ptr)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*ptr)->next;
	(*ptr)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *ptr;
	else
		*list = *ptr;
	(*ptr)->next = tmp;
	tmp->prev = *ptr;
	*ptr = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail ptr algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *ptr;
	bool ptr_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (ptr_not_stirred == false)
	{
		ptr_not_stirred = true;
		for (ptr = *list; ptr != tail; ptr = ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
				swap_node_ahead(list, &tail, &ptr);
				print_list((const listint_t *)*list);
				ptr_not_stirred = false;
			}
		}
		for (ptr = ptr->prev; ptr != *list;
				ptr = ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				swap_node_behind(list, &tail, &ptr);
				print_list((const listint_t *)*list);
				ptr_not_stirred = false;
			}
		}
	}
}
