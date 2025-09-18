#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer.
 * @b: Second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array (for printing).
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The partition index.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high]; /* pivot = last element */
	int i = low - 1, j = high + 1;

	while (1)
	{
		/* Move right until >= pivot */
		do {
			i++;
		} while (array[i] < pivot);

		/* Move left until <= pivot */
		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quicksort_hoare - Recursive quicksort using Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index.
 * @high: The ending index.
 */
void quicksort_hoare(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, size, low, high);
		quicksort_hoare(array, size, low, p);
		quicksort_hoare(array, size, p + 1, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                   using Quick sort (Hoare partition scheme).
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, size, 0, (int)size - 1);
}
