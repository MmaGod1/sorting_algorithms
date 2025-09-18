#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Merges a sequence in bitonic order
 * @array: array to sort
 * @size: total size of the array
 * @start: starting index of the sequence
 * @seq: size of the sequence
 * @dir: 1 for UP (ascending), 0 for DOWN (descending)
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int dir)
{
	if (seq > 1)
	{
		size_t i, k = seq / 2;

		for (i = start; i < start + k; i++)
		{
			if ((dir == 1 && array[i] > array[i + k]) ||
					(dir == 0 && array[i] < array[i + k]))
			{
				swap_ints(&array[i], &array[i + k]);
				print_array(array, size);
			}
		}
		bitonic_merge(array, size, start, k, dir);
		bitonic_merge(array, size, start + k, k, dir);
	}
}

/**
 * bitonic_seq - Recursively builds and sorts bitonic sequences
 * @array: array to sort
 * @size: total size of the array
 * @start: starting index of the sequence
 * @seq: size of the sequence
 * @dir: 1 for UP (ascending), 0 for DOWN (descending)
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, int dir)
{
	if (seq > 1)
	{
		size_t k = seq / 2;

		printf("Merging [%lu/%lu] (%s):\n", seq, size,
				dir ? "UP" : "DOWN");
		print_array(array + start, seq);

		bitonic_seq(array, size, start, k, 1);
		bitonic_seq(array, size, start + k, k, 0);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size,
				dir ? "UP" : "DOWN");
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 1);
}
