#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

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



void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void sortedInsert(listint_t  **head_ref, listint_t  **newNode);
void swap(int *a, int *b);
void q_sort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void switch_nodes(listint_t **list, listint_t **p);
void cocktail_sort_list(listint_t **list);
void print_list(const listint_t *list);
listint_t *add_node_end(listint_t **list, const int n);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_recursion(int *arr, int *array, size_t left, size_t right);
void merge_subarray(int *arr, int *array, size_t left,
		size_t middle, size_t right);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t s, size_t root, size_t size);
void radix_sort(int *array, size_t size);
void count_sort_LSD(int *array, size_t size, size_t lsd);
void quick_sort_hoare(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_recursion(int *array, int l, int r, int direction, size_t size);
void bitonic_merge(int *array, int l, int r, int direction);

#endif
