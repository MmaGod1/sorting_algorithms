#include "sort.h"
/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: Pointer to the array of integers
 * @low: Starting index of the partition to sort
 * @high: Ending index of the partition to sort (pivot position)
 * @size: Total number of elements in the array
 *
 * Return: The final index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - Recursively applies quick sort
 * @array: Pointer to the array of integers
 * @low: Starting index of the current partition
 * @high: Ending index of the current partition
 * @size: Total number of elements in the array
 *
 * This function applies quick sort by calling the lumoto function
 * then recursively sorting the left and right partitions until the
 * base case (1 element or empty partition) is reached.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 *
 * This is the main wrapper for the quick sort algorithm.
 * It checks for valid input and calls the recursive function
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}
