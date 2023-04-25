#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the Shell
 *              sort algorithm
 *
 * @array: Pointer to the first element of the array to sort
 * @size:  Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int tmp;

    /* Find the largest gap in the Knuth sequence that's less than size */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        /* Sort each sub-array created by the gap */
        for (i = gap; i < size; i++)
        {
            tmp = array[i];
            for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = tmp;
        }
        gap = (gap - 1) / 3;

        /* Print the array after each time the gap decreases */
        print_array(array, size);
    }
}
