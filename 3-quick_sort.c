#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * algorithm
 * @array: pointer to the first element of the array to sort
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    q_sort(array, 0, size - 1, size);
}

/**
 * q_sort - recursive function to sort an array using quick sort
 * @array: pointer to the first element of the array to sort
 * @low: the lowest index of the partition to sort
 * @high: the highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */

void q_sort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = partition(array, low, high, size);

        q_sort(array, low, pivot - 1, size);
        q_sort(array, pivot + 1, high, size);
    }
}

/**
 * partition - function to partition the array for quick sort
 * @array: pointer to the first element of the array to sort
 * @low: the lowest index of the partition to sort
 * @high: the highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */

int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high], i = low, j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }
    }
    if (i != high)
    {
        swap(&array[i], &array[high]);
        print_array(array, size);
    }

    return (i);
}

/**
 * swap - swaps two elements of an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 *
 * Return: void
 */

void swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}
