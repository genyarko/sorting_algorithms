#include "sort.h"

/**
 * swap - swap the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * hoare_partition - partitions the array using the Hoare partition scheme
 * @array: array of integers to partition
 * @low: lower index of the partition to sort
 * @high: higher index of the partition to sort
 * @size: size of the array
 * Return: index of the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (true)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_helper - helper function for quick sort algorithm
 * @array: array of integers to sort
 * @low: lower index of the partition to sort
 * @high: higher index of the partition to sort
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = hoare_partition(array, low, high, size);
        quick_sort_helper(array, low, p, size);
        quick_sort_helper(array, p + 1, high, size);
    }
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}
