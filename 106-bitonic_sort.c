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

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - recursive function for bitonic sort
 * @array: array to sort
 * @left_index: index of the left-most element
 * @right_index: index of the right-most element
 * @direction: ascending or descending
 * @size: size of the array
 */
void bitonic_recursion(int *array, size_t left_index, size_t right_index, int direction, size_t size)
{
	size_t mid_index;

	if (right_index - left_index >= 1)
	{
		mid_index = (right_index + left_index) / 2;

		// Recursively sort the left and right halves of the array
		bitonic_recursion(array, left_index, mid_index, 1, size);
		bitonic_recursion(array, mid_index + 1, right_index, 0, size);

		// Merge the two halves of the array in the specified direction
		bitonic_merge(array, left_index, right_index, direction);
	}
}

/**
 * bitonic_merge - sorts and merges a sequence in ascending or descending order
 * @array: array to sort
 * @left_index: index of the left-most element
 * @right_index: index of the right-most element
 * @direction: ascending or descending
 */
void bitonic_merge(int *array, size_t left_index, size_t right_index, int direction)
{
	size_t mid_index = (right_index - left_index + 1) / 2;
	size_t i;
	int temp_value;

	if (right_index - left_index >= 1)
	{
		for (i = left_index; i < left_index + mid_index; i++)
		{
			if (direction == (array[i] > array[i + mid_index]))
			{
				// Swap the two elements if they are in the wrong order
				temp_value = array[i + mid_index];
				array[i + mid_index] = array[i];
				array[i] = temp_value;
			}
		}

