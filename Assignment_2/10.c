#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Function to search for an element in the array
int searchElement(int *array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i; // Return the index where the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int *array;
    int size, element, index;

    // Step 1: Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Allocate memory dynamically for the array
    array = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program with an error code
    }

    // Step 2: Input elements into the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Step 3: Input the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    // Step 4: Search for the element
    index = searchElement(array, size, element);

    // Display the result
    if (index != -1) {
        printf("Element %d found at index %d.\n", element, index);
    } else {
        printf("Element %d not found in the array.\n", element);
    }

    // Step 5: Free the allocated memory
    free(array);

    return 0;
}
