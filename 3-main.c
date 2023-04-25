#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void print_test(int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void test_quick_sort(int *array, size_t size)
{
    printf("Unsorted array: ");
    print_test(array, size);

    quick_sort(array, size);

    printf("Sorted array: ");
    print_test(array, size);
}

int main(void)
{
    int array1[] = {5, 3, 8, 2, 7, 1, 6, 4};
    size_t size1 = sizeof(array1) / sizeof(array1[0]);
    test_quick_sort(array1, size1);
    printf("\n");

    int array2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t size2 = sizeof(array2) / sizeof(array2[0]);
    test_quick_sort(array2, size2);
    printf("\n");

    int array3[] = {8, 7, 6, 5, 4, 3, 2, 1};
    size_t size3 = sizeof(array3) / sizeof(array3[0]);
    test_quick_sort(array3, size3);
    printf("\n");

    int array4[] = {1, 3, 5, 7, 2, 4, 6, 8};
    size_t size4 = sizeof(array4) / sizeof(array4[0]);
    test_quick_sort(array4, size4);
    printf("\n");

    int array5[100000];
    size_t i;
    srand(time(NULL));
    for (i = 0; i < 100000; i++)
        array5[i] = rand();
    test_quick_sort(array5, 100000);
    printf("\n");

    return (0);
}
