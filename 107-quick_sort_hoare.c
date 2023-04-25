#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm with Hoare partition scheme
 * @array: pointer to the array to sort
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - recursive function for the Quick sort algorithm
 * using the Hoare partition scheme
 * @array: pointer to the array to sort
 * @left: left index of the subarray to sort
 * @right: right index of the subarray to sort
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort_recursive(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		quick_sort_recursive(array, left, pivot, size);
		quick_sort_recursive(array, pivot + 1, right, size);
	}
}

/**
 * partition - performs the partition step of the Quick sort algorithm
 * using the Hoare partition scheme
 * @array: pointer to the array to sort
 * @left: left index of the subarray to sort
 * @right: right index of the subarray to sort
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right], tmp;
	int i = left - 1, j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		if (i != j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
}
