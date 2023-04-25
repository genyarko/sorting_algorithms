#include "sort.h"

/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max_num;
    size_t i, significant_digit;

    if (!array || size < 2)
        return;

    max_num = array[0];
    for (i = 1; i < size; i++)
        if (array[i] > max_num)
            max_num = array[i];

    for (significant_digit = 1; max_num / significant_digit > 0; significant_digit *= 10)
        count_sort_LSD(array, size, significant_digit);

    print_array(array, size);
}

/**
 * count_sort_LSD - count sort with LSD
 * @array: array to sort
 * @size: size of the array
 * @significant_digit: least significant digit
 */
void count_sort_LSD(int *array, size_t size, size_t significant_digit)
{
    int count_arr[10] = {0};
    size_t i;
    int *output;

    output = malloc(size * sizeof(int));
    if (!output)
        return;

    for (i = 0; i < size; i++)
        count_arr[(array[i] / significant_digit) % 10]++;

    for (i = 1; i < 10; i++)
        count_arr[i] += count_arr[i - 1];

    for (i = size - 1; i < size; i--)
    {
        output[count_arr[(array[i] / significant_digit) % 10] - 1] = array[i];
        count_arr[(array[i] / significant_digit) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}
