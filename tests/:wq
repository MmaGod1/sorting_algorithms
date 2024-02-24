#include <stdio.h>
#include "../sort.h"

/**
 * create_node - Creates a new node with given value
 * @n: Value for the new node
 * Return: A pointer to the newly created node
 */
listint_t *create_node(int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (NULL);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_list - Frees a doubly linked list
 * @head: Pointer to the head of the list
 */
void free_list(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * main - Test the insertion_sort_list function
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *head = NULL;

	/* Create a doubly linked list */
	listint_t *node1 = create_node(4);
	listint_t *node2 = create_node(2);
	listint_t *node3 = create_node(1);
	listint_t *node4 = create_node(3);

	head = node1;
	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;
	node3->next = node4;
	node4->prev = node3;
	printf("Original list: ");
	print_list(head);

	/* Sort the list using insertion sort */
	insertion_sort_list(&head);
	printf("Sorted list: ");
	print_list(head);

	/* Free the memory allocated for the list */
	free_list(head);
	return (0);
}
