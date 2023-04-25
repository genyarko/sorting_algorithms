#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 * the Bitonic sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2 || !is_power_of_two(size))
		return;

	bitonic_sort_helper(array, size, 1);
}

/**
 * bitonic_sort_helper - Recursive function that performs the Bitonic sort.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 * @up: Flag to indicate whether to sort the array in ascending or descending order.
 *
 * Return: Nothing.
 */
void bitonic_sort_helper(int *array, size_t size, int up)
{
	if (size < 2)
		return;

	bitonic_merge(array, size, up);
	bitonic_sort_helper(array, size / 2, up);
	bitonic_sort_helper(array + size / 2, size / 2, !up);
}

/**
 * bitonic_merge - Merges two bitonic sequences.
 *
 * @array: Pointer to the array.
 * @size: The size of the array.
 * @up: Flag to indicate whether to sort the array in ascending or descending order.
 *
 * Return: Nothing.
 */
void bitonic_merge(int *array, size_t size, int up)
{
	if (size < 2)
		return;

	int i, j, k;
	int distance = size / 2;
	int temp;

	for (i = 0; i < size - distance; i++)
	{
		if ((array[i] > array[i + distance]) == up)
		{
			/* Swap array[i] and array[i+distance] */
			temp = array[i];
			array[i] = array[i + distance];
			array[i + distance] = temp;
			printf("Result [%lu/%lu]: ", size - distance + i, size + i);
			print_array(array, size);
		}
	}

	bitonic_merge(array, distance, up);
	bitonic_merge(array + distance, distance, up);
}

/**
 * is_power_of_two - Checks if a given number is a power of two.
 *
 * @n: The number to be checked.
 *
 * Return: 1 if @n is a power of two, 0 otherwise.
 */
int is_power_of_two(size_t n)
{
	return n && !(n & (n - 1));
}
