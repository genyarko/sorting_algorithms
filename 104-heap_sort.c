#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: the array of integers to sort
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i, temp;

    /* Build heap */
    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size);

    /* Extract elements */
    for (i = size - 1; i > 0; i--)
    {
        /* Move current root to end */
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        /* Call max heapify on the reduced heap */
        sift_down(array, i, 0, size);
    }
}

/**
 * sift_down - helper function to maintain the heap property
 * @array: the array of integers to sort
 * @n: the size of the heap
 * @i: the index of the node to sift down
 * @size: the size of the array
 */
void sift_down(int *array, size_t n, size_t i, size_t size)
{
    int temp, max = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && array[left] > array[max])
        max = left;

    if (right < n && array[right] > array[max])
        max = right;

    if (max != i)
    {
        /* Swap elements */
        temp = array[i];
        array[i] = array[max];
        array[max] = temp;

        print_array(array, size);

        /* Recursively heapify the affected sub-tree */
        sift_down(array, n, max, size);
    }
}
