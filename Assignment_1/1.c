#include <stdio.h>

int main() {
    // Define an array of integers
    int array[] = {1, 2, 3, 4, 5};
    
    // Calculate the number of elements in the array
    int length = sizeof(array) / sizeof(array[0]);
    
    // Loop through the array and print each element
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    
    // Print a newline for better readability
    printf("\n");
    
    return 0;
}
