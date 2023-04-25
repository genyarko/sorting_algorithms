#include "sort.h"
/**
 * merge - merge two subarrays of array
 *
 * @array: array to be sorted
 * @left: starting index of the left subarray
 * @middle: ending index of the left subarray and starting index of the right subarray
 * @right: ending index of the right subarray
 */
void merge(int *array, int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    /* create temporary subarrays */
    int *left_array = (int*) malloc(n1 * sizeof(int));
    int *right_array = (int*) malloc(n2 * sizeof(int));

    /* copy data to temporary subarrays */
    for (i = 0; i < n1; i++)
        left_array[i] = array[left + i];
    for (j = 0; j < n2; j++)
        right_array[j] = array[middle + 1 + j];

    /* merge the two subarrays back into array */
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    /* copy the remaining elements of left_array */
    while (i < n1)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }

    /* copy the remaining elements of right_array */
    while (j < n2)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }

    /* free temporary subarrays */
    free(left_array);
    free(right_array);
}

/**
 * merge_sort - sort an array of integers in ascending order using Merge Sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
    /* base case */
    if (size < 2)
        return;

    /* divide array into two subarrays */
    int middle = size / 2;
    merge_sort(array, middle);
    merge_sort(array + middle, size - middle);

    /* merge the two sorted subarrays */
    merge(array, 0, middle - 1, size - 1);
}
