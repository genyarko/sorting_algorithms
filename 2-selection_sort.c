#include "sort.h"

/**
 * selection_sort -  sorts integers in ascending order using Selection sort
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t pass;

	for (pass = 0; pass < size - 1; pass++)
	{
		int min_index = pass;
		size_t i;

		for (i = pass + 1; i < size; i++)
		{
			if (array[i] < array[min_index])
				min_index = i;
		}
		swap(&array[min_index], &array[pass]);
		print_array(array, size);
	}
}

/**
 * swap - function for swapping values stored in an array
 * @a: first value to swap
 * @b: second value to swap
 */

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
