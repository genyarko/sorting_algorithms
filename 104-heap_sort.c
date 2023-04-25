#include "sort.h"

/**
 * sift_down - Perform heap sort sift down operation
 * @array: array to sort
 * @start: start position of the heap
 * @end: end position of the heap
 * @size: size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start, child, swap;

    while (2 * root + 1 <= end)
    {
        child = 2 * root + 1;
        swap = root;

        if (array[swap] < array[child])
            swap = child;

        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;

        if (swap != root)
        {
            swap_ints(&array[root], &array[swap]);
            print_array(array, size);
            root = swap;
        }
        else
            return;
    }
}

/**
 * heap_sort - sorts an array with the Heap Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t end;

    if (!array || size < 2)
        return;

    /* Build the heap in array */
    for (end = (size - 2) / 2; (int) end >= 0; end--)
        sift_down(array, end, size - 1, size);

    /* Extract the elements from heap in array */
    for (end = size - 1; end > 0; end--)
    {
        swap_ints(&array[end], &array[0]);
        print_array(array, size);
        sift_down(array, 0, end - 1, size);
    }
}
