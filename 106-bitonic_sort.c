#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}

/**
 * bitonic_sort_recursive - Recursive helper function for bitonic_sort
 * @array: Pointer to the array to be sorted
 * @low: Index of the first element of the subarray to be sorted
 * @count: Number of elements in the subarray to be sorted
 * @dir: Direction of sorting, 1 for ascending, 0 for descending
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_merge - Merges two subarrays of an array in bitonic order
 * @array: Pointer to the array
 * @low: Index of the first element of the first subarray
 * @count: Number of elements in both subarrays
 * @dir: Direction of sorting, 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				swap(&array[i], &array[i + k]);
				print_array(array, count);
			}
		}

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * swap - Swaps two integer values
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
