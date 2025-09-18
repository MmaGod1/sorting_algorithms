#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algoritms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *create_node(const int *array, size_t size);
void free_list(listint_t *head);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int forward_pass(listint_t **list, listint_t *start, listint_t *end);
int backward_pass(listint_t **list, listint_t *start, listint_t *end);
void cocktail_sort_list(listint_t **list);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right);
void merge_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t n, size_t i);
void heap_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void swap_ints(int *a, int *b);

#endif /* SORT_H */
