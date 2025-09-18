#include "sort.h"

/**
 * get_max - Find the maximum value in an array
 * @array: The array
 * @size: Number of elements
 * Return: The maximum integer
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - A counting sort used by radix sort
 * @array: The array to sort
 * @size: Size of the array
 * @exp: The digit position to sort (1 = ones, 10 = tens, etc.)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Count occurrences of digits */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Transform count[] to contain actual positions */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build output array (stable sorting) */
	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	/* Copy back to original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 *		LSD radix sort
 * @array: The array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	/* Apply counting sort for every digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
