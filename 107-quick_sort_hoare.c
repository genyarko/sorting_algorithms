#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("\n");
}

int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;

        print_array(array, size);
    }
}

void quick_sort_helper(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = hoare_partition(array, low, high, size);
        quick_sort_helper(array, low, p, size);
        quick_sort_helper(array, p + 1, high, size);
    }
}

void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}
