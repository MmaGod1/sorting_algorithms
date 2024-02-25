#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in the array
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high]; /* Choose the last element as the pivot */
    int i = low - 1; /* Index of smaller element */

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            /* Swap array[i] and array[j] */
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size); /* Print array after swapping */
        }
    }
    /* Swap array[i + 1] and array[high] to place the pivot in the correct position */
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size); /* Print array after partitioning */

    /* Return the partition index */
    return i + 1;
}

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		/* Partition the array and get the partition index */
		pi = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
