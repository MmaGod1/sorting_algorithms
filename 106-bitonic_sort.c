#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - Merge a bitonic sequence
 * @array: array to sort  
 * @size: total size of array
 * @start: starting index
 * @cnt: count of elements to merge
 * @dir: direction (1 for UP, 0 for DOWN)
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t cnt, int dir)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;
        size_t i;

        for (i = start; i < start + k; i++)
        {
            if ((dir == 1 && array[i] > array[i + k]) ||
                (dir == 0 && array[i] < array[i + k]))
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                print_array(array, size);
            }
        }
        bitonic_merge(array, size, start, k, dir);
        bitonic_merge(array, size, start + k, k, dir);
    }
}

/**
 * bitonic_sort_rec - Recursively build and sort bitonic sequences
 * @array: array to sort
 * @size: total size of array  
 * @start: starting index
 * @cnt: count of elements
 * @dir: direction (1 for UP, 0 for DOWN)
 */
void bitonic_sort_rec(int *array, size_t size, size_t start, size_t cnt, int dir)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;

        /* Recursively sort first half ascending */
        bitonic_sort_rec(array, size, start, k, 1);
        /* Recursively sort second half descending */  
        bitonic_sort_rec(array, size, start + k, k, 0);

        /* Now merge the bitonic sequence */
        printf("Merging [%lu/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + start, cnt);
        
        bitonic_merge(array, size, start, cnt, dir);
        
        printf("Result [%lu/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + start, cnt);
    }
}

/**
 * bitonic_sort - Sort an array using bitonic sort
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_rec(array, size, 0, size, 1);
}
