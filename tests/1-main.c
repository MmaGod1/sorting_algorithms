#include "../sort.h"

int main(void)
{
    listint_t *list = NULL;

    /* Create a linked list with elements: 4 <-> 2 <-> 1 <-> 3 */
    list = create_node(4);
    list->next = create_node(2);
    list->next->prev = list;
    list->next->next = create_node(1);
    list->next->next->prev = list->next;
    list->next->next->next = create_node(3);
    list->next->next->next->prev = list->next->next;

    printf("Original list:\n");
    print_list(list);

    printf("\nSorting the list:\n");
    insertion_sort_list(&list);
    print_list(list);

    /* Free the memory allocated for the list */
    while (list != NULL)
    {
        listint_t *tmp = list;
        list = list->next;
        free(tmp);
    }

    return (0);
}
