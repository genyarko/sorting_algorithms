#include "sort.h"

/**
 * bubble_sort - sorts array of int in ascending order using Bubble sort
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int pass, i;

	for (pass = 0; pass < size; pass++)
	{
		int swapped = 0;

		for (i = 0; i < size - pass - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int temp = array[i];

				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;

			}
		}
		if (swapped == 0)
			break;
		print_array(array, size);
	}
}
