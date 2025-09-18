#include "deck.h"
#include <string.h>

/**
 * card_value - Get the numeric value of a playing card.
 * @value: The string representing the card's value (e.g. "Ace", ..., "King").
 * Return: Numeric rank of the card (Ace = 0, 2 = 1, ..., King = 12).
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
 * compare_cards - Compare two cards for sorting.
 * @a: Pointer to the first deck node.
 * @b: Pointer to the second deck node.
 *
 * Return: Negative value if @a should come before @b,
 *         positive value if @a should come after @b,
 *         or 0 if they are equal.
 *
 * Description: Sorts primarily by kind (Spade, Heart, Club, Diamond),
 * then by value (Ace through King).
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
 * sort_deck - Sort a 52-card deck of playing cards.
 * @deck: Double pointer to the head of the deck.
 *
 * Description: Sorts the deck in ascending order, from Ace to King,
 * with suits ordered Spades → Hearts → Clubs → Diamonds.
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
