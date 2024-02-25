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
    /* Choose the pivot element */
    int pivot = array[high];
    int i = low - 1;
    int j, tmp;

    /* Partition the array */
    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            /* Swap elements */
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            /* Print array after each swap */
            print_array(array, size);
        }
    }
    
    /* Swap pivot element to its correct position */
    tmp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = tmp;
    /* Print array after placing pivot in its correct position */
    print_array(array, size);
    
    return (i + 1); /* Return partition index */
}

/**                                                            * quick_sort_recursive - Recursive function to implement Quic
k sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
        int pi;

        if (low < high)
        {
                pi = lomuto_partition(array, low, high, size);
                quick_sort_recursive(array, low, pi - 1, size)
;               quick_sort_recursive(array, pi + 1, high, size);
	}
}

void quick_sort(int *array, size_t size)
{
    /* Check if the array is empty or contains only one element */
    if (array == NULL || size < 2)
        return;
    /* Call recursive quick sort function */
    quick_sort_recursive(array, 0, size - 1, size);
}
