#include <stdio.h>
#include <stdlib.h> // For calloc, realloc, and free

int main() {
    int *array;
    int initial_size, new_size;

    // Step 1: Allocate initial memory using calloc
    printf("Enter the initial number of elements: ");
    scanf("%d", &initial_size);

    // Allocate memory and initialize to zero
    array = (int *)calloc(initial_size, sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program with an error code
    }

    // Input elements for the initial array
    printf("Enter %d elements:\n", initial_size);
    for (int i = 0; i < initial_size; i++) {
        scanf("%d", &array[i]);
    }

    // Display the elements of the initial array
    printf("Initial array elements:\n");
    for (int i = 0; i < initial_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Step 2: Reallocate memory using realloc
    printf("Enter the new number of elements (greater than initial): ");
    scanf("%d", &new_size);

    // Reallocate memory to accommodate new_size elements
    array = (int *)realloc(array, new_size * sizeof(int));

    // Check if reallocation was successful
    if (array == NULL) {
        printf("Memory reallocation failed.\n");
        return 1; // Exit the program with an error code
    }

    // Input additional elements for the reallocated array
    printf("Enter %d additional elements:\n", new_size - initial_size);
    for (int i = initial_size; i < new_size; i++) {
        scanf("%d", &array[i]);
    }

    // Display the elements of the array after reallocation
    printf("Array elements after reallocation:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
