#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Test the selection_sort function
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    size_t size = sizeof(array) / sizeof(array[0]);
    int i;

    printf("Original array: ");
    print_array(array, size);

    selection_sort(array, size);

    printf("Sorted array: ");
    print_array(array, size);

    return (0);
}
