#include "sort.h"

/**
 * swap_ints - Swap two integers in an array and print the array
 * @a: First integer
 * @b: Second integer
 * @array: The array
 * @size: Size of the array
 */
void swap_ints(int *a, int *b, int *array, size_t size)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    print_array(array, size);
}

/**
 * hoare_partition - Partition array using Hoare partition scheme
 * @array: Array to partition
 * @size: Size of the array
 * @low: Starting index
 * @high: Ending index
 *
 * Return: The partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        swap_ints(&array[i], &array[j], array, size);
    }
}

/**
 * quicksort_rec - Recursive quicksort function
 * @array: Array to sort
 * @size: Size of the array
 * @low: Starting index
 * @high: Ending index
 */
void quicksort_rec(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int pi = hoare_partition(array, size, low, high);
        quicksort_rec(array, size, low, pi);
        quicksort_rec(array, size, pi + 1, high);
    }
}

/**
 * quick_sort_hoare - Sort array using quicksort with Hoare partition
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_rec(array, size, 0, (int)size - 1);
}
