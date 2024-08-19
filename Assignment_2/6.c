#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main() {
    int *array;
    int n;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically for n integers
    array = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program with an error code
    }

    // Input the elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Display the elements
    printf("The elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
