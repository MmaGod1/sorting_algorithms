#include "sort.h"

/**
 * sift_down - Maintains the max heap property by sifting down
 * @array: The array to sort
 * @size: Total size of the array (for printing)
 * @n: Effective size of the heap
 * @i: Index to sift down from
 */
void sift_down(int *array, size_t size, size_t n, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	int temp;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		sift_down(array, size, n, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Build the max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, size, (size_t)i);

	/* Extract elements one by one */
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		/* Heapify reduced heap */
		sift_down(array, size, (size_t)i, 0);
	}
}
