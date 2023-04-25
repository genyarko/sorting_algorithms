#include "sort.h"

/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_num;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	max_num = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max_num)
			max_num = array[i];

	for (lsd = 1; max_num / lsd > 0; lsd *= 10)
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
	int count_arr[10] = {0}, *output_array, digit, j;
	size_t i, k;

	output_array = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		count_arr[(array[i] / lsd) % 10]++;

	for (j = 1; j < 10; j++)
		count_arr[j] += count_arr[j - 1];

	for (k = size - 1; (int)k >= 0; k--)
	{
		digit = (array[k] / lsd) % 10;
		output_array[count_arr[digit] - 1] = array[k];
		count_arr[digit]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(output_array);
}
