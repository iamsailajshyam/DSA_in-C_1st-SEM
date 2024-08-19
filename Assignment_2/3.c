#include <stdio.h>

// Function to print array elements
void printArray(int *arr, int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to update array elements
void updateArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 5; // Add 5 to each element
    }
    // Print array within this function
    printf("Array elements in updateArray function:\n");
    printArray(arr, size);
}

int main() {
    int size;

    // Input size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Print original array
    printf("Original array elements:\n");
    printArray(array, size);

    // Update array
    updateArray(array, size);

    // Print array after update
    printf("Array elements after update:\n");
    printArray(array, size);

    return 0;
}
