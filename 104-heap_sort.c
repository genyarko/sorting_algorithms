#include "sort.h"

/**
 * heap_sort - sorts an array following the Heap sort algorithm
 * @array: array of ints to sort
 * @size: size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify_down(array, (size_t)i, 0, size);
	}
}

/**
 * heapify_down - turns an array into a heap tree
 * @array: array to turn into heap
 * @size: size of the heap
 * @root: index of the root of the subtree
 * @orig_size: original size of the array
 */
void heapify_down(int *array, size_t size, size_t root, size_t orig_size)
{
	size_t max, left, right;
	int tmp;

	max = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < size && array[left] > array[max])
		max = left;

	if (right < size && array[right] > array[max])
		max = right;

	if (max != root)
	{
		tmp = array[root];
		array[root] = array[max];
		array[max] = tmp;
		print_array(array, orig_size);
		heapify_down(array, size, max, orig_size);
	}
}
