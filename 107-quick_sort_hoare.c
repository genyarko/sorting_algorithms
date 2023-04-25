#include "sort.h"

/**
 * quick_sort_hoare - sorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursion(array, 0, size - 1, size);
}

/**
 * quick_recursion - helper function for Quicksort
 * @array: array to sort
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void quick_recursion(int *array, size_t left, size_t right, size_t size)
{
	size_t pivot_index;

	if (left < right)
	{
		pivot_index = partition(array, left, right, size);
		quick_recursion(array, left, pivot_index - 1, size);
		quick_recursion(array, pivot_index, right, size);
	}
}

/**
 * partition - gives a pivot index for Quicksort using Hoare's scheme
 * @array: array to partition
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 *
 * Return: the index of the pivot element
 */
size_t partition(int *array, size_t left, size_t right, size_t size)
{
	int pivot_value = array[right];
	size_t i = left - 1, j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot_value);

		do {
			j--;
	
