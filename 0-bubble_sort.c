void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            // print the array after each swap
            printf("Array after swapping elements: ");
            for (size_t k = 0; k < size; k++) {
                printf("%d ", array[k]);
            }
            printf("\n");
        }
    }
}
