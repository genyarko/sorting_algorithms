#include "sort.h"

/**
 * bitonic_sort - sorts an array following the Bitonic sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_bitonic_sort(array, 0, size - 1, 1, size);
}

/**
 * recursive_bitonic_sort - recursive function for bitonic sort
 * @array: array to sort
 * @left: index of the left-most element
 * @right: index of the right-most element
 * @direction: ascending or descending
 * @size: size of the array
 */
void recursive_bitonic_sort(int *array, int left, int right, int direction, size_t size)
{
	int midpoint;

	if (right - left >= 1)
	{
		midpoint = (right + left) / 2;
		printf("Merging [%d/%lu] ", right - left + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + left, right - left + 1);
		recursive_bitonic_sort(array, left, midpoint, 1, size);
		recursive_bitonic_sort(array, midpoint + 1, right, 0, size);
		bitonic_merge(array, left, right, direction);
		printf("Result [%d/%lu] ", right - left + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + left, right - left + 1);
	}
}

/**
 * bitonic_merge - sorts and merges a sequence in ascending or descending order
 * @array: array to sort
 * @left: index of the left-most element
 * @right: index of the right-most element
 * @direction: ascending or descending
 */
void bitonic_merge(int *array, int left, int right, int direction)
{
	int tmp, i, midpoint = (left + right) / 2, mid = (right - left + 1) / 2;

	if (right - left >= 1)
	{
		for (i = left; i < left + mid; i++)
		{
			if (direction == (array[i] > array[i + mid]))
			{
				tmp = array[i + mid];
				array[i + mid] = array[i];
				array[i] = tmp;
			}
		}
		bitonic_merge(array, left, midpoint, direction);
		bitonic_merge(array, midpoint + 1, right, direction);
	}
}

}
