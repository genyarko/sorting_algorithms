#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers using the Bitonic sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array to be sorted.
 **/
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_helper(array, 0, size, 1);
}

/**
 * bitonic_sort_helper - Recursive helper function for bitonic_sort.
 * @array: The array of integers to be sorted.
 * @start: The starting index of the subarray to be sorted.
 * @size: The size of the subarray to be sorted.
 * @dir: The direction of the sort (1 for ascending, -1 for descending).
 **/
void bitonic_sort_helper(int *array, size_t start, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2;

        bitonic_sort_helper(array, start, k, 1);
        bitonic_sort_helper(array, start + k, k, -1);
        bitonic_merge(array, start, size, dir);
    }
}

/**
 * bitonic_merge - Merges two subarrays in a bitonic manner.
 * @array: The array of integers to be sorted.
 * @start: The starting index of the subarray to be merged.
 * @size: The size of the subarray to be merged.
 * @dir: The direction of the sort (1 for ascending, -1 for descending).
 **/
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2, i;

        for (i = start; i < start + k; i++)
        {
            if (dir == (array[i] > array[i + k]))
                swap(&array[i], &array[i + k]), printf("Swap %d <-> %d\n", array[i], array[i + k]);
        }

        bitonic_merge(array, start, k, dir);
        bitonic_merge(array, start + k, k, dir);
    }
}

/**
 * swap - Swaps two integer values.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 **/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
