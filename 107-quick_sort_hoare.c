#include "sort.h"

/**
 * quick_sort_hoare - sorts an array with the Quicksort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_recursion(array, 0, size - 1, size);
}

/**
 * quick_recursion - sorts an array with the Quicksort algorithm
 * @array: array of integers to sort
 * @left: the first index of the partition to sort
 * @right: the last index of the partition to sort
 * @size: size of the array
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
    int pivot;

    if (left < right)
    {
        pivot = partition(array, left, right, size);
        quick_recursion(array, left, pivot - 1, size);
        quick_recursion(array, pivot, right, size);
    }
}

/**
 * partition - partitions an array and selects a pivot
 * @array: array of integers to partition
 * @left: the first index of the partition to sort
 * @right: the last index of the partition to sort
 * @size: size of the array
 *
 * Return: the index of the partition
 */
int partition(int *array, int left, int right, size_t size)
{
    int pivot = array[right];
    int i = left - 1, j = right + 1, tmp;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);
        do {
            j--;
        } while (array[j] > pivot);
        if (i >= j)
            return (i);

        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        print_array(array, size);
    }
}
