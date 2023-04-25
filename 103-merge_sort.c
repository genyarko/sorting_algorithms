#include "sort.h"
/**
 * merge - Merges two sub-arrays into a single sorted array
 *
 * @array: Pointer to the array being sorted
 * @left: Pointer to the left sub-array
 * @right: Pointer to the right sub-array
 * @left_size: Size of the left sub-array
 * @right_size: Size of the right sub-array
 **/
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm
 *
 * @array: Pointer to the array being sorted
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
    if (size < 2)
    {
        return;
    }

    size_t mid = size / 2;

    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((size - mid) * sizeof(int));

    for (size_t i = 0; i < mid; i++)
    {
        left[i] = array[i];
    }

    for (size_t i = mid; i < size; i++)
    {
        right[i - mid] = array[i];
    }

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(array, left, right, mid, size - mid);

    free(left);
    free(right);
}
