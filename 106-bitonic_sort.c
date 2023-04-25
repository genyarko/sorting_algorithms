#include "sort.h"

/**
 * bitonic_sort - sorts an array following the Bitonic sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size - 1, 1, size);
}

/**
 * bitonic_sort_recursive - recursive function for bitonic sort
 * @array: array to sort
 * @left: index of the left-most element
 * @right: index of the right-most element
 * @direction: ascending or descending
 * @size: size of the array
 */
void bitonic_sort_recursive(int *array, int left, int right, int direction, size_t size)
{
	int step;

	if (right - left >= 1)
	{
		step = (right + left) / 2;
		printf("Merging [%d/%lu] ", right - left + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + left, right - left + 1);
		bitonic_sort_recursive(array, left, step, 1, size);
		bitonic_sort_recursive(array, step + 1, right, 0, size);
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
	int tmp, i, step = (left + right) / 2, mid = (right - left + 1) / 2;

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
		bitonic_merge(array, left, step, direction);
		bitonic_merge(array, step + 1, right, direction);
	}

}
