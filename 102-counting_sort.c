#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting Sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max, i;
	size_t j;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);
	for (j = size; j > 0; j--)
	{
		output[count[array[j - 1]] - 1] = array[j - 1];
		count[array[j - 1]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = output[j];
	free(count);
	free(output);
}
