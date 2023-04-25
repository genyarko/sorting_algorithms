#include "sort.h"

/**
 * heap_sort - sorts an array using the Heap sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i < size; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - turns an array into a max heap
 * @array: array to turn into heap
 * @size: size of the array
 * @root: index of the root of the heap
 * @orig_size: original size of the array
 */
void heapify(int *array, size_t size, size_t root, size_t orig_size)
{
	size_t max, left, right;
	int tmp;

	max = root;
	left = (2 * root) + 1;
	right = (2 * root) + 2;

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
		heapify(array, size, max, orig_size);
	}
}
