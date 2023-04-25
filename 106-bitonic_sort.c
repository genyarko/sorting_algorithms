#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}

/**
 * bitonic_sort_recursive - recursive helper function for bitonic_sort
 * @array: array to sort
 * @start: start index of subarray to sort
 * @size: size of the subarray to sort
 * @dir: sort direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        bitonic_merge(array, start, mid, dir);
        bitonic_sort_recursive(array, start, mid, dir);
        bitonic_sort_recursive(array, start + mid, mid, !dir);
    }
}

/**
 * bitonic_merge - merges two subarrays in bitonic order
 * @array: array to sort
 * @start: start index of the first subarray
 * @size: size of each subarray
 * @dir: sort direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
    if (size > 1)
    {
        size_t i, j, k;
        size_t mid = start + size / 2;

        for (i = start; i < mid; i++)
        {
            if ((array[i] > array[mid + i - start]) == dir)
                swap(&array[i], &array[mid + i - start]);
        }

        bitonic_merge(array, start, size / 2, dir);
        bitonic_merge(array, mid, size / 2, dir);
    }
}

/**
 * swap - swaps two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
