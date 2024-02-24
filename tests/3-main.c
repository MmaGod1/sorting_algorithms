#include <stdio.h>
#include "../sort.h"

/**
 * main - Test the quick_sort function
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {10, 7, 8, 9, 1, 5};
	size_t size = sizeof(array) / sizeof(array[0]);
	int i;

	printf("Original array: ");
	print_array(array, size);

	quick_sort(array, size);

	printf("Sorted array: ");
	print_array(array, size);

	return (0);
}
