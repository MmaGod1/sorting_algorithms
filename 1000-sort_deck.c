#include "deck.h"
#include <string.h>

/**
 * card_value - Converts a card's string value
 *		("Ace", "2", ..., "King") to an integer rank.
 * @card: Pointer to the card structure.
 *
 * Return: Integer rank of the card (Ace = 0, 2 = 1, ..., King = 12).
 */
int card_value(const char *value)
{
	const char *values[] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (i);
	}
	return (-1); /* Should never happen with valid input */
}

/**
 * compare_cards - Comparison function for two deck nodes, used with qsort.
 * @a: Pointer to the first deck node.
 * @b: Pointer to the second deck node.
 *
 * Return: Negative if @a comes before @b, positive if after, 0 if equal.
 *         Cards are ordered first by kind (Spades, Hearts, Clubs, Diamonds),
 *         then by value (Ace through King).
 */
int compare_cards(const void *a, const void *b)
{
	deck_node_t *node_a = *(deck_node_t **)a;
	deck_node_t *node_b = *(deck_node_t **)b;
	int kind_diff;

	kind_diff = node_a->card->kind - node_b->card->kind;
	if (kind_diff != 0)
		return (kind_diff);

	return (card_value(node_a->card->value) - card_value(node_b->card->value));
}

/**
 * sort_deck - Sorts a deck of 52 cards in ascending order.
 * @deck: Double pointer to the head of the doubly linked list of deck nodes.
 *
 * Description: The deck is sorted from Ace to King within each suit,
 *              and suits are ordered Spades, Hearts, Clubs, Diamonds.
 *              The function uses qsort internally to sort an array of
 *              pointers to the deck nodes, then relinks the list.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *node;
	deck_node_t **array;
	size_t i, size = 0;

	if (!deck || !*deck)
		return;

	/* Count cards */
	for (node = *deck; node; node = node->next)
		size++;

	/* Build array of nodes */
	array = malloc(size * sizeof(*array));
	if (!array)
		return;

	node = *deck;
	for (i = 0; i < size; i++)
	{
		array[i] = node;
		node = node->next;
	}

	/* Sort array with qsort */
	qsort(array, size, sizeof(*array), compare_cards);

	/* Rebuild linked list */
	for (i = 0; i < size; i++)
	{
		array[i]->prev = (i > 0) ? array[i - 1] : NULL;
		array[i]->next = (i < size - 1) ? array[i + 1] : NULL;
	}

	*deck = array[0]; /* Update head */
	free(array);
}
