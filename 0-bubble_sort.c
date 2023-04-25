#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort algorithm.
 * @array: the array to sort.
 * @size: the size of the array.
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, swapnum, temp;
	bool swap;

	temp = 0;
	swap = true;
	while (swap && size >= 2)
	{
		swapnum = 0;
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapnum++;
				print_array(array, size);

			}
		}

		if (swapnum == 0)
			swap = false;
	}
	if (swap)
		return;
}
