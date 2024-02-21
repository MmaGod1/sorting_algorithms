#include "../sort.h"

/**
 * main - Test the bubble_sort function
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    size_t size = sizeof(array) / sizeof(array[0]);
    
    printf("Original array: ");
    print_array(array, size);

    bubble_sort(array, size);

    printf("Sorted array: ");
    print_array(array, size);

    return (0);
}
