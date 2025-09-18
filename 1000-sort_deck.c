#include "deck.h"
#include <string.h>

/**
 * get_card_value - Get numeric value of card for sorting
 * @value: String value of the card
 *
 * Return: Numeric value for sorting (1-13)
 */
int get_card_value(const char *value)
{
	if (strcmp(value, "Ace") == 0)
		return (1);
	else if (strcmp(value, "2") == 0)
		return (2);
	else if (strcmp(value, "3") == 0)
		return (3);
	else if (strcmp(value, "4") == 0)
		return (4);
	else if (strcmp(value, "5") == 0)
		return (5);
	else if (strcmp(value, "6") == 0)
		return (6);
	else if (strcmp(value, "7") == 0)
		return (7);
	else if (strcmp(value, "8") == 0)
		return (8);
	else if (strcmp(value, "9") == 0)
		return (9);
	else if (strcmp(value, "10") == 0)
		return (10);
	else if (strcmp(value, "Jack") == 0)
		return (11);
	else if (strcmp(value, "Queen") == 0)
		return (12);
	else if (strcmp(value, "King") == 0)
		return (13);

	return (0); /* Should not reach here */
}

/**
 * compare_cards - Compare function for qsort
 * @a: First card node
 * @b: Second card node
 *
 * Return: Comparison result for qsort
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;

	int value_a = get_card_value(node_a->card->value);
	int value_b = get_card_value(node_b->card->value);

	/* First sort by card value */
	if (value_a != value_b)
		return (value_a - value_b);

	/* If values are same, sort by suit (SPADE, HEART, CLUB, DIAMOND) */
	return ((int)node_a->card->kind - (int)node_b->card->kind);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *nodes[52];
	deck_node_t *current;
	int i, count = 0;

	if (!deck || !*deck)
		return;

	/* Convert linked list to array */
	current = *deck;
	while (current && count < 52)
	{
		nodes[count] = current;
		current = current->next;
		count++;
	}

	/* Sort the array using qsort */
	qsort(nodes, count, sizeof(deck_node_t *), compare_cards);

	/* Rebuild the doubly linked list */
	for (i = 0; i < count; i++)
	{
		if (i == 0)
		{
			nodes[i]->prev = NULL;
			*deck = nodes[i];
		}
		else
		{
			nodes[i]->prev = nodes[i - 1];
			nodes[i - 1]->next = nodes[i];
		}

		if (i == count - 1)
			nodes[i]->next = NULL;
	}
}
