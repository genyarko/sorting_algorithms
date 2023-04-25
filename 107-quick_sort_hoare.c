#include <stdio.h>
#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with the Hoare partition scheme
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_hoare_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_hoare_helper - Helper function for quick_sort_hoare
 *
 * @array: Pointer to the first element of the array
 * @lo: Starting index of the partition to be sorted
 * @hi: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 *
 * Return: void
 */
void quick_sort_hoare_helper(int *array, int lo, int hi, size_t size)
{
    int p;

    if (lo < hi)
    {
        p = partition_hoare(array, lo, hi, size);
        quick_sort_hoare_helper(array, lo, p, size);
        quick_sort_hoare_helper(array, p + 1, hi, size);
    }
}

/**
 * partition_hoare - Picks the last element of the partition as pivot,
 * rearranges the array in such a way that all elements smaller than
 * the pivot are to the left of it and all greater elements are to the
 * right of it. Returns the index of the pivot element.
 *
 * @array: Pointer to the first element of the array
 * @lo: Starting index of the partition to be sorted
 * @hi: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot element
 */
int partition_hoare(int *array, int lo, int hi, size_t size)
{
    int pivot = array[hi], tmp;
    int i = lo - 1, j = hi + 1;

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

        if (i != j)
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            print_array(array, size);
        }
    }
}
