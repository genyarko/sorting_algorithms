#include "sort.h"

/**
 * counting_sort - sorts an array with the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *out_arr, max, num;
	size_t i, j, k;

	if (size < 2)
		return;

	/* Find the maximum value in the array */
	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	/* Allocate memory for the counting array and the output array */
	count_arr = malloc(sizeof(int) * (max + 1));
	out_arr = malloc(sizeof(int) * size);

	/* Initialize the counting array */
	for (j = 0; j <= max; j++)
		count_arr[j] = 0;

	/* Count the occurrences of each value */
	for (k = 0; k < size; k++)
	{
		num = array[k];
		count_arr[num]++;
	}

	/* Accumulate the counts */
	for (j = 1; j <= max; j++)
		count_arr[j] += count_arr[j - 1];

	/* Sort the array */
	for (k = size - 1; k != (size_t)-1; k--)
	{
		num = array[k];
		out_arr[count_arr[num] - 1] = num;
		count_arr[num]--;
	}

	/* Copy the sorted array back to the input array */
	for (i = 0; i < size; i++)
		array[i] = out_arr[i];

	/* Free the memory */
	free(count_arr);
	free(out_arr);
}
