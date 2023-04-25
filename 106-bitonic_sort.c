#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - recursive function to merge two bitonic sequences in
 * descending and ascending orders
 * @array: array of integers
 * @size: size of the array
 * @start: starting index of the sequence
 * @count: size of the sequence
 * @direction: direction of sorting, 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t count, int direction)
{
    size_t i, j, k, n;
    int tmp;

    if (count > 1)
    {
        size_t m = count / 2;

        printf("Merging [%lu, %lu] (%s):\n", start, start + count - 1, direction ? "UP" : "DOWN");
        print_array(array + start, count);

        for (i = start, j = start + m; j < start + count; i++, j++)
        {
            if ((array[i] > array[j]) == direction)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;

                printf("Swapped elements\n");
                print_array(array + start, count);
            }
        }

        bitonic_merge(array, size, start, m, direction);
        bitonic_merge(array, size, start + m, m, direction);
    }
}

/**
 * bitonic_sort_recursive - recursive function to sort a bitonic sequence
 * in ascending and descending orders
 * @array: array of integers
 * @size: size of the array
 * @start: starting index of the sequence
 * @count: size of the sequence
 * @direction: direction of sorting, 1 for ascending, 0 for descending
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t count, int direction)
{
    size_t m = count / 2;

    if (count > 1)
    {
        printf("Merging [%lu, %lu] (%s):\n", start, start + count - 1, direction ? "UP" : "DOWN");
        print_array(array + start, count);

        bitonic_sort_recursive(array, size, start, m, 1);
        bitonic_sort_recursive(array, size, start + m, m, 0);
        bitonic_merge(array, size, start, count, direction);
    }
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array && size > 1 && ((size & (size - 1)) == 0))
    {
        bitonic_sort_recursive(array, size, 0, size, 1);
    }
}
