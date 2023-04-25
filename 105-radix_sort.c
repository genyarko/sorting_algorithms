#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - sorts an array using Radix Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array to sort
 */
void radix_sort(int *array, size_t size)
{
	int *sorted_arr = NULL;
	size_t i, j, max_num = 0, digit = 1;

	if (!array || size < 2)
		return;

	sorted_arr = malloc(sizeof(int) * size);
	if (!sorted_arr)
		return;

	for (i = 0; i < size; i++)
		max_num = (array[i] > max_num) ? array[i] : max_num;

	while (max_num / digit > 0)
	{
		size_t count[10] = {0};

		for (i = 0; i < size; i++)
			count[(array[i] / digit) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (j = size - 1; (int)j >= 0; j--)
		{
			sorted_arr[--count[(array[j] / digit) % 10]] = array[j];
		}

		for (i = 0; i < size; i++)
			array[i] = sorted_arr[i];

		print_array(array, size);
		digit *= 10;
	}

	free(sorted_arr);
}
