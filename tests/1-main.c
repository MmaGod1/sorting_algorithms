#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Your print_array and print_list functions */

int main(void)
{
    listint_t *list = NULL;
    listint_t *new_node;

    /* Create a linked list: 5 <-> 3 <-> 8 <-> 2 <-> 1 */
    int values[] = {5, 3, 8, 2, 1};
    size_t num_values = sizeof(values) / sizeof(values[0]);
    
    /* Populate the linked list */
    for (size_t i = 0; i < num_values; i++) {
        new_node = malloc(sizeof(listint_t));
        if (new_node == NULL)
            return (1);
        new_node->n = values[i];
        new_node->prev = NULL;
        new_node->next = list;
        if (list != NULL)
            list->prev = new_node;
        list = new_node;
    }

    printf("Original list: ");
    print_list(list);

    insertion_sort_list(&list);

    printf("Sorted list: ");
    print_list(list);

    return (0);
}
