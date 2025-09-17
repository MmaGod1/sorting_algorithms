#include <stdio.h>

/**
 * merge - Merges two sorted sub-arrays into one sorted array
 *
 * @array: The array containing the sub-arrays
 * @temp: Temporary array used for merging
 * @left: Starting index of the left sub-array
 * @mid: Ending index of the left sub-array, starting of the right
 * @right: Ending index of the right sub-array
 *
 * Return: Nothing
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively sorts an array using Merge sort
 *
 * @array: The array to be sorted
 * @temp: Temporary array used for merging
 * @left: Starting index of the current sub-array
 * @right: Ending index (exclusive) of the current sub-array
 *
 * Return: Nothing
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid, right);

	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: The number of elements in @array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
