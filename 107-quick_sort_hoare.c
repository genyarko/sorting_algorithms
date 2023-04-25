#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * @array: array of integers to sort
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort(array, 0, size - 1, size);
}

/**
 * quick_sort - sorts a partition of an array of integers in ascending order
 * @array: array of integers to sort
 * @lo: the lowest index of the partition to sort
 * @hi: the highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = hoare_partition(array, lo, hi, size);
		quick_sort(array, lo, pivot - 1, size);
		quick_sort(array, pivot, hi, size);
	}
}

/**
 * hoare_partition - partitions an array of integers in ascending order
 * @array: array of integers to sort
 * @lo: the lowest index of the partition to sort
 * @hi: the highest index of the partition to sort
 * @size: size of the array
 *
 * Return: the pivot index
 */
int hoare_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i = lo - 1, j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return j;

		swap_int(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * swap_int - swaps two integers in an array
 * @a: the first integer
 * @b: the second integer
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
