#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array
 * @array: The original array
 * @temp: Temporary array for merging
 * @left: Start index of left subarray
 * @mid: End index of left subarray
 * @right: End index of right subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);
	for (i = left; i <= right; i++)
		temp[i] = array[i];

	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (temp[i] <= temp[j])
		{
			array[k] = temp[i];
			i++;
		}
		else
		{
			array[k] = temp[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		array[k] = temp[i];
		i++;
		k++;
	}
	while (j <= right)
	{
		array[k] = temp[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursively sorts array using merge sort
 * @array: The array to sort
 * @temp: Temporary array for merging
 * @left: Start index
 * @right: End index
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		/* Print current array being divided */
		printf("Merging [%lu..%lu] (size %lu): ", left, right, right - left + 1);
		print_array(array + left, right - left + 1);

		/* Recursively sort first and second halves */
		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid + 1, right);

		/* Merge the sorted halves */
		merge(array, temp, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge Sort algorithm (top-down)
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);

	free(temp);
}
