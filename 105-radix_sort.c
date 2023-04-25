#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_val, digit;
	size_t i, j;
	int *output, *count;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);

	if (!output || !count)
		return;

	max_val = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}

	for (digit = 1; max_val / digit > 0; digit *= 10)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;

		for (i = 0; i < size; i++)
			count[(array[i] / digit) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (j = size - 1; (int) j >= 0; j--)
		{
			output[count[(array[j] / digit) % 10] - 1] = array[j];
			count[(array[j] / digit) % 10]--;
		}

		for (i = 0; i < size; i++)
			array[i] = output[i];

		print_array(array, size);
	}

	free(output);
	free(count);
}
