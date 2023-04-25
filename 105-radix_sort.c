#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              LSD radix sort algorithm.
 *
 * @array: Pointer to the integer array to sort.
 * @size:  Size of the array to sort.
 */
void radix_sort(int *array, size_t size)
{
    int *tmp = NULL;
    int max = 0;
    size_t i, j, k;
    unsigned int digit = 1;

    if (array == NULL || size < 2)
        return;

    tmp = malloc(sizeof(int) * size);
    if (tmp == NULL)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    /* Sort the array by each digit, from least significant to most */
    while (max / digit > 0) {
        unsigned int count[10] = {0};

        /* Count the number of elements for each digit */
        for (i = 0; i < size; i++)
            count[(array[i] / digit) % 10]++;

        /* Compute the running sum of the counts */
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        /* Move the elements to their correct position in the output array */
        for (i = size - 1; i < SIZE_MAX; i--) {
            if (count[(array[i] / digit) % 10] > 0) {
                tmp[count[(array[i] / digit) % 10] - 1] = array[i];
                count[(array[i] / digit) % 10]--;
            }
            if (i == 0)
                break;
        }

        /* Copy the sorted array back to the input array */
        for (i = 0; i < size; i++)
            array[i] = tmp[i];

        /* Print the array after each iteration */
        print_array(array, size);

        digit *= 10;
    }

    free(tmp);
}
