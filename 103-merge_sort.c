#include "sort.h"
/**
 * merge_sort - sorts an array with the Merge Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);

	if (!buffer)
		return;

	top_down_merge_sort(array, buffer, 0, size);
	free(buffer);
}

/**
 * top_down_merge_sort - recursive function that merge sorts an array
 * @array: array to merge sort
 * @buffer: temporary buffer used for merging
 * @left: index of the left element
 * @right: index of the right element
 */
void top_down_merge_sort(int *array, int *buffer, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		top_down_merge_sort(array, buffer, left, middle);
		top_down_merge_sort(array, buffer, middle, right);
		merge_subarray(array, buffer, left, middle, right);
	}
}

/**
 * merge_subarray - merges subarrays
 * @array: array to merge
 * @buffer: temporary buffer used for merging
 * @left: index of the left element
 * @middle: index of the middle element
 * @right: index of the right element
 */
void merge_subarray(int *array, int *buffer, size_t left,
		size_t middle, size_t right)
{
	size_t i = left, j = middle, k = 0;

	while (i < middle && j < right)
	{
		if (array[i] < array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}

	while (i < middle)
		buffer[k++] = array[i++];
	while (j < right)
		buffer[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = buffer[i++];
}
