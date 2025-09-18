#include "sort.h"

/**
 * bitonic_merge - Merge a bitonic sequence in ascending or descending order
 * @array: array to sort
 * @size: total size of array (for printing)
 * @start: starting index of sequence
 * @cnt: number of elements to merge
 * @dir: direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t cnt, int dir)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;
        size_t i;

        /* Compare and swap elements */
        for (i = start; i < start + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                print_array(array, size);
            }
        }

        /* Recursively merge both halves */
        bitonic_merge(array, size, start, k, dir);
        bitonic_merge(array, size, start + k, k, dir);
    }
}

/**
 * bitonic_sort_rec - Recursively create bitonic sequence and sort
 * @array: array to sort
 * @size: total size of array (for printing)
 * @start: starting index
 * @cnt: number of elements in current sequence
 * @dir: direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_rec(int *array, size_t size, size_t start, size_t cnt, int dir)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;

        printf("Merging [%lu/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + start, cnt);

        /* Sort first half in ascending order */
        bitonic_sort_rec(array, size, start, k, 1);
        
        /* Sort second half in descending order */
        bitonic_sort_rec(array, size, start + k, k, 0);
        
        /* Merge the whole sequence in the specified direction */
        bitonic_merge(array, size, start, cnt, dir);

        printf("Result [%lu/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + start, cnt);
    }
}

/**
 * bitonic_sort - Sort array using bitonic sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_rec(array, size, 0, size, 1);
}
