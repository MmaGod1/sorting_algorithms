#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm and Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: Prints the array each time the interval decreases
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Build Knuth maximum sequence value less than size */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		/* Do gapped insertion sort for this gap size */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		print_array(array, size);

		/* Move to next gap */
		gap = (gap - 1) / 3;
	}
}
