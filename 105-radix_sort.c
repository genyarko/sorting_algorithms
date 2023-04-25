#include "sort.h"

/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = 0;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	/* Find maximum value in array */
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	/* Sort array for each digit */
	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * count_sort_LSD - count sort with LSD
 * @array: array to sort
 * @size: size of the array
 * @lsd: least significant digit
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_arr[10] = {0}, l, m, temp;
	size_t k, n;

	for (k = 0; k < size; k++)
		count_arr[(array[k] / lsd) % 10]++;

	for (l = 1; l < 10; l++)
		count_arr[l] += count_arr[l - 1];

	for (m = size - 1; m >= 0; m--)
	{
		temp = array[m];
		array[--count_arr[(temp / lsd) % 10]] = temp;
	}
}
